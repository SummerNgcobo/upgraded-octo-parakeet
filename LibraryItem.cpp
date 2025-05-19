#include "LibraryItem.h"
#include <iostream>

LibraryItem::LibraryItem(const std::string& title, const std::string& author, int id)
    : title(title), author(author), id(id), isBorrowed(false) {}

// Getters
std::string LibraryItem::getTitle() const { return title; }
std::string LibraryItem::getAuthor() const { return author; }
int LibraryItem::getId() const { return id; }
bool LibraryItem::getIsBorrowed() const { return isBorrowed; }

// Setters
void LibraryItem::setTitle(const std::string& title) { this->title = title; }
void LibraryItem::setAuthor(const std::string& author) { this->author = author; }
void LibraryItem::setId(int id) { this->id = id; }
void LibraryItem::setIsBorrowed(bool borrowed) { isBorrowed = borrowed; }

bool LibraryItem::borrowItem() {
    if (!isBorrowed) {
        isBorrowed = true;
        return true;
    }
    return false;
}

bool LibraryItem::returnItem() {
    if (isBorrowed) {
        isBorrowed = false;
        return true;
    }
    return false;
}