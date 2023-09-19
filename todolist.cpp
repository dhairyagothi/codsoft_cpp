#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;


#include <iostream>
using namespace std;

const int maxTasks = 10; // Define the maximum number of tasks

class task_input
{
private:
    string tasks[maxTasks];
    string status[maxTasks];
    int num = 0;

public:
    void task()
    {
        cout << "\n Choose one of the following actions you want to perform: " << endl;
        cout << " 1. ADD A TASK TO YOUR TO-DO LIST " << endl;
        cout << " 2. VIEW TASK LIST " << endl;
        cout << " 3. UPDATE TASK STATUS " << endl;
        cout << " 4. REMOVE TASK FROM LIST " << endl;
        cout << " 5. SHOW TASK STATUS " << endl;
        cout << " 6. EXIT TODO LIST " << endl;
    }

    void addtask(const string& description)
    {
        if (num < maxTasks)
        {
            tasks[num] = description;
            status[num] = "incomplete";
            num++;
            cout << " Task added successfully " << endl;
        }
        else
        {
            cout << "Task list is full." << endl;
        }
    }

    void viewtask()
    {
        cout << "Here is your task list : "<<endl ;
        for (int i = 0; i < num; i++)
        {
            cout << (i + 1) << "." << tasks[i] << " status: " << status[i] << endl;
        }
    }

    void updatetaskstatus(int tasknum, const string& updatestatus)
    {
        if (tasknum >= 1 && tasknum <= num)
        {
            status[tasknum - 1] = updatestatus;
            cout << "Task status updated successfully." << endl;
        }
        else
        {
            cout << "Invalid task number. Please enter a correct task number." << endl;
        }
    }

    void taskliststatus()
    {
        cout << "Here is your task list status : "<<endl ;
        for (int i = 0; i < num; i++)
        {
            cout << "TASK " << (i + 1) << ". status: " << status[i] << endl;
        }
    }

    void removetask(int tasknum)
    {
        if (tasknum >= 1 && tasknum <= num)
        {
            for (int i = tasknum - 1; i < num - 1; i++)
            {
                tasks[i] = tasks[i + 1];
                status[i] = status[i + 1];
            }
            num--;
            cout << "Task removed successfully." << endl;
        }
        else
        {
            cout << "Invalid task number." << endl;
        }
    }
};

int main()
{
    cout << "_____________________TO DO LIST____________________" << endl;

    task_input list1; // Moved outside the loop to keep the task list

    while (true)
    {
        list1.task();
        int choice;
        string description;
        int tasknum;
        string updatestatus;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        cin.ignore(); // Added to consume the newline character

        if (choice == 1)
        {
            cout << "Please enter your task: "<<endl;
            getline(cin, description);
            list1.addtask(description);
        }
        else if (choice == 2)
        {
            list1.viewtask();
        }
        else if (choice == 3)
        {
            cout << "Enter task number whose status you want to update: ";
            cin >> tasknum;
            cin.ignore();
            cout << "Update task status (completed, incomplete, in progress): ";
            getline(cin, updatestatus);
            list1.updatetaskstatus(tasknum, updatestatus);
        }
        else if (choice == 4)
        {
            cout << "Enter Task no. to remove from the list: ";
            cin >> tasknum;
            list1.removetask(tasknum);
        }
        else if (choice == 5)
        {
            list1.taskliststatus();
        }
        else if (choice == 6)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Please enter a valid input from the list." << endl;
        }
    }

    return 0;
}
