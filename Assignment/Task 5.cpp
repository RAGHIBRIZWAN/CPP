#include <iostream>
#include <string>
using namespace std;

class BOGOCoupon;

class Restaurant {
    string name, location, items[3];
    float prices[3];
    int codes[15];
    
public:
    static const int totalItems = 3;
    
    Restaurant(string n, string loc) : name(n), location(loc) {}
    
    void setItems_Prices(string item1, string item2, string item3, float price1, float price2, float price3) {
        items[0] = item1;
        items[1] = item2;
        items[2] = item3;
        prices[0] = price1;
        prices[1] = price2;
        prices[2] = price3;
    }
    
    void display() {
        for (int i = 0; i < totalItems; i++) {
            cout << "Item " << i + 1 << " : " << items[i] << endl;
        }
    }
    
    float generateBill() {
        return 1;
    }
    
    float applyDiscount() {
        return 1;
    }
};

class BOGOCoupon {
    string code, resCode;
    float from, until;
    
public:
    BOGOCoupon() {}

    BOGOCoupon(string c, float f, float u, string rc) : code(c), from(f), until(u), resCode(rc) {}

    bool isValid(float time) {
        return from < time && time < until;
    }

    string getRestaurantCode() {
        return resCode;
    }

    string getCouponCode() {
        return code;
    }
};

class User {
    string username, redeemedCoupons[15];
    BOGOCoupon coupons[15];
    int userAge, phoneNumber;
    
public:
    User() {}
    User(string name, int age, int number) : username(name), userAge(age), phoneNumber(number) {}
    
    int counter = 0;
    
    void accumulateCoupon() {
        string couponCode, restaurantCode;
        float validFrom, validUntil;

        cout << "Enter restaurant code: ";
        cin >> restaurantCode;
        cout << "Enter coupon code: ";
        cin >> couponCode;
        cout << "Enter valid from: ";
        cin >> validFrom;
        cout << "Enter valid until: ";
        cin >> validUntil;
        
        coupons[counter] = BOGOCoupon(couponCode, validFrom, validUntil, restaurantCode);
        if (hasValidCoupon(coupons[counter], couponCode) && redeemCoupon(couponCode)) {
            cout << "COUPON IS VALID" << endl;
            counter++;
        }
    }
    
    bool hasValidCoupon(BOGOCoupon &bg, string coupon) {
        return coupon[0] == bg.getRestaurantCode()[0] && coupon[1] == bg.getRestaurantCode()[1];
    }
    
    bool redeemCoupon(string redeemCoupon) {
        for (int i = 0; i < counter; i++) {
            if (redeemCoupon == redeemedCoupons[i]) return false;
        }
        redeemedCoupons[counter] = redeemCoupon;
        return true;
    }
};

int main() {
    Restaurant r1("Food Haven", "City Center"), r2("Pixel Bites", "Cyber street");
    r1.setItems_Prices("Burger", "Pizza", "Karhayi", 150.0, 200.5, 235.8);
    r2.setItems_Prices("Chaat", "Qorma", "Fatair", 500.0, 780.0, 900.5);

    cout << "DISPLAYING MENU OF FOOD HAVEN" << endl;
    r1.display();
    cout << "DISPLAYING MENU OF PIXEL BITES" << endl;
    r2.display();

    User u1, u2;
    u1 = User("Raghib", 18, 25468);
    u2 = User("Rizwan", 35, 12584);
    u1.accumulateCoupon();
    u2.accumulateCoupon();
    return 0;
}
