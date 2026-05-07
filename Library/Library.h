#pragma once
#include "Book.h"
#include <string>
#include <iostream>
#include <vector>

class Library {

    private:
        std::vector<Book> books;

    public:
        void addBook(const Book& book) {
            int number;
            std::cout << "Welcome to the adding a book utility! " << std::endl;
            std::cout << "How many books would you like to add? " << std::endl;
            std::cin >> number;

            for (int i = 0; i < number; i++) {
                std::string title;
                std::string author;
                int year;
                
                std::cout << "Please enter the Title of the book: ";
                std::cin >> title;
                std::cout << std::endl;
                std::cin.get();

                std::cout << "Please enter the author: ";
                std::cin >> author;
                std::cout << std::endl;
                std::cin.get();

                std::cout << "Please enter the year of publishing: ";
                std::cin >> year;
                std::cout << std::endl;
                std::cin.get();

                books.push_back(Book(title,author,year,false));
                std::cin.get();
            }
        };

        
        
        void showAllBooks() const {
            for (std::size_t i = 0; i < books.size(); i++) {

                books[i].printBook();
            }
        };
        //void showAvailableBooks() const;
        //void borrowBook(const std::string& title);
        //void returnBook(const std::string& title);


};