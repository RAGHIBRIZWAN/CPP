#include <iostream>
using namespace std;

struct Register{
    int Course_Id;
    string Course_Name;
};

struct Student: Register
{

    int Student_Id;
    string First_Name;
    string Last_Name;
    int Cell_No;
    string Email; 
};

int main(){
    Student stud[5];

    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter your Course ID: "<<endl;
        cin>>stud[i].Course_Id; 
        cout<<"Enter your Course Name: "<<endl;
        cin>>stud[i].Course_Name; 
        cout<<"Enter your Student ID: "<<endl;
        cin>>stud[i].Student_Id; 
        cout<<"Enter your First Name: "<<endl;
        cin>>stud[i].First_Name; 
        cout<<"Enter your Last Name: "<<endl;
        cin>>stud[i].Last_Name; 
        cout<<"Enter your Cell No: "<<endl;
        cin>>stud[i].Cell_No; 
        cout<<"Enter your Email: "<<endl;
        cin>>stud[i].Email; 
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<stud[i].Course_Id<<endl;
        cout<<stud[i].Course_Name<<endl;
        cout<<stud[i].Student_Id<<endl;
        cout<<stud[i].First_Name<<endl;
        cout<<stud[i].Last_Name<<endl;
        cout<<stud[i].Cell_No<<endl;
        cout<<stud[i].Email<<endl;
    }
    
    
}
