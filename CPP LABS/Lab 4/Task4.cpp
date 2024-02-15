/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 15/2/2024
*/

#include <iostream>
using namespace std;

class Office
{
    string Location;
    int seatingCapacity;
    string furniture[3];

public:
    Office(string location = "", int capacity = 0, string *furn = nullptr)
        : Location(location), seatingCapacity(capacity)
    {
        for (int i = 0; i < 3; i++)
        {
            furniture[i] = furn[i];
        }
    }

    void DisplayInfo()
    {
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Furniture: " << furniture[0] << ", " << furniture[1] << ", " << furniture[2] << endl;
    }
};

int main()
{
    string furn[3] = {"Desk", "Chair", "Bookshelf"};
    Office office1("Karachi", 50, furn);
    cout << "Office 1:" << endl;
    office1.DisplayInfo();
    cout << endl;
}
