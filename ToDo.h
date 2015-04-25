#ifndef TODO_H
#define TODO_H
#include<vector>
#include<iostream>

struct item{
  std::string name;
  int priority;
  int dayDue;
  int monthDue;
  int yearDue;
};

class ToDo
{
    public:
        ToDo();
        ~ToDo();
	
	void readIn();
	void readOut();
        void addItem(std::string name, int priority, std::string date);
        void displayALL();
	void PrintPriority();
	void PrintDate();
	void taskComplete(std::string task);
	void PrintDueToday();
	void PrintDueMonth();
	void clearAll();

    protected:
    private:
	std::vector<item> todoList;
	
};

#endif // GRAPH_H
