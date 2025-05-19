#include "Magazine.h"
#include <iostream>

Magazine::Magazine(const std::string& title, const std::string& author, int id, int issueNumber)
    : LibraryItem(title, author, id), issueNumber(issueNumber) {}

int Magazine::getIssueNumber() const { return issueNumber; }
void Magazine::setIssueNumber(int issueNumber) { this->issueNumber = issueNumber; }

void Magazine::displayInfo() const {
    std::cout << "Type: Magazine\n";
    std::cout << "Title: " << getTitle() << "\n";
    std::cout << "Author: " << getAuthor() << "\n";
    std::cout << "ID: " << getId() << "\n";
    std::cout << "Issue Number: " << issueNumber << "\n";
    std::cout << "Status: " << (getIsBorrowed() ? "Borrowed" : "Available") << "\n";
}

std::string Magazine::getType() const { return "Magazine"; }