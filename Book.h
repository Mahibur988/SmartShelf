#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <algorithm>
using namespace std;

class Book {
private:
    string title;
    string firstName;
    string lastName;

    string titleLower;
    string lastNameLower;

public:
    Book() {}

    Book(string t, string f, string l) {
        title = t;
        firstName = f;
        lastName = l;

        titleLower = t;
        lastNameLower = l;

        transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);
        transform(lastNameLower.begin(), lastNameLower.end(), lastNameLower.begin(), ::tolower);
    }

    string getTitle() const { return title; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }

    string getTitleLower() const { return titleLower; }
    string getLastNameLower() const { return lastNameLower; }
};

#endif