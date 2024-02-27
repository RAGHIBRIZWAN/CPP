/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 25/2/2024
*/

#include <iostream>
#include <vector>
using namespace std;

class menuItems
{
public:
    string foodName;
    double foodPrice;
};

class Menu
{

public:
    vector<menuItems> menu;

    void addItems()
    {
        int items;
        string food;
        double price;
        cout << "How many items do you want to add? ";
        cin >> items;
        for (int i = 0; i < items; i++)
        {
            cout << "Item: " << i + 1 << endl;
            cout << "Enter food name: ";
            cin >> food;
            cout << "Enter food price: ";
            cin >> price;
            menuItems item = {food, price};
            menu.push_back(item);
        }
    }

    void removes()
    {
        string food;
        cout << "Enter the name of the food to remove: ";
        cin >> food;

        bool itemRemoved = false;
        for (int i = 0; i < menu.size(); i++)
        {
            if (menu[i].foodName == food)
            {
                menu.erase(menu.begin() + i);
                itemRemoved = true;
                break;
            }
        }

        if (!itemRemoved)
        {
            cout << "Item not found." << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < menu.size(); i++)
        {
            cout << menu[i].foodName << "  " << menu[i].foodPrice << endl;
        }
    }
};

class Payment
{
public:
    double amount;
};

class Order
{

public:
    vector<menuItems> items;
    double total;

    void add(menuItems item)
    {
        items.push_back(item);
        total += item.foodPrice;
    }

    double getTotal()
    {
        return total;
    }
};

int main()
{
    Menu menu;
    Order order;
    int choice;

    do
    {
        cout << "\n1. Add item to menu\n2. Remove item from menu\n3. Display menu\n4. Place order\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            menu.addItems();
            break;
        case 2:
            menu.removes();
            break;
        case 3:
            menu.display();
            break;
        case 4:
        {
            int items;
            cout << "How many items do you want to order? ";
            cin >> items;
            for (int i = 0; i < items; i++)
            {
                string food;
                cout << "Name the item " << i + 1 << ": ";
                cin >> food;
                for (int j = 0; j < menu.menu.size(); j++)
                {
                    if (menu.menu[j].foodName == food)
                    {
                        order.add(menu.menu[j]);
                        break;
                    }
                }
            }
            cout << "Total cost: " << order.getTotal() << endl;
        }

        break;
        default:
            break;
        }
        }
        while (choice != 5)
            ;

        return 0;
    }
