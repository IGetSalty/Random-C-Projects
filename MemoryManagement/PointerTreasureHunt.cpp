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

    for (int i = 0; i < size; i++) {
        *(arr+i) -= smallest;
    }
}



int main() {
    int numbers[] = {8,3,15,1,9};
    int* point = numbers;
    int size = 5;

    int* smallValue = smallestValue(numbers,size);

    std::cout << smallValue << " " << *smallValue << std::endl;

    int* largeValue = largestValue(numbers,size);

    std::cout << largeValue << " " << *largeValue << std::endl;

    swap(smallValue,largeValue);

    normalise(numbers,size,*smallValue);

    for (int i = 0; i < size; i++) {
        std::cout << (point+i) << "   " << *(point+i) << "  ";
    }
    std::cout << std::endl;

    std::cin.get();
    

}