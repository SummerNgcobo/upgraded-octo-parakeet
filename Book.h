#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <string>

class Book : public LibraryItem {
private:
    std::string genre;

public:
    Book(const std::string& title, const std::string& author, int id, const std::string& genre);
    
    // Getters and setters
    std::string getGenre() const;
    void setGenre(const std::string& genre);

    // Overridden virtual functions
    void displayInfo() const override;
    std::string getType() const override;
};

#endif // BOOK_H