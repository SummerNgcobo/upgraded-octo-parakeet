#include "LibraryManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>  // Required for std::make_unique

LibraryManager::LibraryManager() {
    loadData();
}

LibraryManager::~LibraryManager() {
    saveData();
}

void LibraryManager::addItem(std::unique_ptr<LibraryItem> item) {
    items.push_back(std::move(item));
}

void LibraryManager::displayAllItems() const {
    if (items.empty()) {
        std::cout << "No items in the library.\n";
        return;
    }
    
    std::cout << "\nLibrary Items:\n";
    for (const auto& item : items) {
        item->displayInfo();
        std::cout << "-----------------\n";
    }
}

LibraryItem* LibraryManager::findItemById(int id) const {
    for (const auto& item : items) {
        if (item->getId() == id) {
            return item.get();
        }
    }
    return nullptr;
}

std::vector<LibraryItem*> LibraryManager::findItemsByTitle(const std::string& title) const {
    std::vector<LibraryItem*> results;
    for (const auto& item : items) {
        if (item->getTitle().find(title) != std::string::npos) {
            results.push_back(item.get());
        }
    }
    return results;
}

std::vector<LibraryItem*> LibraryManager::findItemsByAuthor(const std::string& author) const {
    std::vector<LibraryItem*> results;
    for (const auto& item : items) {
        if (item->getAuthor().find(author) != std::string::npos) {
            results.push_back(item.get());
        }
    }
    return results;
}

bool LibraryManager::borrowItem(int id) {
    LibraryItem* item = findItemById(id);
    if (item) {
        return item->borrowItem();
    }
    return false;
}

bool LibraryManager::returnItem(int id) {
    LibraryItem* item = findItemById(id);
    if (item) {
        return item->returnItem();
    }
    return false;
}

void LibraryManager::loadData() {
    std::ifstream file(dataFile);
    if (!file.is_open()) return;

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string type, title, author, genre;
        int id, issueNumber;
        bool isBorrowed;

        getline(iss, type, '|');
        getline(iss, title, '|');
        getline(iss, author, '|');
        iss >> id;
        iss.ignore();
        iss >> isBorrowed;
        iss.ignore();

        if (type == "Book") {
            getline(iss, genre);
            addItem(std::make_unique<Book>(title, author, id, genre));
            items.back()->setIsBorrowed(isBorrowed);
        } else if (type == "Magazine") {
            iss >> issueNumber;
            addItem(std::make_unique<Magazine>(title, author, id, issueNumber));
            items.back()->setIsBorrowed(isBorrowed);
        }
    }
    file.close();
}

void LibraryManager::saveData() {
    std::ofstream file(dataFile);
    if (!file.is_open()) return;

    for (const auto& item : items) {
        file << item->getType() << "|" << item->getTitle() << "|" 
             << item->getAuthor() << "|" << item->getId() << "|" 
             << item->getIsBorrowed() << "|";
        
        if (item->getType() == "Book") {
            Book* book = dynamic_cast<Book*>(item.get());
            file << book->getGenre();
        } else if (item->getType() == "Magazine") {
            Magazine* magazine = dynamic_cast<Magazine*>(item.get());
            file << magazine->getIssueNumber();
        }
        
        file << "\n";
    }
    file.close();
}