#include <iostream>
using namespace std;

class Smartphone{
    string Brand;
    string Model;
    string Resolution;
    string RAM;
    string ROM;
    string Storage;

public:

    void setData(string brand,string model,string resolution,string ram,string rom,string storage){
        Brand = brand;
        Model = model;
        Resolution = resolution;
        RAM = ram;
        ROM = rom;
        Storage = storage;
    }
   
    void getData(void){
        cout<<Brand<<endl;
        cout<<Model<<endl;
        cout<<Resolution<<endl;
        cout<<RAM<<endl;
        cout<<ROM<<endl;
        cout<<Storage<<endl;        
    }
    void call(string number){
        cout<<"Making phone call to "<<number<<endl;
    }

    void message(string number1, string number2){
        cout<<"Sending message to "<<number1<<" from "<<number2<<endl;
    }

    void wifi(string network){
        cout<<"Connecting wifi of network name "<<network<<endl;
    }

    void browsing(string internet){
        cout<<"Browsing "<<internet<< " on internet on "<<Brand<<" "<<Model;
    }
};

int main(){
    Smartphone phone;
    phone.setData("Apple","Iphone 14","600x600","4GB","64GB","100GB");
    phone.getData();
    phone.call("03340030844");
    phone.message("03346555663","03340030844");
    phone.wifi("StormFibre");
    phone.browsing("Chrome");
}
