#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>

class LibraryManager {
private:
    std::vector<std::unique_ptr<LibraryItem>> items;
    const std::string dataFile = "library_data.txt";

    void loadData();
    void saveData();

public:
    LibraryManager();
    ~LibraryManager();

    void addItem(std::unique_ptr<LibraryItem> item);
    void displayAllItems() const;
    LibraryItem* findItemById(int id) const;
    std::vector<LibraryItem*> findItemsByTitle(const std::string& title) const;
    std::vector<LibraryItem*> findItemsByAuthor(const std::string& author) const;
    bool borrowItem(int id);
    bool returnItem(int id);
};

#endif // LIBRARYMANAGER_H