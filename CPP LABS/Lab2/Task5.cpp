#include <iostream>
using namespace std;

struct product
{
    string name;
    int price;
    int quantity;
    int ID;
};

void find(product prod[], int num)
{
    int ID;
    cout << "Function Started:- " << endl;
    cout << "Enter the ID of the product: " << endl;
    cin >> ID;

    for (int i = 0; i < num; i++)
    {
        if (prod[i].ID == ID)
        {
            cout << prod[i].name << endl;
            cout << prod[i].price << endl;
            cout << prod[i].quantity << endl;
            cout << prod[i].ID << endl;
            break;
        }
    }
}

void addition(product prod[], int &num)
{
    int num2;
    cout << "Enter the number of products you want to add: ";
    cin >> num2;

    for (int i = num; i < num + num2; i++)
    {
        cout << "Enter the name of the product: " << endl;
        cin >> prod[i].name;
        cout << "Enter the price of the product: " << endl;
        cin >> prod[i].price;
        cout << "Enter the quantity of the product: " << endl;
        cin >> prod[i].quantity;
        cout << "Enter the ID of the product: " << endl;
        cin >> prod[i].ID;
    }

    num += num2;
}

void update(product prod[], int num)
{
    int ID;
    cout << "Function Started:- " << endl;
    cout << "Enter the ID of the product: " << endl;
    cin >> ID;

    for (int i = 0; i < num; i++)
    {
        if (prod[i].ID == ID)
        {
            cout << "Enter the updated information for the product: " << endl;
            cout << "Enter the name of the product: " << endl;
            cin >> prod[i].name;
            cout << "Enter the price of the product: " << endl;
            cin >> prod[i].price;
            cout << "Enter the quantity of the product: " << endl;
            cin >> prod[i].quantity;
            cout << "Enter the ID of the product: " << endl;
            cin >> prod[i].ID;
            break;
        }
    }
}

int main()
{
    int num, value;
    cout << "How many products you want to register? ";
    cin >> num;
    product prod[50];

    for (int i = 0; i < num; i++)
    {
        cout << "Enter the name of the product: " << endl;
        cin >> prod[i].name;
        cout << "Enter the price of the product: " << endl;
        cin >> prod[i].price;
        cout << "Enter the quantity of the product: " << endl;
        cin >> prod[i].quantity;
        cout << "Enter the ID of the product: " << endl;
        cin >> prod[i].ID;
    }

    while (1)
    {
        cout << "1. Find\n2. Add\n3. Update\n4. Exit\n";
        cin >> value;

        switch (value)
        {
        case 1:
            find(prod, num);
            break;

        case 2:
            addition(prod, num);
            break;

        case 3:
            update(prod, num);
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}
