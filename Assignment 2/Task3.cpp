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

    void setLastName( string lname) { lastName = lname; }
    void setFirstName( string fname) { firstName = fname; }
    void setAddress( string addr) { address = addr; }
    void setCity( string c) { city = c; }
    void setState( string s) { state = s; }
    void setZip( string z) { zip = z; }
    void setPhone( string p) { phone = p; }
};

class DarazCustomerData:public DarazPersonData{
protected:
    int customerNumber=0;
    int loyaltyPoints=0;
public:

    void setCustomerNumber(int num) { customerNumber = num; }
    void setLoyaltyPoints(int points) { loyaltyPoints = points; }

    int getCustomerNumber() const { return customerNumber; }
    int getLoyaltyPoints() const { return loyaltyPoints; }
};

class DarazLoyaltyProgram:public DarazCustomerData{
public:
    void addLoyaltyPoints(int points) {
        if (points > 0) {
            setLoyaltyPoints(getLoyaltyPoints() + points);
            cout << "Added " << points << " loyalty points." << endl;
        } else {
            cout << "Invalid loyalty points. Please enter a positive value." << endl;
        }
    }

    void redeemLoyaltyPoints(int points) {
        if (points > 0 && points <= getLoyaltyPoints()) {
            setLoyaltyPoints(getLoyaltyPoints() - points);
            cout << "Redeemed " << points << " loyalty points." << endl;
        } else {
            cout << "Invalid loyalty points. Please enter a positive value and make sure you have enough points." << endl;
        }
    }

    void displayTotalLoyaltyPoints() {
        cout << "Total loyalty points: " << getLoyaltyPoints() << endl;
    }
};

int main(){
    DarazCustomerData customer;
    customer.setFirstName("Raghib");
    cout << "First Name: " << customer.getFirstName() << endl;
    customer.setLastName("Rizwan");
    cout << "Last Name: " << customer.getLastName() << endl;
    customer.setCity("Karachi");
    cout << "City: " << customer.getCity() << endl;
    customer.setAddress("Nazimabad");
    cout << "Address: " << customer.getAddress() << endl;
    customer.setPhone("0123456789");
    cout << "Phone: " << customer.getPhone() << endl;
    customer.setState("Pakistan");
    cout << "State: " << customer.getState() << endl;
    customer.setZip("0123");
    cout << "Zip: " << customer.getZip() << endl;


    DarazLoyaltyProgram loyalty;
    loyalty.setCustomerNumber(123);
    loyalty.setLoyaltyPoints(50);
    loyalty.addLoyaltyPoints(50);
    loyalty.displayTotalLoyaltyPoints();
    loyalty.redeemLoyaltyPoints(40);
    loyalty.displayTotalLoyaltyPoints();

    return 0;
}
