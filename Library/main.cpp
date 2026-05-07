#include "Book.h"
#include "Library.h"
#include <iostream>
#include <limits>
#include <vector>

int main() {
    Library library;
    Book book;
    
    library.addBook(book);
    std::cin.get();

    library.showAllBooks();
    
    std::cin.get();
}