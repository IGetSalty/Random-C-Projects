#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <math.h>
#include <algorithm>

std::string file = "random_data.txt";
std::string merge = "output_mergesort.txt";
std::string heap = "output_heapsort.txt";
std::string quick = "output_quicksort.txt";
std::string randquick = "output_randomquicksort.txt";
std::string counting = "output_countingsort.txt";
std::string output = "output_data.txt";

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
//Randomized Quicksort
///////////////

int RandomPartition(std::vector<int>& A, int p, int r) {
    int i = (rand() % (r-p+1)) + p;
    std::swap(A[r],A[i]);
    return Partition(A, p, r);
}

void RandomQuickSort(std::vector<int>& A, int p, int r) {
    if (p<r) {
        int q =  RandomPartition(A,p,r);
        RandomQuickSort(A,p,q-1);
        RandomQuickSort(A,q+1,r);
    }
}


///////////////
//Bucket
///////////////

///////////////
//Counting
///////////////
std::vector<int> CountingSort(std::vector<int>& A, std::vector<int>& B) {
    int k = *std::max_element(A.begin(), A.end());
    std::vector<int> C(k + 1, 0);
    
    B.resize(A.size());

    for (int j = 0; j < A.size(); j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    for (int j = A.size() - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    return B;
}


///////////////
//Radix
///////////////


/////////////////////////////////////////////////////////////////////////
//Main
/////////////////////////////////////////////////////////////////////////

void algoRunner(int a, std::vector<int>& data) {
    
    
if (a == 1) {

    std::cout << "Insertion Sorting" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    InsertionSort(data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    writeResults(data, output);

    std::cout << "Time taken (Insertion Sort): "
              << duration.count() << " seconds\n";
}

else if (a == 2) {

    std::cout << "Merge Sorting" << std::endl;

    std::vector<int> b(data.size());

    auto start = std::chrono::high_resolution_clock::now();

    topDownMergeSort(data, b, data.size());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    writeResults(data, merge);

    std::cout << "Time taken (Merge Sort): "
              << duration.count() << " seconds\n";
}

else if (a == 3) {

    std::cout << "Heap Sorting" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    Heapsort(data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    writeResults(data, heap);

    std::cout << "Time taken (Heap Sort): "
              << duration.count() << " seconds\n";
}

else if (a == 4) {

    std::cout << "Quick Sorting" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    Quicksort(data, 0, size(data) - 1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    writeResults(data, quick);

    std::cout << "Time taken (Quick Sort): "
              << duration.count() << " seconds\n";
}

else if (a == 5) {

    std::cout << "Random Quick Sorting" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    RandomQuickSort(data, 0, size(data) - 1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    writeResults(data, randquick);

    std::cout << "Time taken (Random Quick Sort): "
              << duration.count() << " seconds\n";
}

else if (a == 6) {
    std::vector<int> B;
    std::cout << "Counting Sorting" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    B = CountingSort(data,B);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    writeResults(B, counting);

    std::cout << "Time taken (Counting Sort): "
              << duration.count() << " seconds\n";
}
}


int  main() {

    std::vector<int> mergedata,heapdata,
    quickdata,randomquickdata,countingdata;

    fillVector(mergedata,file);
    fillVector(heapdata,file);
    fillVector(quickdata,file);
    fillVector(randomquickdata,file);
    fillVector(countingdata,file);

    //MergeSort
    algoRunner(2,mergedata);
    std::cout<< std::endl;

    //HeapSort
    algoRunner(3,heapdata);
    std::cout<< std::endl;

    //QuickSort
    algoRunner(4,quickdata);
    std::cout<< std::endl;

    //RandomQuickSort
    algoRunner(5,randomquickdata);
    std::cout<< std::endl;
    
    //Counting
    algoRunner(6,countingdata);
    std::cout<< std::endl;
    
    std::cin.get();
    
    return 0;

}