#include <iostream>

int* findMax(int* arr, int size) {

    int currentMax = *arr;
    int* maxPtr = arr;

    for (int i = 0; i< size; i++) {

        if (*(arr+i) > currentMax) {
            maxPtr = (arr+i);
            currentMax = *(arr+i);
        }

    }

    return maxPtr;
}

int* findValue(int* arr, int size, int value) {

    int* valPtr;

    for (int i = 0; i < size; i++) {

        if (*(arr+i) == value) {
            valPtr = (arr+i);
            return valPtr;
        } 
    }

    return nullptr;
}


int main() {
    int numbers[] = {4,7,19,9,3};
    int size = 5;
    int search = 9;

    int* ptrMax = findMax(numbers,size);

    std::cout<<ptrMax<< " " << *ptrMax << std::endl;

    int* valPtr = findValue(numbers,size,search);

    if (valPtr) {
        std::cout << valPtr << " " << *valPtr << std::endl;
    }
    
    
    std::cin.get();
}