import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd
app.jinja_env.globals.update(usd=usd, lookup=lookup, int=int)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Query  the user database transactions
    rows = db.execute("SELECT symbol, SUM(shares) as volumeShare FROM transactions WHERE user_id = :user_id GROUP BY symbol HAVING volumeShare",user_id=session["user_id"])

    # Get total cash remaining
    total_sum = 0
    total_hold = []
    for row in rows:
        stock = lookup(row["symbol"])
        total_hold.append({
            "symbol": stock["symbol"],
            "name": stock["name"],
            "shares": row["volumeShare"],
            "price": usd(stock["price"]),
            "total": usd(stock["price"]*row["volumeShare"])
        })
        total_sum += stock["price"] * row["volumeShare"]
    # remaining cash available and total
    cash_available = db.execute("SELECT cash FROM users WHERE id=:user_id", user_id=session["user_id"])[0]["cash"]
    total_sum += cash_available

    return render_template("index.html",total_hold = total_hold, cash_available=usd(cash_available), total_sum=usd(total_sum) )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure symbol and shares is submitted
        if not request.form.get("symbol") :
            return apology("must provide symbol", 400)

        elif not request.form.get("shares"):
            return apology("must provide shares", 400)

        if  int(request.form.get("shares")) < 1:
            return apology(" INVALID SELECTION,  AT LEAST ONE(1) SHARE REQUIRED")

        # Purchase value
        quote = lookup(request.form.get("symbol"))
        share = request.form.get("shares")

        if not quote:
            return apology(" invalid symbol")

        # Get the cost of that stock
        cost = int(share)*quote["price"]

        # Query the user cash balance
        balance = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        if cost > balance[0]["cash"]:
            return apology(" Not Enough cash, Update your Balance")

        # update New Balance in users table
        db.execute("UPDATE users SET cash=cash-:cost WHERE id=:id", cost=cost, id=session["user_id"]);
        # add transactions to transactions table
        new_transactions = db.execute("INSERT INTO transactions (user_id,symbol,shares, quote,username) VALUES (:user_id,:symbol, :shares, :quote,:username)",
        user_id=session["user_id"],symbol=quote["symbol"],shares=int(request.form.get("shares")),quote=quote['price'],
        username=db.execute("SELECT username FROM users WHERE id = :uid", uid=int(session['user_id']))[0]["username"])


        return redirect("/")


    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactionss"""

    # get the user's transactionss
    activity = db.execute("SELECT symbol, shares, quote, transacted FROM transactions WHERE user_id=:id", id=session["user_id"])

    if not activity:
        return apology("You have no activity to display")

    return render_template("history.html",stocks=activity)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():


    if request.method == "POST":

        # request stock information
        quote = lookup(request.form.get("symbol"))

        if not quote:
            return apology("MISSING SYMBOL")

        return render_template("quoted.html", quote = quote)

    """Get stock quote."""
    return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():

    if request.method == "POST":

    #Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        #Ensure password or password confirmation were submitted
        elif not request.form.get("password") or not request.form.get("confirmation"):
            return apology("must provide password", 403)

        # Ensure password and confirmation match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("Sorry, password do not match", 403)

        #Ensure user is unique
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        #add the user and the hash pasword to the database
        load = db.execute("INSERT INTO users (username,hash) VALUES(:username, :hash)",username=request.form.get("username"),hash=generate_password_hash(request.form.get("password")))

        # Ensure the username created is unique in the database
        if len(rows) >= 1:
            return apology("username already exist",403)

        # Log the user and remember which user has logged in
        #session["user_id"] = rows[0]["id"]
        session["user_id"] = load

        # Redirect user to home page
        return redirect("/")

        # user reached the route with GET
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Get the user symbol and shares inputs
        symbol =request.form.get("symbol")
        shares = request.form.get("shares")

        # Ensure symbol and shares is submitted
        if not symbol :
            return apology("must provide symbol", 400)

        elif not shares:
            return apology("must provide shares", 400)

        if  int(shares) < 1:
            return apology(" INVALID SELECTION,  AT LEAST ONE(1) SHARE REQUIRED")

        # look up the  quote and infos for this symbol (stock)
        quote = lookup(request.form.get("symbol"))


        if not quote:
            return apology(" invalid symbol")

        # Get availability for a given symbol on user purchases
        rows = db.execute("SELECT SUM(shares) as totalShares FROM transactions WHERE symbol=:symbol AND user_id=:user_id",
        symbol=quote["symbol"],user_id=session["user_id"])

        for row in rows:
            if int(shares) > row["totalShares"]:
                return apology("You do not have enough shares")

        # Get the cost of that stock
        cost = int(shares)*quote["price"]


        # update New Balance in users table
        db.execute("UPDATE users SET cash = cash +:cost WHERE id=:id", cost=cost, id=session["user_id"])

        # Update shares counts in database
        db.execute("UPDATE transactions SET shares=shares-:shares WHERE symbol=:symbol",shares=int(shares),symbol=quote["symbol"])

        return redirect("/")

    else:
        # list the user's belongings (stocks/symbol)
        portfolio = db.execute("SELECT symbol FROM transactions WHERE user_id=:user_id",user_id=session["user_id"])

        return render_template("sell.html",symbols=portfolio)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
