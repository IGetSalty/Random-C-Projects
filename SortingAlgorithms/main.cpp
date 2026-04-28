#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <math.h>

/////////////////////////////////////////////////////////////////////////
//Utilities
/////////////////////////////////////////////////////////////////////////

std::vector<int> fillVector(std::vector<int> &v, std::string filename) {
    std::ifstream fin(filename);
    int c;

    while (fin >> c) {
        v.push_back(c);
    }

    fin.close();

    return v; 
}


void writeResults(std::vector<int> &v, std::string &outputName) {

    std::ofstream fout(outputName);
    int c;
    
    if (fout.is_open()) {
        for (const int& num : v) {
            fout << num << std::endl;
        }

        fout.close();
        std::cout << "Data has been Written to File" << std::endl;
    }
    else {
        std::cout << "Unable to open file for writing" << std::endl;
    }

    
}

/////////////////////////////////////////////////////////////////////////
//Sorting Algorithms
//Insertion merge bucket quick heap counting radix
/////////////////////////////////////////////////////////////////////////

///////////////
//Insertion
///////////////
std::vector<int> InsertionSort(std::vector<int> &v) {

    for (int j=1; j<v.size();j++) {
        
        int key = v[j];
        int i = j-1;

        while (i>=0 && v[i]>key) {
            v[i+1] = v[i];
            i--;
        
        }
        v[i+1] = key;
    }
    
    return v;
}

///////////////
//Merge
///////////////
void copyArray(std::vector<int>& a, int begin, int end, std::vector<int>& b) {
    for (int k = begin; k < end; ++k) {
        b[k] = a[k];
    }
}

void topDownMerge(std::vector<int>& a, int begin, int middle, int end, std::vector<int>& b) {
    int i = begin, j = middle;

    for (int k = begin; k < end; ++k) {
        if (i < middle && (j >= end || a[i] <= a[j])) {
            b[k] = a[i]; //left
            i++;
        }
        else {
            b[k] = a[j]; //right
            j++;
        }
    }
}

void topDownSplitMerge(std::vector<int>& a, int begin, int end, std::vector<int>& b) {
    if (end-begin<=1) return;

    int middle = (begin+end)/2;

    //recursive splitting
    topDownSplitMerge(b,begin,middle,a);
    topDownSplitMerge(b,middle,end,a);

    //merge sorted halves
    topDownMerge(b,begin,middle,end,a);
}

void topDownMergeSort(std::vector<int>& a, std::vector<int>& b, int n) {
    copyArray(a,0,n,b);
    topDownSplitMerge(a,0,n,b);
}

///////////////
//Heap
///////////////

void Heapify(std::vector<int>& A, int i, int heapSize) {

    while (true) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heapSize && A[left] > A[largest])
        largest = left;
    if (right < heapSize && A[right] > A[largest])
        largest = right;

    if (largest == i) break;

    std::swap(A[i], A[largest]);
    i = largest;
}
}

void BuildMaxHeap(std::vector<int>& A) {
    int heapSize = A.size();

    for (int i = heapSize/2-1; i >= 0; i-- ) {
        Heapify(A,i,heapSize);
    }
}

void Heapsort(std::vector<int>& A) {
    BuildMaxHeap(A);
    int heapSize = A.size();

    for (int i = A.size()-1; i>=1;i--) {

        std::swap(A[0],A[i]);
        heapSize = heapSize - 1;
        Heapify(A,0,heapSize);

    }
}



///////////////
//Quick
///////////////


int Partition(std::vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p-1;
    int j = p;

    for (j; j <= r-1; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i],A[j]);
        }
    }

    std::swap(A[i+1],A[r]);
    
    return i+1;

}

void Quicksort(std::vector<int>& A, int p, int r) {
    if (p<r) {
        int q = Partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}

///////////////
//Bucket
///////////////

///////////////
//Counting
///////////////

///////////////
//Radix
///////////////


/////////////////////////////////////////////////////////////////////////
//Main
/////////////////////////////////////////////////////////////////////////

void algoRunner(int a, std::vector<int>& data,std::string inputfile) {
    
    
    auto start = std::chrono::high_resolution_clock::now();
    
    if (a==1) {                                 
        InsertionSort(data);
    } else if (a==2) {                         
        std::vector<int> b(data.size());
        topDownMergeSort(data,b,data.size());
    } else if (a==3) {
        Heapsort(data);
    } else if (a==4) {
        Quicksort(data,0,size(data)-1);
    }
    
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = (end - start);

    std::cout << "Insertion sort time: " << duration.count() << std::endl;
}

int  main() {

    std::vector<int> data;
    int a = 3; //1 = Insertion Sort 2 = Merge Sort 3 = Heap Sort
    
    std::string file = "random_data.txt";
    std::string output = "output_data_merge.txt";

    fillVector(data,file);
    algoRunner(a,data,file);
    writeResults(data,output);
    
    std::cin.get();
    
    
    return 0;

}