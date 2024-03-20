#include<iostream>
#include<string>
using namespace std;

class Book{
protected:
    string title;
    string author;
    string publisher;

public:
    Book(const string& title, const string& author, const string& publisher)
        : title(title), author(author), publisher(publisher) {}

    void display(){
        cout<<"Title of the book: "<<title<<endl;
        cout<<"Author of the book: "<<author<<endl;
        cout<<"Publisher of the book: "<<publisher<<endl;
    }
};

class fictionBook : public Book{
    string genre;
    string protagonist;

public:
    fictionBook(const string& title, const string& author, const string& publisher, const string& genre, const string& protagonist)
        : Book(title, author, publisher), genre(genre), protagonist(protagonist) {}

    void display() {
        Book::display();
        cout<<"Genre of the book: "<<genre<<endl;
        cout<<"Protagonist of the book: "<<protagonist<<endl;
    }
};

int main(){
    fictionBook fiction("Harry Potter","Raghib","Rizwan","Sci-fi","Dk");
    fiction.display();

    return 0;
}
