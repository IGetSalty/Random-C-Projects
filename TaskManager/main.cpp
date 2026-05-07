#include "Task.h"
#include "TaskList.h"
//#include "TaskManager.h"
#include <iostream>
#include <limits>

int main() {

    //TaskList* a = NULL; //Null pointer for dynamically allocated array for TaskList
    TaskList List;
    int n = 0, id; //Initial size/capacity of TaskList
    std::string desc;


    std::cout << "Welcome to Task manager, how many tasks would you like to add today? " << std::endl;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    for (int i = 0; i < n; i++) {
        std::cout << "What task description would you like to give this one? ";
        std::getline(std::cin, desc);

        id = i+1;

        List.AddTask(Task(id, desc));
    }

    std::cin.get();

    List.PrintAll();

    std::cout << "Please enter the id of the task you'd like to mark as completed? ";
    int c; 
    std::cin >> c;
    List.CompleteTask(c);

    List.PrintAll();

    std::cin.get();
    std::cout << std::endl;
    std::cout << "end of program" << std::endl;
    std::cin.get();

    return 0;
    

}