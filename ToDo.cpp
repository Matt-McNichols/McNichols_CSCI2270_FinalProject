#include<iostream>
#include <algorithm>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include"ToDo.h"

using namespace std;


ToDo :: ToDo()
{
}

ToDo :: ~ToDo()
{
}

/*
  Function Prototype:
  void ToDo :: readIn()
  
  Function description:
  This method reads any todo list items that are saved in the
  ToDoList.txt file.  If there are items in the file, this method 
  re-enters the items into the todoList vector. This allows for the
  user to exit the program and start the program again without 
  losing their todo list items

  Example:
  ToDo T;
  T.readOut();

  Precondition:
  The ToDoList.txt file has only been written to by the program. 
  This method is called every time the user enters the program,
  if the user has an empty todo list the method will not do 
  anything.

  Post condition:
  The items that have been entered by the user while previously 
  running the program are entered into todoList vector. If no items
  have previously been entered, the vector remains empty.
 */
void ToDo :: readIn()
{
  ifstream inputFile;
  inputFile.open("ToDoList.txt"); //open file from the command line 
  if (inputFile.is_open())
    {
      string line;
      while(!inputFile.eof())
	{
	  //read in the date as a string
	  getline(inputFile,line,'\n');
	  if(inputFile.eof()){break;}
	  int eoDate=line.find('-');
	  string Fdate=line.substr(0,eoDate);

	  //read in the name as a string
	  int endOFname=line.find(":");
	  int nameLength=endOFname-(eoDate+2);
	  string Fname=line.substr((eoDate+2),nameLength);

	  //read in the priority as a string 
	  string Fpriority=line.substr(endOFname+1);

	  //call add item to add the file item into vector
	  addItem(Fname,atoi(Fpriority.c_str()),Fdate);
	  
	}
    }
}

/*
Function prototype:
void ToDo :: readOut()

Function description:
This method is called once the user has selected Quit from the 
menue.  The purpose of this method is to write all items from the 
todoList vector to the ToDoList.txt file.  

Example:
ToDo T;
T.readOut();

Precondition:
The Item vector is either empty or contains a objects of type item.
The user has entered valid inputs for the item components.

Post condition:
Each item from the todoList vector has been written to the 
ToDoList.txt file in the same odder they appear in the vector
 */
void ToDo :: readOut()
{
  ofstream fileOut;
  fileOut.open("ToDoList.txt");
  for(int i=0;i<todoList.size();i++)
    {
      fileOut<<todoList[i].monthDue<<"/"<<todoList[i].dayDue<<"/"<<todoList[i].yearDue<<"--"<<todoList[i].name<<":"<<todoList[i].priority<<endl;
    }
  fileOut.close();

}

/*
Function Prototype
void ToDo :: addItem(string name, int priority,string date)

Function Description:
This method adds an item to the todoList vector. The user is asked
to enter the items name, priority and due date. These values are 
passed to this method which breaks the date appart, creates a new 
item and pushes it into the todoList vector.

Example:
ToDo T;
T.addItem(example, 500, 04/25/2015)

Precondition:
The user must type valid inputs for name, priority and date. The 
date must be in the specified order and include the '/' in the 
correct locations.

Post condition:
The inputs given by the user are stored into a new item and the item
is pushed onto the todoList vector.
 */

void ToDo :: addItem(string name, int priority,string date)
{
      //break up the date string into seperate parts
      //month
      int monthLength=date.find('/');
      string month=date.substr(0,monthLength);
      
      //day
      int dayPosition=date.find('/',monthLength+1);
      int dayLength=dayPosition-monthLength;
      string day=date.substr(monthLength+1,dayLength-1);
      
      //year
      string year=date.substr(dayPosition+1);
      
      //add the item to vector
      item v;
      v.name=name;
      v.priority=priority;
      v.dayDue=atoi(day.c_str());
      v.monthDue=atoi(month.c_str());
      v.yearDue=atoi(year.c_str());
      todoList.push_back(v);
}

/*
Function Prototype:
void ToDo :: displayALL()

Funcion Description:
This method is used to display all items that are in the todoList 
vector. The method uses a vector iterator to scroll through all
each item in order and displays all the information about the item.

Example:
ToDo T;
T.displayAll();

Precondition:
This method assumes there are items in the vector. If there are no 
items in the vector, this method simply returns and does not output 
anything.

Post conditions:
This method will output the items in the vector in the order the 
items appear in the vector. It will output all the information for
each item. The output is of the same format as the output used when
writing to the ToDoList.txt file. 
 */

void ToDo :: displayALL()
{
  vector<item>::iterator myIntVectorIterator;
for(myIntVectorIterator = todoList.begin(); myIntVectorIterator != todoList.end();myIntVectorIterator++)
  {
    cout<<(*myIntVectorIterator).monthDue<<"/"<<(*myIntVectorIterator).dayDue<<"/"<<(*myIntVectorIterator).yearDue<<"--"<<(*myIntVectorIterator).name<<":"<<(*myIntVectorIterator).priority<<endl;   
  }
}
/*
Function Prototype:
void ToDo :: PrintPriority()

Function Description:
This method re-arranges the items in the todoList vector based on
priority. The method arranges from highest priority value to lowest.
The method then prints the items. This method only prints the item
priority value and name.

Example:
ToDo T;
T.PrintPriority();

Precondition:
This method assumes there are Items in the todoList vector. Also 
the method assumes the user entered a valid input for the priority
value of each item.

Post condition:
The todoList vector order has been changed. The highest priority 
item is first in the vector and lowest is last. The method prints 
the items in the new order.
 */
void ToDo :: PrintPriority()
{
  int i,j;
 
  for(i= (todoList.size()-1); i>0; --i)
    {
      for(j=0; j<i; j++)
	{
	  if(todoList[j].priority<todoList[j+1].priority)
	    {
	      item temp=todoList[j];
	      todoList[j]=todoList[j+1];
	      todoList[j+1]=temp;
	    }
	}
    }
 
vector<item>::iterator myIntVectorIterator;
for(myIntVectorIterator = todoList.begin(); myIntVectorIterator != todoList.end();myIntVectorIterator++)
  {
    cout<<(*myIntVectorIterator).priority<<":"<<(*myIntVectorIterator).name<<endl;   
    
  }
}
/*
Function Prototype:
void ToDo :: PrintDate()

Function Description:
This method re-arranges the items in the todoList vector based on
date. The method arranges items from the earliest date to the latest
The method then prints the items. This method only prints the item
date value and name.

Example:
ToDo T;
T.PrintDate();

Precondition:
This method assumes there are Items in the todoList vector. Also 
the method assumes the user entered a valid input for the date
value of each item.  There is a prototype date value printed when 
the program asks the user to enter the date.

Post condition:
The todoList vector order has been changed. The earliest due
date item is now first in the vector while the latest due date
item is last. The method prints the items in the new order.
 */
void ToDo :: PrintDate()
{
  int i,j;
  //sort by year
for(i=(todoList.size()-1); i>0; --i)
    {
      for(j=0; j<i; j++)
	{
	  if(todoList[j].yearDue>todoList[j+1].yearDue)
	    {
	      item temp=todoList[j];
	      todoList[j]=todoList[j+1];
	      todoList[j+1]=temp;
	    }
	}
    }

  //sort by month
  for(i=(todoList.size()-1); i>0; --i)
    {
      for(j=0; j<i; j++)
	{
	  if((todoList[j].yearDue==todoList[j+1].yearDue)&&(todoList[j].monthDue>todoList[j+1].monthDue))
	    {
	      item temp=todoList[j];
	      todoList[j]=todoList[j+1];
	      todoList[j+1]=temp;
	    }
	}
    }

  //sort by date within each month
  for(i= (todoList.size()-1); i>0; --i)
   {
      for(j=0; j<i; j++)
	{
	  if((todoList[j].monthDue==todoList[j+1].monthDue)&&(todoList[j].dayDue>todoList[j+1].dayDue))
	    {
	      item temp=todoList[j];
	      todoList[j]=todoList[j+1];
	      todoList[j+1]=temp;
	    }
	}
    }

vector<item>::iterator myIntVectorIterator;
for(myIntVectorIterator = todoList.begin(); myIntVectorIterator != todoList.end();myIntVectorIterator++)
  {
    cout<<(*myIntVectorIterator).monthDue<<"/"<<(*myIntVectorIterator).dayDue<<"/"<<(*myIntVectorIterator).yearDue<<"--"<<(*myIntVectorIterator).name<<endl;   
    
  }
}
/*
Function Prototype:
void ToDo :: taskComplete(string task)

Function description:
This method allows the user to remove an item from the todoList 
vector.  The user is asked to enter the item name which is passed to
this method as a string. The method then finds the item with the 
same name and deletes the item.

Example:
ToDo T;
T.taskComplete("homework") 

Precondition:
The method searches the vector and if the string matches an item
name the item is erased from the vector. If the string does not
match any item names the the function tells the user the item was
not found and returns.
 
Post condition:
If an item is found,the vector is re-sized and all other items are 
shifted appropriately.
 */
void ToDo :: taskComplete(string task)
{
  bool found=false;
  for(int i=0; i<todoList.size(); i++)
    {
      if(todoList[i].name==task)
	{
	  
	  todoList.erase(todoList.begin()+i);
	  found=true;
	  break;
	}
    }
  if(found==false)cout<<"completed item not found"<<endl;
  return;
}
/*
Function prototype:
void ToDo :: PrintDueToday()

Function description:
This method uses ctime library to compare the due date of each item
in the vector with the current date. If an item has a due date 
that matches the current date the method prints the item.

Example:
ToDo T;
T.PrintDueToday();

Precondition:
This method assumes the vector is not empty and that items contain
valid inputs. 

Postcodition:
The function prints the items that are due today but makes no change
the the todoList vector
 */
void ToDo :: PrintDueToday()
{
 time_t t = time(0);   // get time now
 struct tm * now = localtime( & t );
 
 vector<item>::iterator myIntVectorIterator;
for(myIntVectorIterator = todoList.begin(); myIntVectorIterator != todoList.end();myIntVectorIterator++)
  {
    if(now->tm_mday==(*myIntVectorIterator).dayDue && (now->tm_mon+1)==(*myIntVectorIterator).monthDue && (now->tm_year+1900)==(*myIntVectorIterator).yearDue)
      {
	cout<<(*myIntVectorIterator).monthDue<<"/"<<(*myIntVectorIterator).dayDue<<"/"<<(*myIntVectorIterator).yearDue<<"--"<<(*myIntVectorIterator).name<<":"<<(*myIntVectorIterator).priority<<endl;   
      }
  }

}
/*
Function prototype:
void ToDo :: PrintDueToday()

Function description:
This method uses ctime library to compare the due date of each item
in the vector with the current date. If an item has a due date 
whos month matches the current month the method prints the item.

Example:
ToDo T;
T.PrintDueMonth();

Precondition:
This method assumes the vector is not empty and that items contain
valid inputs. 

Postcodition:
The function prints the items that are due this month but makes no
change the the todoList vector.
 */
void ToDo :: PrintDueMonth()
{
  time_t t = time(0);   // get time now
  struct tm * now = localtime( & t );
  
  vector<item>::iterator myIntVectorIterator;
  for(myIntVectorIterator = todoList.begin(); myIntVectorIterator != todoList.end();myIntVectorIterator++)
    {
      if((now->tm_mon+1)==(*myIntVectorIterator).monthDue && (1900+now->tm_year)==(*myIntVectorIterator).yearDue)
	{
	  cout<<(*myIntVectorIterator).monthDue<<"/"<<(*myIntVectorIterator).dayDue<<"/"<<(*myIntVectorIterator).yearDue<<"--"<<(*myIntVectorIterator).name<<":"<<(*myIntVectorIterator).priority<<endl;   
	}
    }

}
/*
Function Prototype:
void ToDo :: clearAll()

Function description:
This method allows the user to clear everything out of todoList 
vector. 

Example:
ToDo T;
T.clearAll();

Precondition:
This Function assumes there are items in the vector although if the
vector is empty, calling this method will not change the vector.

Post condition:
The vector is completely empty. All items have been freed. If the 
user ends the program after this method, the ToDoList.txt file will
be empty.
*/

void ToDo :: clearAll()
{
  todoList.clear();
}

