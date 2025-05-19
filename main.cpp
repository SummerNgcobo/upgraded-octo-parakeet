#include <iostream>
#include <memory>
#include <limits>
#include "LibraryManager.h"
#include "Book.h"
#include "Magazine.h"


void displayMenu() {
    std::cout << "\nLibrary Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Add Magazine\n";
    std::cout << "3. Display All Items\n";
    std::cout << "4. Search by Title\n";
    std::cout << "5. Search by Author\n";
    std::cout << "6. Borrow Item\n";
    std::cout << "7. Return Item\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

void addBook(LibraryManager& manager) {
    std::string title, author, genre;
    int id;
    
    std::cout << "\nEnter Book Details:\n";
    std::cout << "Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Genre: ";
    std::cin.ignore();
    std::getline(std::cin, genre);
    
    manager.addItem(std::make_unique<Book>(title, author, id, genre));
    std::cout << "Book added successfully!\n";
}

void addMagazine(LibraryManager& manager) {
    std::string title, author;
    int id, issueNumber;
    
    std::cout << "\nEnter Magazine Details:\n";
    std::cout << "Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Issue Number: ";
    std::cin >> issueNumber;
    
    manager.addItem(std::make_unique<Magazine>(title, author, id, issueNumber));
    std::cout << "Magazine added successfully!\n";
}

void searchByTitle(LibraryManager& manager) {
    std::string title;
    std::cout << "Enter title to search: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    
    auto results = manager.findItemsByTitle(title);
    if (results.empty()) {
        std::cout << "No items found with title: " << title << "\n";
    } else {
        std::cout << "\nSearch Results:\n";
        for (const auto& item : results) {
            item->displayInfo();
            std::cout << "-----------------\n";
        }
    }
}

void searchByAuthor(LibraryManager& manager) {
    std::string author;
    std::cout << "Enter author to search: ";
    std::cin.ignore();
    std::getline(std::cin, author);
    
    auto results = manager.findItemsByAuthor(author);
    if (results.empty()) {
        std::cout << "No items found by author: " << author << "\n";
    } else {
        std::cout << "\nSearch Results:\n";
        for (const auto& item : results) {
            item->displayInfo();
            std::cout << "-----------------\n";
        }
    }
}

void borrowItem(LibraryManager& manager) {
    int id;
    std::cout << "Enter ID of item to borrow: ";
    std::cin >> id;
    
    if (manager.borrowItem(id)) {
        std::cout << "Item borrowed successfully!\n";
    } else {
        std::cout << "Failed to borrow item. It may not exist or already be borrowed.\n";
    }
}

void returnItem(LibraryManager& manager) {
    int id;
    std::cout << "Enter ID of item to return: ";
    std::cin >> id;
    
    if (manager.returnItem(id)) {
        std::cout << "Item returned successfully!\n";
    } else {
        std::cout << "Failed to return item. It may not exist or not be borrowed.\n";
    }
}

int main() {
    LibraryManager manager;
    int choice;
    
    do {
        displayMenu();
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                addBook(manager);
                break;
            case 2:
                addMagazine(manager);
                break;
            case 3:
                manager.displayAllItems();
                break;
            case 4:
                searchByTitle(manager);
                break;
            case 5:
                searchByAuthor(manager);
                break;
            case 6:
                borrowItem(manager);
                break;
            case 7:
                returnItem(manager);
                break;
            case 8:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
    
    return 0;
}