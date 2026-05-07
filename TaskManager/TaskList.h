#pragma once
#include "Task.h"

class TaskList {

    private:
        Task* tasks;
        int size, capacity;

        //Whole purpose of this function is to take the old Array/TaskList, create a new one with double the capacity and then copy 
        //the old one into the new one. After, we delete the old one.
        void resize() {
            capacity *= 2; //Doubling capacity
            Task* newArr = new Task[capacity];

            for (int i = 0; i < size; i++) {
                newArr[i] = tasks[i];
            }

            delete[] tasks;
            tasks = newArr;

        }


    public:

        //Here we are initialising the Task List with an initial capacity of 2.
        TaskList() {
            capacity = 2;
            size = 0;
            tasks = new Task[capacity];

        }

        ~TaskList() {
            delete[] tasks;
        }

        void AddTask(const Task& t) {
            if (size == capacity) resize();
            tasks[size++] = t;
        }

        void CompleteTask(int a) {
            tasks[a-1].completed=true;
        }

        void PrintAll() {
            for (int i = 0; i < size; i++) {
                tasks[i].print();
            }
        }
    };

