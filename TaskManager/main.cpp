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

    std::cin.get();
    std::cout << "This is a test message" << std::endl;
    std::cin.get();

    return 0;
    

}