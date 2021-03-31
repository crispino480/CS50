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
- The webpage in this project is designed to gather and store comments or feedbacks; 
 </p>
 
 ## Tools used: 
 <p>
This simple  web application was created using Flask in the cs50 IDE available for cs50 student
</p>

**![Image of wepage](https://github.com/crispino480/forimages/blob/main/mywebpage.png)**
<p>
The files used here  are application.py, where the application and routes are created,
froshims.db is the database borrowed from a previous cs50 project
The html files used for this project in the templates folder are index.html,
layout.html; the Css file and image used for the background are located in the static folder.
</p>

<p>
This web application does not do any validation but rather, will make sure for any submission
all fields has been filled up.Once submitted, the form will send the provided information to the database;
</p>

<p>
Index.html extends layout.html in its form, then there is a use of the html "div" tag for divions in the layout
of this page, each divions include an input tag for information we are collecting from the users
  
![index.html](https://github.com/crispino480/forimages/blob/main/index.html.png)
</p>

<p>
layout.html is the page's head, it will be use as an extension to create pages to this webpage

![layout.html](https://github.com/crispino480/forimages/blob/main/layout.html.png)
</p>

<p>
froshims.db is the database created with 5 tables: id, usermane, email, telephone and comments
![database.db](https://github.com/crispino480/forimages/blob/main/database.png)
  
  ![database.db](https://github.com/crispino480/forimages/blob/main/database.png)
</p>

<p>
styles.css is the css stylesheet referenced in layout.html, which contents all the webpage styling
</p>

<p>
In application.py, there is a submit function; if a POST request is submitted via the form, we use the request.form.get
to capture the user input and validate that no empty entry has been submitted, for each entry

Once the validation has been passed, the input provided is load to the database via the variable load.

![application.py](https://github.com/crispino480/forimages/blob/main/application.py.png)
</p>
