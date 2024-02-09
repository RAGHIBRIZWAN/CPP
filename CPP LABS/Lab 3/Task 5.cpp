#include <iostream>
#include <vector>
using namespace std;

class Stationary
{
    vector<string> sell;
    vector<int> price;

public:
    void adds(string item, int cost)
    {
        sell.push_back(item);
        price.push_back(cost);
    }

    void display()
    {
        for (int i = 0; i < sell.size(); i++)
        {
                cout << "Item is: " << sell[i] << endl;
                cout << "Price is: " << price[i] << endl;
        }
    }

    void modify(string item, int cost)
    {
        for (int i = 0; i < 10; i++)
        {
            if (sell[i] == item)
            {
                price[i] = cost;
            }
        }
    }

    void retrieve()
    {
        for (int i = 0; i < sell.size(); i++)
        {
                cout << sell[i] << endl;
        }
    }
};

int main()
{
    Stationary shop;
    shop.adds("Bread", 100);
    shop.adds("Eggs", 50);
    shop.adds("Butter", 80);
    cout << "Retrieve function: " << endl;
    shop.retrieve();
    cout << "Display function: " << endl;
    shop.display();
}

//INCOMPLETE CODE
