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
    string ISBN;
    int pageCount;
    int pagesread;
public:

    Book(int count = 1000,int read = 0):pageCount(count),pagesread(read){}

    void setvalues(string Name,string Author,string isbn){
        name = Name;
        author = Author;
        ISBN = isbn;
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
            cout<<"There are not much pages in book"<<endl;
        }
        else{
            cout<<"You have not finished the book"<<endl;
        }
    }

    void showBookInfo(void){
        cout<<"Pages Count "<<pageCount<<endl;
        cout<<"Pages read "<<pagesread<<endl;
        cout<<"Name "<<name<<endl;
        cout<<"Author "<<author<<endl;
        cout<<"ISBN "<<ISBN<<endl;
    }
};

int main(){
    Book books;
    books.setvalues("Harry_Potter","Raghib","0124589637");
    books.showBookInfo();
    books.read();
    books.showBookInfo();
}
