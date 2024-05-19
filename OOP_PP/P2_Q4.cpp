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

    int getmaxQuantityPerInvestor(){
        return maxQuantityPerInvestor;
    }

    virtual bool isEligibleToBuy(int purchaseQuantity) {
        if (purchaseQuantity <= maxQuantityPerInvestor && purchaseQuantity <= availableQuantity)
        {
            return true;
        }
        else if(purchaseQuantity <= 0){
            cout<<"Invalid input!"<<endl;
            return false;
        }
        else{
            return false;
        }
    }

    virtual void displayInfo() {
        cout << "Symbol: " << symbol << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Price: " << price << endl;
        cout << "Available Quantity: " << availableQuantity << endl;
        cout << "Max Quantity Per Investor: " << maxQuantityPerInvestor << endl;
        cout << "Stock Category Quantity: " << stockCategoryQuantity << endl;
    }

    bool operator!=(const Stock& other) const {
        return symbol != other.symbol || companyName != other.companyName;
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
        if (purchaseQuantity >= 50 )
        {
            return true;
        }
        else if(purchaseQuantity < 50){
            return false;
        }
        else if (purchaseQuantity % 5 != 0 )
        {
            cout<<"Should be multiple of 5";
            return false;
        }
    }
};

class TechStock : public Stock {
public:
    TechStock(string symbol, string companyName, double price, int availableQuantity, int maxQuantityPerInvestor, int stockCategoryQuantity)
        : Stock(symbol, companyName, price, availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity) {}

    bool isEligibleToBuy(int purchaseQuantity) {
        if (purchaseQuantity % 10 == 0 )
        {
            return true;
        }
        else if(purchaseQuantity % 10 != 0){
            return false;
        }
        else if(purchaseQuantity>100){
            cout<<"Max purchase limit is 100"<<endl;
            return false;
        }

        
    }
};

class Investor {
protected:
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
        if (hasLoan == true)
        {
            cout<<"You already availed the loan!"<<endl;
            return false;
        }
        bool totalPrice = stock.getPrice() * purchaseQuantity;
        if (totalPrice > availableFunds)
        {
            cout<<"Insufficient funds!"<<endl;
            return false;
        }
        return stock.isEligibleToBuy(purchaseQuantity);
    }
};

class LongTermInvestor : public Investor {
public:
    LongTermInvestor(string name, string CNIC, string email, int availableFunds, bool hasLoan)
        : Investor(name, CNIC, email, availableFunds, hasLoan) {}

    bool canBuyStock(Stock& stock, int purchaseQuantity) {
        if (hasLoan && availableFunds < 50000)
        {
            cout<<"Insufficient funds due to loan!"<<endl;
            return false;
        }

        if (purchaseQuantity > stock.getmaxQuantityPerInvestor())
        {
            cout<<"Exceeds max quantity per investor!"<<endl;
            return false;
        }

        return stock.isEligibleToBuy(purchaseQuantity);
    }
};

int main() {
    // Create a market
    Market market;

    // Create some stocks
    Stock* stock1 = new PharmaStock("PHARMA", "Pharma Company", 10.0, 100, 200, 500);
    Stock* stock2 = new TechStock("TECH", "Tech Company", 20.0, 150, 300, 600);

    // Add stocks to the market
    market.addStock(stock1);
    market.addStock(stock2);

    // Create investors
    Investor* investor1 = new DayTrader("Raghib Rizwan", "12345", "raghib@example.com", 1000, false);
    Investor* investor2 = new LongTermInvestor("Rizwan Rabani ", "67890", "rizwan@example.com", 50000, true);

    // Try to buy stocks
    int purchaseQuantity = 50;
    if (investor1->canBuyStock(*stock1, purchaseQuantity))
    {
        cout<<"Transaction successful!"<<endl;
    }
    else
    {
        cout<<"Transaction failed!"<<endl;
    }

    purchaseQuantity = 120;
    if (investor2->canBuyStock(*stock2, purchaseQuantity))
    {
        cout<<"Transaction successful!"<<endl;
    }
    else
    {
        cout<<"Transaction failed!"<<endl;
    }

    // Clean up
    delete stock1;
    delete stock2;
    delete investor1;
    delete investor2;

    return 0;
}
