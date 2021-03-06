# CS50 Final-Project : " submit your comment "
#### Video Demo:  <https://youtu.be/d6Wip_Qynww>
#### Description:
<p>
  
  ## Overview
MY Webpage can be add to a production page to collect feedback form users,
The information provided by the end user  will then be stored into a database
</p>

## purpose
<p>
 -The webpage in this project is designed to gather and store comments or feedbacks; it can be shared with 
 clients to gather input from them
 </p>
 
 ## Tools and Languages used: 

 - This project is developed in ****CS50 IDE**** An integrated development environment, as a software application that provides 
 comprehensive facilities to computer programmers for software development.
 - **Flask** (Flux Advanced Security Kernel) is a micro web framework written in Python.
 - **Python** is an interpreted, high-level and general-purpose programming language.
 - **Html (HyperText Markup Language)** is the standard markup language for documents designed to be displayed in a web browser.
 - **sqlite** is a relational database management system contained in a C library; it allows a single database connection 
 to access multiple database files simultaneously.
  - **CSS(Cascading Style Sheets)** is a style sheet language used for describing the presentation of a document written 
  in a markup language.

 ## Website view
**![Image of wepage](https://github.com/crispino480/forimages/blob/main/mywebpage.png)**

## Files:
<p>
The files used here  are application.py, where the application and routes are created,
froshims.db is the database borrowed from a previous cs50 project
The html files used for this project in the templates folder are index.html,
layout.html; the Css file and image used for the background are located in the static folder.
</p>

### Users input
<p>
This web application does not do any validation but rather, will make sure for any submission
all fields has been filled up. Once submitted, the form will send the provided information to the database;
</p>

### Index.html
<p>
Index.html extends layout.html in its form, then there is a use of the html "div" tag for divions in the layout
of this page, each divions include an input tag for information we are collecting from the users
  
![index.html](https://github.com/crispino480/forimages/blob/main/index.html.png)
</p>

### layout.html
<p>
layout.html is the page's head, it will be use as an extension to create pages to this webpage

![layout.html](https://github.com/crispino480/forimages/blob/main/layout.html.png)
</p>

### Froshims.db ( Database)
<p>
froshims.db is the database created with 5 tables: id, usermane, email, telephone and comments
![database.db](https://github.com/crispino480/forimages/blob/main/database.png)
  
  ![database.db](https://github.com/crispino480/forimages/blob/main/database.png)
</p>

### Style.css
<p>
styles.css is the css stylesheet referenced in layout.html, which contents all the webpage styling
</p>

### Application.py
<p>
In application.py, there is a submit function; if a POST request is submitted via the form, we use the request.form.get
to capture the user input and validate that no empty entry has been submitted, for each entry

Once the validation has been passed, the input provided is load to the database via the variable load.

![application.py](https://github.com/crispino480/forimages/blob/main/application.py.png)
</p>
