#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

void box()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,10);
	cout<<"          ================================================================================================"<<endl;
	cout<<"          |                                                                                               |"<<endl;
	cout<<"          |                                                                                               |"<<endl;
	cout<<"          |                                                                                               |"<<endl;
	cout<<"          |                                    Zohad's Library                                            |"<<endl;
	cout<<"          |                                                                                               |"<<endl;
	cout<<"          |                                                                                               |"<<endl;
	cout<<"          |                                                                                               |"<<endl;
	cout<<"          ================================================================================================"<<endl;
	SetConsoleTextAttribute(h,7);
}

struct book {
    string title;
    string author;
    string genre;
    int year;
};

void details(book books[]) {
    for (int i = 1; i < 7; ++i) {
    	cout<<i<<") Details:"<<endl;
    	cout<<endl;
        cout << "Enter book title: ";
        cin >> books[i].title;
        cout << "Enter author: ";
        cin >> books[i].author;
        cout << "Enter genre: ";
        cin >> books[i].genre;
        cout << "Enter publication year: ";
        cin >> books[i].year;
        cout << endl;
    }
}

void category(book books[], book fiction[], book nonfiction[]) {
    int fictionCount = 0;
    int nonfictionCount = 0;

    for (int i = 0; i < 7; ++i) {
        if (books[i].genre == "fiction") {
            fiction[fictionCount++] = books[i];
        } else if (books[i].genre == "nonfiction") {
            nonfiction[nonfictionCount++] = books[i];
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
    
}

int main() {
	
	box();
    book books[7];
    details(books);

    book fiction[7];
    book nonfiction[7];

    category(books, fiction, nonfiction);

    int fictionCount = 7;
    int nonfictionCount = 7;

    book earliestFiction = findEarliestBook(fiction, fictionCount);

    book earliestNonfiction = findEarliestBook(nonfiction, nonfictionCount);
    
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,4);
    displayBooks(fiction, fictionCount, "Fiction");
    cout << "Earliest Fiction Book: " << earliestFiction.title << " (" << earliestFiction.year << ")\n\n";

	
	SetConsoleTextAttribute(h,1);
    displayBooks(nonfiction, nonfictionCount, "Nonfiction");
    cout << "Earliest Nonfiction Book: " << earliestNonfiction.title << " (" << earliestNonfiction.year << ")\n";
    
    
    	
	SetConsoleTextAttribute(h,7);


    return 0;
}
