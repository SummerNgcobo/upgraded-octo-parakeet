#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, int id, const std::string& genre)
    : LibraryItem(title, author, id), genre(genre) {}

std::string Book::getGenre() const { return genre; }
void Book::setGenre(const std::string& genre) { this->genre = genre; }

void Book::displayInfo() const {
    std::cout << "Type: Book\n";
    std::cout << "Title: " << getTitle() << "\n";
    std::cout << "Author: " << getAuthor() << "\n";
    std::cout << "ID: " << getId() << "\n";
    std::cout << "Genre: " << genre << "\n";
    std::cout << "Status: " << (getIsBorrowed() ? "Borrowed" : "Available") << "\n";
}

std::string Book::getType() const { return "Book"; }