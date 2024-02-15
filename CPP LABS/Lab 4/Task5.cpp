#include <iostream>
using namespace std;

class Office{
    string Location;
    int seatingCapacity;
    string* furniture;

public:

    Office(string location = "", int capacity = 0, int furnitureSize = 3)
        : Location(location), seatingCapacity(capacity)
    {
        furniture = new string[furnitureSize];
    }

    void DisplayInfo()
    {
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
    }

    ~Office(){
        cout << "Destrucutor called successfully " << endl;
        delete[] furniture;
    }
};

int main(){
    Office* office1 = new Office("Karachi",50);
    office1->DisplayInfo();
    delete[] office1;
}
