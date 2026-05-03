#include <iostream>

int* smallestValue(int* arr, int size) {

    int smallVal = *arr;
    int* smallPtr = arr;

    for (int i = 0; i < size; i++) {
        if (*(arr+i) < smallVal) {
            smallVal = *(arr+i);
            smallPtr = (arr+i);
        }
    }

    return smallPtr;
}

int* largestValue(int* arr, int size) {

    int largeValue = *arr;
    int* largePtr = arr;

    for (int i = 0; i < size; i++) {
        
        if (*(arr+i) > largeValue) {
            largeValue = *(arr+i);
            largePtr = (arr+i);
        }
    
    }

    return largePtr;

}

void swap(int* smallest, int* largest) {

    std::swap(*smallest,*largest);

}

void normalise(int* arr, int size, int smallest) {

int* ptr = arr;

    for (int i = 0; i < size; i++) {

        *(ptr+i) -= smallest;

    }

}

int* findSecondLargest(int* arr, int size) {

    //use find largest and store
    //loop through and compare twice

    int* largest = largestValue(arr,size);
    int largeValue = *largest;
    int* smallest = arr;

    for (int i = 0; i < size; i++) {
        if (*(arr+i) > *smallest && *(arr+i) < largeValue) {
            smallest = (arr+i);
        }
    } 

    return smallest;

}

///////////////////////////////////////////////////////

int main() {

    //Initialising Stuff
    int numbers[] = {8,3,15,1,9};
    int* point = numbers;
    int size = 5;

    //Find Minimum and Maximum 
    int* smallValue1 = smallestValue(numbers,size);
    int* largeValue1 = largestValue(numbers,size);
    int* secondLargest = findSecondLargest(numbers,size);
    std::cout << "Smallest Value " << *smallValue1 << " Largest Value " << *largeValue1 << " Second Largest " << *secondLargest << std::endl;


    //Print Normal Array
    std::cout << "Normal Array" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << *(point+i) << "  ";
    }
    std::cout << std::endl;

    //Swap Minimum and Maximum in Array
    swap(smallValue1,largeValue1);

    //Recalculating the Minimum and Maximum Values after doing swap
    int* smallValue = smallestValue(numbers,size);
    int* largeValue = largestValue(numbers,size);

    std::cout << "Swapped Array" << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << *(point+i) << "  ";
    }
    std::cout << std::endl;


    //Subtract Minimum from every value in array
    normalise(numbers,size,*smallValue);

    std::cout << "Normalized Array" << std::endl;
    //Print out resultant array
    for (int i = 0; i < size; i++) {
        std::cout << *(point+i) << "  ";
    }
    std::cout << std::endl;

    std::cin.get();
    
}