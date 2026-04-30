#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <math.h>
#include <algorithm>

class DynamicArray {
private:
    int* data;     // pointer to the array
    int size;      // number of elements used
    int capacity;  // total allocated space

public:
    DynamicArray();
    ~DynamicArray();

    void push_back(int value);
    int get(int index);
    void set(int index, int value);
    int getSize();
};


int main() {

    DynamicArray Test;

}