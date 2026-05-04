#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Book.h"
#include "Sort.h"

using namespace std;

int main() {
    vector<Book> books;

    string filename;
    int fileChoice;

    cout << "Choose file:\n";
    cout << "1. Small file (books_small.txt)\n";
    cout << "2. Large file (books_large.txt)\n";
    cout << "Enter choice: ";
    cin >> fileChoice;

    if (fileChoice == 1) {
        filename = "books_small.txt";
    }
    else if (fileChoice == 2) {
        filename = "books_large.txt";
    }
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    ifstream file(filename);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;

    //Read file
    while (getline(file, line)) {
        try {
            stringstream ss(line);
            string title, author;

 
            getline(ss, title, ',');
            getline(ss, author);

            // removing quotation from title

            if (!title.empty() && title.front() == '"' && title.back() == '"') {
                title = title.substr(1, title.length() - 2);
            }

            // we will get first and last name

            string first, last;
            stringstream authorStream(author);
            authorStream >> first >> last;

          
            Book b(title, first, last);
            books.push_back(b);
        }
        catch (...) {
            cout << "Error reading line!" << endl;
        }
    }

    file.close();

    cout << "\nWelcome to the Library System!" << endl;

    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Sort books by title\n";
        cout << "2. Sort books by last name\n";
        cout << "3. Sort books by last name (reverse)\n";
        cout << "4. Sort by total characters\n";
        cout << "5. Exit the program\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 && !books.empty()) {
            quickSort(books, 0, books.size() - 1);
        }
        else if (choice == 2 && !books.empty()) {
            mergeSort(books, 0, books.size() - 1);
        }
        else if (choice == 3 && !books.empty()) {
            insertionSortReverse(books);
        }
        else if (choice == 4 && !books.empty()) {
            sortByTotalChars(books);
        }

        // Print result

        if (choice >= 1 && choice <= 4) {
            cout << "\nSorted Results:\n";
            for (size_t i = 0; i < books.size(); i++) {
                cout << "\"" << books[i].getTitle() << "\" - "
                    << books[i].getFirstName() << " "
                    << books[i].getLastName() << endl;
            }
        }

    } while (choice != 5);

    return 0;
}