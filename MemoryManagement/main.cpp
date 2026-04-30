#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <math.h>
#include <algorithm>

//Normal
int addNumbers1(int a, int b) {

    int *x = &a,*y = &b;
    int c = a+b;
    int *z = &c;

    std::cout << x << " " << a << " " << y << " " << b << " " << z << " " << c << std::endl;

    return c;
}

//By Reference
int addNumbers2(int& a, int& b) {

    int *x = &a,*y = &b;
    int c = a+b;
    int *z = &c;

    std::cout << x << " " << a << " " << y << " " << b << " " << z << " " << c << std::endl;

    return c;
}

//By Pointers
int addNumbers3(int *a, int *b) {

    int c = *a+*b;
    int *z = &c;

    std::cout << a << " " << *a << " " << b << " " << *b << " " << z << " " << c << std::endl;

    return c;
}



int main() {
    int n = 10;
    int *p = &n;

    int m = 13;
    int *q = &m;

    int d = addNumbers3(q,p);
    int *e = &d;

    std::cout << n << " " << p << std::endl;
    std::cout << m << " " << q << std::endl;
    std::cout << d << " " << e << std::endl;
    std::cin.get();    
    
}