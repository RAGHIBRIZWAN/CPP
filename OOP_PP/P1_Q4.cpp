#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Product
{
public:
    string name;
    double price;
    string manufacturer;
    int stockLevel;

    Product(string n, double p, string m, int s)
        : name(n), price(p), manufacturer(m), stockLevel(s) {}
};

class ShoppingCart
{
    vector<Product<string>> products;

public:
    ShoppingCart() : products() {}

    void addProduct(Product<string> product)
    {
        products.push_back(product);
    }

    void removeProduct(Product<string> product)
    {
        bool found = false;
        for (size_t i = 0; i < products.size(); ++i)
        {
            if (products[i].name == product.name)
            {
                products.erase(products.begin() + i);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Product is not in the list" << endl;
        }
    }

    double calculateTotalPrice()
    {
        double totalPrice = 0.0;
        for (int i = 0; i < products.size(); i++)
        {
            int quantity;
            cout << "Enter quantity for " << products[i].name << ": ";
            cin >> quantity;
            if (quantity <= products[i].stockLevel)
            {
                totalPrice += products[i].price * quantity;
            }
            else
            {
                cout << "Quantity exceeds stock level" << endl;
            }
        }
        return totalPrice;
    }

    void displayProducts()
    {
        for (int i = 0; i < products.size(); i++)
        {
            cout << "Product Name: " << products[i].name << ", Price: " << products[i].price
                 << ", Manufacturer: " << products[i].manufacturer
                 << ", Stock Level: " << products[i].stockLevel << endl;
        }
    }
};

class Order
{
    string orderID;
    ShoppingCart shoppingCart;

public:
    void generateOrderID(string customerName, string phoneNumber)
    {
        orderID = customerName[0] + customerName[customerName.size() - 1] + phoneNumber[phoneNumber.size() - 1] + phoneNumber[phoneNumber.size() - 2];
    }

    ShoppingCart getShoppingCart()
    {
        return shoppingCart;
    }
    void displayOrderID()
    {
        cout << "Order ID: " << orderID << endl;
    }
};

int main()
{
    // Create some products
    Product<string> p1("Laptop", 1200.50, "Dell", 10);
    Product<string> p2("Smartphone", 799.99, "Samsung", 20);
    Product<string> p3("Headphones", 199.99, "Sony", 15);

    // Create a shopping cart and add products
    ShoppingCart cart;
    cart.addProduct(p1);
    cart.addProduct(p2);
    cart.addProduct(p3);

    // Display products in the cart
    cart.displayProducts();

    // Calculate the total price of products in the cart
    double total = cart.calculateTotalPrice();
    cout << "Total Price: $" << total << endl;

    // Create an order and generate order ID
    Order order;
    order.generateOrderID("John Doe", "12345678901");
    order.displayOrderID();

    // Display products in the order's shopping cart
    order.getShoppingCart().displayProducts();

    return 0;
}
