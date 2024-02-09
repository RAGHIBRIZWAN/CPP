#include <iostream>
using namespace std;

class WaterBottle
{
    string Company;
    string Color;
    double Capacity;

public:
    void setCompany(string company)
    {
        Company = company;
    }
    void getCompany(void)
    {
        cout << "Comapny is: " << Company<<endl;
    }
    void setColor(string color)
    {
        Color = color;
    }
    void getColor(void)
    {
        cout << "Color is: " << Color<<endl;
    }
    void setCapacity(int capacity)
    {
        Capacity = capacity;
    }
    void getCapacity(void)
    {
        cout << "Capacity is: " << Capacity<<endl;
    }

    void changecap(int capacity)
    {
        double capml, capl;
        cout << "Enter the value you want for capacity: " << endl;
        cin >> capml;

        cout << "Capacity in milliliters is: " << capml<<endl;

        capl = capml / 1000;

        cout << "Capacity in liters is: " << capl<<endl;
    }
};

int main()
{
    double capacity;
    cout << "Enter the water capacity of bottle in millileters: " << endl;
    cin >> capacity;

    WaterBottle bottle;
    bottle.setCompany("Linux");
    bottle.setColor("Blue");
    bottle.setCapacity(capacity);
    bottle.getCompany();
    bottle.getColor();
    bottle.getCapacity();
    bottle.changecap(capacity);
}
