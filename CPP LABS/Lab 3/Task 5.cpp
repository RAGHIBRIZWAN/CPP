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

    void receipt()
    {
        int bill = 0;
        int products = 0, quantity = 1;
        string items;

        cout << "How many products are there?";
        cin >> products;

        for (int i = 0; i < products; i++)
        {
            cout << "Enter product name: ";
            cin >> items;
            for (int j = 0; j < products; j++)
            {
                if (items == sell[j])
                {
                    cout << "Enter quantity of the product: ";
                    cin >> quantity;
                    bill += price[j] * quantity;
                }
            }
        }

        cout << "Yout total bill is: " << bill<<endl;
    }
};

int main()
{
    string prod,mod;
    int cost1,cost2;
    Stationary shop;

    int number=0;
    while (number!=6)
{
    cout << "1.add\n2.modify\n3.retrieve\n4.display\n5.reciept\n6.exit\n";
    cin >> number;



        switch (number)
        {
        case 1:
            
            cout << "What do you want to add?" << endl;
            cin >> prod;
            cout << "What is its price?" << endl;
            cin>>cost1;
            shop.adds(prod, cost1);
            break;

            case 2:
            cout << "What do you want to modify?" << endl;
            cin >> mod;
            cout << "What is its price?" << endl;
            cin>>cost2;
            shop.modify(mod, cost2);
            break;

            case 3:
            shop.retrieve();
            break;

            case 4:
            shop.display();
            break;

            case 5:
            shop.receipt();
            break;

            case 6:
            return 0;
            break;

        default:
            break;
        }
    }
}
