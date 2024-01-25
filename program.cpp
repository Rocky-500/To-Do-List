#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Task class to represent a to-do item
class Task{
private:
    string description;
    bool completed;

public:
    Task(const string& desc){   //: description(desc), completed(false)
        description = desc;
        completed = false;
    }
    //function to get the task description
    string getDescription() const{
        return description;
    }

    //function to check if the task is completed
    bool isCompleted() const{
        return completed;
    }

    //function to mark the task as completed
    void markAsCompleted(){
        completed = true;
    }
};

void addTask(vector<Task>& todoList, const string& description){
    todoList.push_back(Task(description));
    cout<<"Task added successfully!"<<endl;
}

void displayTasks(const vector<Task>& todoList){
    cout<<"\nTo-Do List:"<<endl;
    for (size_t i = 0; i < todoList.size(); ++i){
        cout<<"\t    ["<<(i + 1)<<"] ";
        if (todoList[i].isCompleted())
            cout<<"[X] ";
        else
            cout<<"[ ] ";
        cout<<todoList[i].getDescription()<<endl;
    }
}

void markTaskAsCompleted(vector<Task>& todoList, size_t index){
    if (index > 0 && index <= todoList.size()){
        todoList[index - 1].markAsCompleted();
        cout<<"Task marked as completed!"<<endl;
    } else{
        cout<<"Invalid task index!"<<endl;
    }
}

void removeTask(vector<Task>& todoList, size_t index){
    if (index > 0 && index <= todoList.size()){
        todoList.erase(todoList.begin() + index - 1);
        cout<<"Task removed successfully!"<<endl;
    } else{
        cout<<"Invalid task index!"<<endl;
    }
}

int main(){
    vector<Task> todoList;

    while (true){
        cout<<"\n\n\n\t\t><><><><><><><><><><><><><><><><>< To-Do List Manager ><><>><><><><><><><><><><<><><><><"<<endl;
        cout<<"1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout<<"Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice){
            case 1:{
                cout<<"Enter task description: ";
                string description;
                cin.ignore(); //Ignore the newline character left in the buffer
                getline(cin, description);
                addTask(todoList, description);
                break;
            }
            case 2:
                displayTasks(todoList);
                break;
            case 3:{
                cout<<"Enter the index of the task to mark as completed: ";
                size_t index;
                cin >> index;
                markTaskAsCompleted(todoList, index);
                break;
            }
            case 4:{
                cout<<"Enter the index of the task to remove: ";
                size_t index;
                cin >> index;
                removeTask(todoList, index);
                break;
            }
            case 5:
                cout<<"Exiting program. Goodbye!\n";
                return 0;
            default:
                cout<<"Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
