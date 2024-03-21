#include<iostream>
#include<vector>
using namespace std;

class DarazPersonData{
    string lastName,firstName,address,city,state,zip,phone;
public:
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }

    void setLastName( string& lname) { lastName = lname; }
    void setFirstName( string& fname) { firstName = fname; }
    void setAddress( string& addr) { address = addr; }
    void setCity( string& c) { city = c; }
    void setState( string& s) { state = s; }
    void setZip( string& z) { zip = z; }
    void setPhone( string& p) { phone = p; }
};

class DarazCustomerData{
protected:
    int customerNumber;
    int loyaltyPoints;
public:
    int getCustomerNumber() const { return customerNumber; }
    int getLoyaltyPoints() const { return loyaltyPoints; }

    void setCustomerNumber(int num) { customerNumber = num; }
    void setLoyaltyPoints(int points) { loyaltyPoints = points; }

};

class DarazLoyaltyProgram{
public:
    void addLoyaltyPoints(DarazCustomerData& customer, int points) {
        if (points > 0) {
            customer.setLoyaltyPoints(customer.getLoyaltyPoints() + points);
            cout << "Added " << points << " loyalty points." << endl;
        } else {
            cout << "Invalid loyalty points. Please enter a positive value." << endl;
        }
    }

    void redeemLoyaltyPoints(DarazCustomerData& customer, int points) {
        if (points > 0 && points <= customer.getLoyaltyPoints()) {
            customer.setLoyaltyPoints(customer.getLoyaltyPoints() - points);
            cout << "Redeemed " << points << " loyalty points." << endl;
        } else {
            cout << "Invalid loyalty points. Please enter a positive value and make sure you have enough points." << endl;
        }
    }

    void displayTotalLoyaltyPoints(const DarazCustomerData& customer) {
        cout << "Total loyalty points: " << customer.getLoyaltyPoints() << endl;
    }
};

int main(){
    DarazCustomerData customer;
    customer.setCustomerNumber(123);
    customer.setLoyaltyPoints(50);

    DarazLoyaltyProgram loyalty;
    loyalty.addLoyaltyPoints(customer,50);
    loyalty.displayTotalLoyaltyPoints(customer);
    loyalty.redeemLoyaltyPoints(customer,40);
    loyalty.displayTotalLoyaltyPoints(customer);
}
