#include "Book.h"
#include "Library.h"
#include <iostream>
#include <limits>
#include <vector>

int main() {
    Library library;
    Book book;
    int choice;

    while (choice != 6) {
        std::cout << std::endl;
        std::cout << "[1] Add Books" << std::endl;
        std::cout << "[2] Show All Books" << std::endl;
        std::cout << "[3] Show All Available Books" << std::endl;
        std::cout << "[4] Borrow a Book" << std::endl;
        std::cout << "[5] Return a Book" << std::endl;
        std::cout << "[6] Exit Application" << std::endl;
        std::cout << std::endl;
        std::cout << "Choice? ";
        std::cin >> choice;
        

        if (choice == 1) {
            std::cout << std::endl;
            library.addBook(book);
            //std::cin.get();
            library.showAllBooks();
        }
        else if (choice == 2) {
            std::cout << std::endl;
            library.showAllBooks();
        }
        else if (choice == 3) {
            std::cout << std::endl;
            library.showAvailableBooks();
        }
        else if (choice == 4) {
            std::cout << std::endl;
            library.borrowBook();
        }
        else if (choice == 5) {
            std::cout << std::endl;
            library.returnBook();
        }
    }
    
    
    std::cout << "Press ENTER to Exit the application";
    std::cin.get();
}