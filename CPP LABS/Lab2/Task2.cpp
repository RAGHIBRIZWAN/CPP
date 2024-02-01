#include <iostream>
using namespace std;

struct library {
    string title;
    string author;
    int year;
    string genre;
};

void find(library lib[], int num) {
    string title, author;
    cout << "Function Started:- " << endl;
    cout << "Enter the name of the book: " << endl;
    cin >> title;
    cout << "Enter the author's name: " << endl;
    cin >> author;

    for (int i = 0; i < num; i++) {
        if (lib[i].title == title && lib[i].author == author) {
            cout << lib[i].title << endl;
            cout << lib[i].author << endl;
            cout << lib[i].year << endl;
            cout << lib[i].genre << endl;
            break;
        }
    }
}

void addition(library lib[], int& num) {
    int num2;
    cout << "Enter the number of books to add: ";
    cin >> num2;

    for (int i = num; i < num + num2; i++) {
        cout << "Enter the name of the book: " << endl;
        cin >> lib[i].title;
        cout << "Enter the author's name: " << endl;
        cin >> lib[i].author;
        cout << "Enter the year of the book: " << endl;
        cin >> lib[i].year;
        cout << "Enter the genre of the book: " << endl;
        cin >> lib[i].genre;
    }

    num += num2;
}

void update(library lib[], int num) {
    string title, author;
    cout << "Function Started:- " << endl;
    cout << "Enter the name of the book: " << endl;
    cin >> title;
    cout << "Enter the author's name: " << endl;
    cin >> author;

    for (int i = 0; i < num; i++) {
        if (lib[i].title == title && lib[i].author == author) {
            cout << "Enter the updated information for the book: " << endl;
            cout << "Enter the name of the book: " << endl;
            cin >> lib[i].title;
            cout << "Enter the author's name: " << endl;
            cin >> lib[i].author;
            cout << "Enter the year of the book: " << endl;
            cin >> lib[i].year;
            cout << "Enter the genre of the book: " << endl;
            cin >> lib[i].genre;
            break;
        }
    }
}

int main() {
    int num, value;
    cout << "How many books you want to register? ";
    cin >> num;
    library lib[50];

    for (int i = 0; i < num; i++) {
        cout << "Enter the name of the book: " << endl;
        cin >> lib[i].title;
        cout << "Enter the author's name: " << endl;
        cin >> lib[i].author;
        cout << "Enter the year of the book: " << endl;
        cin >> lib[i].year;
        cout << "Enter the genre of the book: " << endl;
        cin >> lib[i].genre;
    }

    while (1) {
        cout << "1. Find\n2. Add\n3. Update\n4. Exit\n";
        cin >> value;

        switch (value) {
            case 1:
                find(lib, num);
                break;

            case 2:
                addition(lib, num);
                break;

            case 3:
                update(lib, num);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
}
