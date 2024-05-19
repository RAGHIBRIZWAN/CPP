#include <iostream>
#include <vector>
using namespace std;

class Stock {
    string symbol, companyName;
    double price;
    int availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity;

public:
    Stock(string symbol, string companyName, double price, int availableQuantity, int maxQuantityPerInvestor, int stockCategoryQuantity)
        : symbol(symbol), companyName(companyName), price(price), availableQuantity(availableQuantity), maxQuantityPerInvestor(maxQuantityPerInvestor), stockCategoryQuantity(stockCategoryQuantity) {}

    string getSymbol() {
        return symbol;
    }

    string getCompanyName() {
        return companyName;
    }

    double getPrice() {
        return price;
    }

    virtual bool isEligibleToBuy(int purchaseQuantity) {
        return false;
    }

    virtual void displayInfo() {
        cout << "Symbol: " << symbol << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Price: " << price << endl;
        cout << "Available Quantity: " << availableQuantity << endl;
        cout << "Max Quantity Per Investor: " << maxQuantityPerInvestor << endl;
        cout << "Stock Category Quantity: " << stockCategoryQuantity << endl;
    }
};

class Market {
    vector<Stock*> stocks;

public:
    Market() {}

    void addStock(Stock* stock) {
        stocks.push_back(stock);
    }

    void tradeStocks() {
    }

    int getNumStocks() const {
        return stocks.size();
    }
};

class PharmaStock : public Stock {
public:
    PharmaStock(string symbol, string companyName, double price, int availableQuantity, int maxQuantityPerInvestor, int stockCategoryQuantity)
        : Stock(symbol, companyName, price, availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity) {}

    bool isEligibleToBuy(int purchaseQuantity) {
        return false;
    }
};

class TechStock : public Stock {
public:
    TechStock(string symbol, string companyName, double price, int availableQuantity, int maxQuantityPerInvestor, int stockCategoryQuantity)
        : Stock(symbol, companyName, price, availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity) {}

    bool isEligibleToBuy(int purchaseQuantity) {
        return false;
    }
};

class Investor {
    string name;
    string CNIC;
    string email;
    int availableFunds;
    bool hasLoan;

public:
    Investor(string name, string CNIC, string email, int availableFunds, bool hasLoan)
        : name(name), CNIC(CNIC), email(email), availableFunds(availableFunds), hasLoan(hasLoan) {}

    virtual bool canBuyStock(Stock& stock, int purchaseQuantity) = 0;
};

class DayTrader : public Investor {
public:
    DayTrader(string name, string CNIC, string email, int availableFunds, bool hasLoan)
        : Investor(name, CNIC, email, availableFunds, hasLoan) {}

    bool canBuyStock(Stock& stock, int purchaseQuantity) {
        return false;
    }
};

class LongTermInvestor : public Investor {
public:
    LongTermInvestor(string name, string CNIC, string email, int availableFunds, bool hasLoan)
        : Investor(name, CNIC, email, availableFunds, hasLoan) {}

    bool canBuyStock(Stock& stock, int purchaseQuantity) {
        return false;
    }
};

int main() {
    return 0;
}
