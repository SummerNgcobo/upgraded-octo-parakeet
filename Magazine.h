#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"
#include <string>

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(const std::string& title, const std::string& author, int id, int issueNumber);
    
    // Getters and setters
    int getIssueNumber() const;
    void setIssueNumber(int issueNumber);

    // Overridden virtual functions
    void displayInfo() const override;
    std::string getType() const override;
};

#endif // MAGAZINE_H