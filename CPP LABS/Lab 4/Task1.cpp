/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 15/2/2024
*/

#include<iostream>
using namespace std;

class Book{
    string name;
    string author;
    int ISBN;
    int pageCount;
    int pagesread;
public:

    Book(){}

    Book(string Name, string Author,int isbn,int page,int read){
        name = Name;
        author = Author;
        ISBN = isbn;
        pageCount = page;
        pagesread = read;
    }

    void read(){
        int read;
        cout<<"How many pages have you read?"<<endl;
        cin>>read;
        pagesread += read;
        if (pagesread == pageCount )
        {
            cout<<"You have finished the book"<<endl;
        }
        else if(pagesread > pageCount){
            cout<<"There are not much pages in book";
        }
        else{
            cout<<"You have not finished the book"<<endl;
        }
    }
};

int main(){
    Book books("Harry_Potter","Raghib",01245,50,40);
    books.read();
}
