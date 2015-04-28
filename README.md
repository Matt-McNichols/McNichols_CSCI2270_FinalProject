McNichols_CSCI2270_FinalProject
Repository for final project
==============================

Project Summary
------------------------------

For my final project I plan on making a task manager.  This will be a program 
that allows the user to organize their lives by creating a to do list.  The 
program will save all the items in the list and give options for how the list 
can be displayed. 

I plan on creating a struct called Item which contains a string for the item 
title, a due date for the item, a bool value for if the item has been completed,
and also an integer value for the priority level of item. 

I also plan on creating a class called TaskManager which will allow the user to
add items to their task manager as well as delete items or change an items 
completed value.  Also there will be multiple print functions which organize the
items either alphabetically, by due date, or by priority. these print functions
will only print items that have not been completed. There will also be an option
to print all the items in the task manager along with an indicator showing which
items have been completed and which have not. 

How to Run
----------------------------
Download the 3 files (ToDo.cpp ToDo.h main.cpp) compile and run.  
To add an item to your list select 1<enter>
   first enter the name of the todo list item<enter>
   next enter an integer priority value do not include spaces<enter>
   last enter a due date. Follow the date format specified (MM/DD/YYYY)
   	include the '/' in the date then<enter>

To print all items in your todo list select 2<enter>.	
   Items will be printed in the format they are written to in the ToDoList.txt
   file.

To print all items by priority select 3<enter>
   Items will be re-ordered based on priority level and then printed. Only the
   item priority and name will be printed.

To print all items by date select 4<enter>
   Items will be re-ordered based on priority level and then printed. Only the
   item priority and name will be printed.

To print what is due today select 5<enter>
   Items will not be re-ordered but if an items date is the same as the current
   date then the item will be printed in the same format as the print all 
   option.

To print what is due this month select 6<enter>
   Items will not be re-ordered but if an item has the same due date month and 
   year then the items will be printed.

To remove an item from the todo list select 7<enter>
   The user will be prompted to enter the name of the item. It is important the
   user enters the exact name as the item in the list. If the user enters an 
   item in the list, there will be no output and the item will be removed from
   the list. If the user enters a name that does not exist in the list, the 
   program will print an error message and redisplay the menue.

To remove all items from the list select 8<enter>
   All items will be removed from the list. The todoList vector will be empty.
   
To quit the program select 9<enter>
   All items in the todoList vector will be written to the ToDoList.txt file. 
   The user will exit the program.


Dependencies
----------------------------
To determine the current date, I used #include<ctime> library which is a library
in std.

System Requirements
----------------------------
This program will be intended for use on linux devices.

Group Members
---------------------------
Matt McNichols

Contributors
----------------------------
Matt Arendall
Dylan Van de Kerkhove

Open Issues/Bugs
----------------------------
When a user does not enter any name for an item, the code does not break but it
creates an empty item within the list. If I had more time I would have made an 
empty input notify the user of their mistake and restart them at the enter name
prompt.

