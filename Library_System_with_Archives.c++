#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void addBook(vector<Book> &library) {
    Book book;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter author: ";
    getline(cin, book.author);
    cout << "Enter year: ";
    cin >> book.year;

    library.push_back(book);
    cout << "Book added successfully!\n";
}

void saveToFile(const vector<Book> &library, const string &filename) {
    ofstream file(filename);
    for (const auto &book : library) {
        file << book.title << "," << book.author << "," << book.year << endl;
    }
    file.close();
    cout << "Library saved to " << filename << endl;
}

void displayBooks(const vector<Book> &library) {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }
    for (const auto &book : library) {
        cout << "Title: " << book.title << ", Author: " << book.author
             << ", Year: " << book.year << endl;
    }
}

int main() {
    vector<Book> library;
    string filename = "library.txt";
    int choice;

    do {
        cout << "\n1. Add Book\n2. Display Books\n3. Save to File\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                saveToFile(library, filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
