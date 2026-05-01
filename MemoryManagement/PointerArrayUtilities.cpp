#include <iostream>


void printArray(int* arr,int size) {
    //This will take the array arr and print out each value
    for (int i=0;i<5;i++) {
        std::cout << *(arr+i) << " ";
    }
    std::cout<<std::endl;
}


void addToall(int* arr, int size, int value) {
    //This will take a rando number and add it to each element of arr
    for (int i = 0;i<size;i++) {
        *(arr+i) = *(arr+i) + value;
    }

}


int sumArray(int* arr, int size) {
    //This will sum every element of arr together
    int total = 0;
    for (int i = 0; i<size;i++) {
        total+= *(arr+i);
    }
    
    return total;
}

void printPointers(int* arr, int size) {
    int* ptr = arr;

    for (int i = 0;i<size;i++) {
        std::cout << ptr << " ";
        ptr++;
    }
    std::cout<<std::endl;
}



int main() {
    int numbers[] = {1,2,3,4,5};
    int size = 5;

    int (*arraypointer)[5] = &numbers; //why the ()?
    printArray(numbers,size);

    addToall(numbers,size,7);
    printArray(numbers,size);

    int total = sumArray(numbers,size);
    std::cout<<total<<std::endl;

    printPointers(numbers,size);

    std::cin.get();

    int value = 7;

}