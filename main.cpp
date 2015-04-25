#include <algorithm>
#include<iostream>
#include<vector>
#include<string>
#include"ToDo.h"
#include<fstream>

using namespace std;

 void displayMenu()
  {
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Add Item"<<endl;
    cout<<"2. Print All Items"<<endl;
    cout<<"3. Print By priority"<<endl;
    cout<<"4. Print By Date"<<endl;
    cout<<"5. Print What is Due Today"<<endl;
    cout<<"6. Print What is Due This Month"<<endl;
    cout<<"7. Task Completed"<<endl;
    cout<<"8. Clear All"<<endl;
    cout<<"9. Quit"<<endl;
    return;
  }

int main()
{
  int input;
  // Flag used for exiting menu
  bool quit = false;
  ToDo T;
  //input existing items from todoList.txt back into T 
  T.readIn();
  
  //input file will not be found the first time through 
  //as soon as the user exits the program all info will be written to
  //a newly created file  
  while(quit != true)
    {
      displayMenu();
      cin >> input;
      
      //clear out cin
      cin.clear();
      cin.ignore(10000,'\n');
      //T.getTime();
      switch (input)
        {
	  // add item
	case 1:
	  {
	    string name;
	    string Spriority;
	    string date;
	    int priority=0;
	    cout << "Enter Item Name:" << endl;
	    getline(cin,name);
	    cout << "Enter Priority:" << endl;
	    getline(cin,Spriority);
	    priority=atoi(Spriority.c_str());
	    cout << "Enter Due Date(MM/DD/YYYY):" << endl;
	    getline(cin,date);
	    T.addItem(name,priority,date);
	  }
	  break;
	  // print all
	case 2:
	  {
	    T.displayALL();
	  }
	  break;

	  // print by priority
	case 3:
	  {
	    T.PrintPriority();
	  }
	  break;

	  // print by date
	case 4:
	  {
	    T.PrintDate();
	  }
	  break;

	  //print what is due today
	case 5:
	  {
	    T.PrintDueToday();
	  }
	  break;

	  //print what is due this month
	case 6:
	  {
	    T.PrintDueMonth();
	  }
	  break;
	  //task complete
	case 7:
	  {
	    string name;
	    cout << "Enter Item Name:" << endl;
	    getline(cin,name);
	    T.taskComplete(name);
	  }
	  break;

	  //clearAll
	case 8:
	  {
	    T.clearAll();
	  }
	  break;

	  //Quit
	case 9:
	  {
	    cout << "Goodbye!" << endl;
	    quit = true;
	    T.readOut();
	  }
	  break;

	  // invalid input
	default:
	  cout << "Invalid Input" << endl;
	  cin.clear();
	  cin.ignore(10000,'\n');
	  break;
        }
      //cout<<"hello"<<endl;
    }
    //cout<<"return"<<endl;
    return 0;
}
