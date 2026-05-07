#pragma once
#include <string>
#include <iostream>

class Book {
    private:
        std::string Title;
        std::string Author;
        int Year;
        bool isBorrowed;
    
    public:
        Book() : Title(""), Author(""),Year(2000),isBorrowed(false) {}

        Book(std::string title,std::string author, int year, bool isborrowed)
            : Title(title), Author(author), Year(year),isBorrowed(isborrowed) {}

        void printBook() const {
            std::cout << Title << " " << Author << " " << Year << (isBorrowed ? "[Y] " : " [N] " );
        }

};