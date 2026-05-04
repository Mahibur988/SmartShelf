#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>
#include "Book.h"
using namespace std;

// QUICK SORT FOR (TITLE)

int partition(vector<Book>& books, int low, int high) {
    string pivot = books[high].getTitleLower();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (books[j].getTitleLower() < pivot) {
            i++;
            swap(books[i], books[j]);
        }
    }

    swap(books[i + 1], books[high]);
    return i + 1;
}

void quickSort(vector<Book>& books, int low, int high) {
    if (low < high) {
        int pi = partition(books, low, high);
        quickSort(books, low, pi - 1);
        quickSort(books, pi + 1, high);
    }
}

// MERGE SORT FOR (LAST NAME)

void merge(vector<Book>& books, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Book> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = books[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = books[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].getLastNameLower() < R[j].getLastNameLower()) {
            books[k] = L[i];
            i++;
        }
        else {
            books[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        books[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        books[k] = R[j];
        j++; k++;
    }
}

void mergeSort(vector<Book>& books, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(books, left, mid);
        mergeSort(books, mid + 1, right);
        merge(books, left, mid, right);
    }
}

// INSERTION SORT FOR (REVERSE LAST NAME)

void insertionSortReverse(vector<Book>& books) {
    for (int i = 1; i < books.size(); i++) {
        Book key = books[i];
        int j = i - 1;

        while (j >= 0 && books[j].getLastNameLower() < key.getLastNameLower()) {
            books[j + 1] = books[j];
            j--;
        }

        books[j + 1] = key;
    }
}

// EXTRA CREDIT

int totalChars(const Book& b) {
    return b.getTitle().length() +
        b.getFirstName().length() +
        b.getLastName().length();
}

void sortByTotalChars(vector<Book>& books) {
    int n = books.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (totalChars(books[j]) < totalChars(books[minIndex])) {
                minIndex = j;
            }
        }

        swap(books[i], books[minIndex]);
    }
}

#endif