# Written in Flask using Python,SQL, Javascripts
# This WebPage application to keep track of friends’ birthdays.
# When the / route is requested via GET, this web application displays, in a table, all of the people in your database along with their birthdays.
# When the / route is requested via POST, this web application  add a new birthday to your database and then re-render the index page.
import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        db.execute("INSERT INTO birthdays (name, month,day) VALUES(?, ?,?)", name, month,day)
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html",birthdays=birthdays)


