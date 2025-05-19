#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>

class LibraryItem {
protected:
    std::string title;
    std::string author;
    int id;
    bool isBorrowed;

public:
    LibraryItem(const std::string& title, const std::string& author, int id);
    virtual ~LibraryItem() = default;

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getId() const;
    bool getIsBorrowed() const;

    // Setters
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setId(int id);
    void setIsBorrowed(bool borrowed);

    // Virtual function to be overridden by derived classes
    virtual void displayInfo() const = 0;
    virtual std::string getType() const = 0;

    // Borrow and return functions
    bool borrowItem();
    bool returnItem();
};

#endif // LIBRARYITEM_H