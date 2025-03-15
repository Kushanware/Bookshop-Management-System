#include<iostream>
#include<fstream>
using namespace std;

class Bookshop {
public:
    void menu();
    void addBook();
    void showBooks();
    void checkBook();
    void updateBook();
    void deleteBook();
};

void Bookshop::menu() {
    cout << "\n\nBookshop Management System";
    cout << "\n1. Add Book";
    cout << "\n2. Show Books";
    cout << "\n3. Check Book";
    cout << "\n4. Update Book";
    cout << "\n5. Delete Book";
    cout << "\n6. Exit";
}

void Bookshop::addBook() {
    fstream file;
    string id, name, author;
    int year;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Year: ";
    cin >> year;

    file.open("books.txt", ios::app);
    file << id << " " << name << " " << author << " " << year << endl;
    file.close();
    cout << "Book added successfully!";
}

void Bookshop::showBooks() {
    fstream file;
    string id, name, author;
    int year;

    file.open("books.txt", ios::in);
    if (!file) {
        cout << "\nNo books found!";
    } else {
        cout << "\nBook List:";
        while (file >> id >> name >> author >> year) {
            cout << "\nID: " << id << " Name: " << name << " Author: " << author << " Year: " << year;
        }
    }
    file.close();
}

void Bookshop::checkBook() {
    fstream file;
    string id, name, author, searchID;
    int year, found = 0;

    cout << "\nEnter Book ID to search: ";
    cin >> searchID;
    file.open("books.txt", ios::in);

    while (file >> id >> name >> author >> year) {
        if (id == searchID) {
            cout << "\nID: " << id << " Name: " << name << " Author: " << author << " Year: " << year;
            found = 1;
            break;
        }
    }
    if (!found) cout << "\nBook not found!";
    file.close();
}

void Bookshop::updateBook() {
    fstream file, temp;
    string id, name, author, searchID;
    int year, found = 0;

    cout << "\nEnter Book ID to update: ";
    cin >> searchID;
    file.open("books.txt", ios::in);
    temp.open("temp.txt", ios::out);

    while (file >> id >> name >> author >> year) {
        if (id == searchID) {
            cout << "\nEnter new details";
            cout << "\nName: ";
            cin.ignore();
            getline(cin, name);
            cout << "Author: ";
            getline(cin, author);
            cout << "Year: ";
            cin >> year;
            found = 1;
        }
        temp << id << " " << name << " " << author << " " << year << endl;
    }
    file.close();
    temp.close();
    remove("books.txt");
    rename("temp.txt", "books.txt");
    if (!found) cout << "\nBook not found!";
    else cout << "\nBook updated!";
}

void Bookshop::deleteBook() {
    fstream file, temp;
    string id, name, author, searchID;
    int year, found = 0;

    cout << "\nEnter Book ID to delete: ";
    cin >> searchID;
    file.open("books.txt", ios::in);
    temp.open("temp.txt", ios::out);

    while (file >> id >> name >> author >> year) {
        if (id == searchID) {
            found = 1;
            continue;
        }
        temp << id << " " << name << " " << author << " " << year << endl;
    }
    file.close();
    temp.close();
    remove("books.txt");
    rename("temp.txt", "books.txt");
    if (!found) cout << "\nBook not found!";
    else cout << "\nBook deleted!";
}

int main() {
    Bookshop b;
    int choice;
    while (true) {
        b.menu();
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: b.addBook(); break;
            case 2: b.showBooks(); break;
            case 3: b.checkBook(); break;
            case 4: b.updateBook(); break;
            case 5: b.deleteBook(); break;
            case 6: return 0;
            default: cout << "\nInvalid choice!";
        }
    }
}
