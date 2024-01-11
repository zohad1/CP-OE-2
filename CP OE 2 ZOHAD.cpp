#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

void box() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
    cout << "          ================================================================================================" << endl;
    cout << "          |                                                                                               |" << endl;
    cout << "          |                                                                                               |" << endl;
    cout << "          |                                                                                               |" << endl;
    cout << "          |                                    Zohad's Library                                            |" << endl;
    cout << "          |                                                                                               |" << endl;
    cout << "          |                                                                                               |" << endl;
    cout << "          |                                                                                               |" << endl;
    cout << "          ================================================================================================" << endl;
    SetConsoleTextAttribute(h, 7);
}

struct book {
    string title;
    string author;
    string genre;
    int year;  // Changed from string to int
};

void details(book books[]) {
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ") Details:" << endl;
        cout << endl;
        cout << "Enter book title: ";
        cin.ignore(); // Add this line to clear the input buffer
        getline(cin, books[i].title);
        cout << "Enter author: ";
        getline(cin, books[i].author);
        cout << "Enter genre: ";
        getline(cin, books[i].genre);
        cout << "Enter publication year: ";
        cin >> books[i].year;
        cout << endl;
    }
}

void category(book books[], book fiction[], book nonfiction[]) {
    int fictionCount = 0;
    int nonfictionCount = 0;

    for (int i = 0; i < 6; ++i) {
        if (books[i].genre == "fiction" || books[i].genre == "FICTION" || books[i].genre == "Fiction") {
            fiction[fictionCount++] = books[i];
        } else if (books[i].genre == "nonfiction" || books[i].genre == "non fiction" || books[i].genre == "non-fiction") {
            nonfiction[nonfictionCount++] = books[i];
        } else {
            cout << "Please enter fiction or nonfiction" << endl;
            i--;  // Decrement i to allow the user to enter details for the same book again
        }
    }
}

book findEarliestBook(book books[], int count) {
    book earliest = books[0];
    for (int i = 1; i < count; ++i) {
        if (books[i].year < earliest.year) {
            earliest = books[i];
        }
    }
    return earliest;
}

void displayBooks(book books[], int count, const string& category) {
    cout << "Books in " << category << " category:\n";
    
    for (int i = 0; i < 3; ++i) {
        cout << "\n  Title: " << books[i].title << "\n  Author: " << books[i].author << "\n  Year: " << books[i].year << endl;
    }
    cout << endl;
}

void displayCategoryWithEarliest(book books[], int count, const string& category) {
    displayBooks(books, count, category);
    book earliestBook = findEarliestBook(books, count);
    cout << "Earliest " << category << " Book: " << earliestBook.title << " (" << earliestBook.year << ")\n\n";
}

int main() {

    box();
    book books[6];
    details(books);

    book fiction[6];
    book nonfiction[6];

    category(books, fiction, nonfiction);

    int fictionCount = 3;
    int nonfictionCount = 3;
    
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
    cout << "Fictional Books:\n";
    displayCategoryWithEarliest(fiction, fictionCount, "Fiction");
    
    SetConsoleTextAttribute(h, 1);
    cout << "Nonfictional Books:\n";
    displayCategoryWithEarliest(nonfiction, nonfictionCount, "Nonfiction");
    
    
    SetConsoleTextAttribute(h, 7);

    return 0;
}
