#include <iostream>
using namespace std;

class Medicine
{
protected:
    string name, formula;
    int retailPrice, manDate, expDate;

public:
    Medicine(string name, string formula, int retailPrice, int manDate, int expDate) : name(name), formula(formula), retailPrice(retailPrice), manDate(manDate), expDate(expDate) {}

    void setname(string name)
    {
        this->name = name;
    }
    void setformula(string formula)
    {
        this->formula = formula;
    }
    void setprice(int retailPrice)
    {
        this->retailPrice = retailPrice;
    }
    void setman(int manDate)
    {
        this->manDate = manDate;
    }
    void setexp(int expDate)
    {
        this->expDate = expDate;
    }

    string getname()
    {
        return name;
    }
    string getformula()
    {
        return formula;
    }
    int getprice()
    {
        return retailPrice;
    }
    int getman()
    {
        return manDate;
    }
    int getexp()
    {
        return expDate;
    }

    virtual void print()
    {
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Retail Price: " << retailPrice << endl;
        cout << "Manufacturing Date: " << manDate << endl;
        cout << "Expiry Date: " << expDate << endl;
    }

    bool operator==(Medicine& other) {
        return expDate == other.expDate;
    }
};

class Tablet : public Medicine
{
    int sucroseLevel;

public:
    Tablet(string name, string formula, int retailPrice, int manDate, int expDate, int sucroseLevel) : Medicine(name, formula, retailPrice, manDate, expDate), sucroseLevel(sucroseLevel) {}

    void print()
    {
        Medicine::print();
        cout << "Sucrose Level: " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine
{
    int absPer;

public:
    Capsule(string name, string formula, int retailPrice, int manDate, int expDate, int absPer) : Medicine(name, formula, retailPrice, manDate, expDate), absPer(absPer) {}

    void print()
    {
        Medicine::print();
        cout << "Absoption Percentage: " << absPer << endl;
    }
};

class Syrup : public Medicine
{
public:
    Syrup(string name, string formula, int retailPrice, int manDate, int expDate) : Medicine(name, formula, retailPrice, manDate, expDate) {}
};

class Pharmacist
{
public:
    string search_Medicine(string formula, Medicine med)
    {
        if (med.getformula() == formula){
            cout<<med.getname()<<endl;
        }
    }
};

class Counter{
    int overallRevenue;
public:
    Counter(int overallRevenue):overallRevenue(overallRevenue){}

    int updateRevenue(int revenue){
        return overallRevenue += revenue;
    }

    string search_Medicine(string name,Medicine med){
        if (med.getname() == name)
        {
            cout<<med.getname()<<endl;
        }
    }

    int getRevenue(){
        return overallRevenue;
    }

};
int main()
{
    Tablet tablet1("Paracetamol", "C8H9NO2", 5.99, 20230401, 20260401, 1);
    Tablet tablet2("Aspirin", "C9H8O4", 4.99, 20240501, 20260401, 0);
    Capsule capsule("Ibuprofen", "C13H18O2", 7.99, 20230501, 20260501, 80);
    Syrup syrup("Cough Syrup", "Various", 9.99, 20230601, 20260601);

    if (tablet1 == tablet2)
    {
       cout << "Both tablets expire in the same year." << endl;
    } else {
        cout << "The tablets expire in different years." << endl;
    }
    

    Pharmacist pharma;
    pharma.search_Medicine("C8H9NO2", tablet1);

    Counter count(50);
    count.updateRevenue(5);
    count.search_Medicine("Paracetamol", tablet1);

    cout<<"Overall Revenue: "<<count.getRevenue()<<endl;
}
