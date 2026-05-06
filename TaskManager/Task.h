#pragma once
#include <string>
#include <iostream>

class Task {

    public:
        int id;
        std::string description;
        bool completed;

    //Default constructor
    Task() : id(0), description(""), completed(false) {}
    
    //Usual Constructor first line gives arguments and second gives which argument goes to which Class attribute. completed is example of default
    Task(int id, const std::string& desc) :
        id(id), description(desc), completed(false) {}

    void print() const {
        std::cout << "[" << id << "] " << (completed ? "[X] " : " [ ] " ) << description << std::endl;
    };
};