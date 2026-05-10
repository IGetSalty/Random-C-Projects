#pragma once
#include "Book.h"
#include <string>
#include <iostream>
#include <limits>
#include <vector>

class Library {

    private:
        std::vector<Book> books;

    public:
        void addBook(const Book& book) {
            int number;
            std::cout << "Welcome to the adding a book utility! " << std::endl;
            std::cout << "-------------------------------------------------" << std::endl;
            std::cout << std::endl;

            std::cout << "How many books would you like to add? ";
            std::cin >> number;
            std::cout << std::endl;

            for (int i = 0; i < number; i++) {
                std::string title;
                std::string author;
                int year;

                std::cin.get();
                
                std::cout << "Please enter the Title of book " << i+1 << ": ";
                std::getline(std::cin,title);
                //std::cin.get();
                std::cout << std::endl;
                
                std::cout << "Please enter the author: ";
                std::getline(std::cin,author);
                //std::cin.get();
                std::cout << std::endl;

                std::cout << "Please enter the year of publishing: ";
                std::cin >> year;
                
                //std::cout << std::endl;
                std::cout << "-------------------------------------------------" << std::endl;
                std::cin.get();
                books.push_back(Book(title,author,year,false));
                //std::cin.get();
                
            }
        };

        
        
        void showAllBooks() const {
            for (std::size_t i = 0; i < books.size(); i++) {

                books[i].printBook();
            }
            std::cout << std::endl;
        };


        void showAvailableBooks() const {
            for (std::size_t i = 0; i < books.size(); i++) {

                if (books[i].getisBorrowed() == false) {

                    books[i].printBook();
                }
            
            }
            std::cout << std::endl;
        };
        
        void borrowBook() {
            std::string tit;
            showAvailableBooks();
            std::cin.get();
            std::cout << "Which book would you like to borrow (enter Title): ";
            std::getline(std::cin,tit);
            std::cin.get();
            for (std::size_t i = 0; i < books.size(); i++) {
                if (books[i].getTitle() == tit) {

                    if (books[i].getisBorrowed() == true) {
                        std::cout << "Book is already borrowed, try another one!" << std::endl;
                    }
                    else {
                        books[i].BorrowBook(books[i]);
                    }
                }
            }
            std::cin.get();
            showAvailableBooks();
            
        };
        
        void returnBook() {
            std::string tit;
            showAllBooks();
            std::cin.get();
            std::cout << "Which book would you like to return (enter Title): ";
            std::getline(std::cin,tit);


            for (std::size_t i = 0; i < books.size(); i++) {
                if (books[i].getTitle() == tit) {

                    if (books[i].getisBorrowed() == false) {
                        std::cout << "Book hasn't been borrowed yet, would you like to borrow it?" << std::endl;
                    }
                    else {
                        books[i].ReturnBook(books[i]);
                    }
                }
            }
            std::cin.get();
            showAvailableBooks();
        };


};