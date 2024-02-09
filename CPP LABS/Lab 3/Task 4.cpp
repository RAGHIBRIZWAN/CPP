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

    void setBrand(string brand){
        Brand = brand;
    }
    void setModel(string model){
        Model = model;
    }
    void setResolution(string resolution){
        Resolution = resolution;
    }
    void setRAM(string ram){
        RAM = ram;
    }
    void setROM(string rom){
        ROM = rom;
    }
    void setSTORAGE(string storage){
        Storage = storage;
    }
    void getBrand(void){
        cout<<Brand<<endl;
    }
    void getmodel(void){
        cout<<Model<<endl;
    }
    void getResolution(void){
        cout<<Resolution<<endl;
    }
    void getRAM(void){
        cout<<RAM<<endl;
    }
    void getROM(void){
        cout<<ROM<<endl;
    }
    void getSTORAGE(void){
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
    phone.setBrand("Apple");
    phone.setModel("Iphone 14");
    phone.setResolution("600x600");
    phone.setRAM("4GB");
    phone.setROM("64GB");
    phone.setSTORAGE("100GB");
    phone.getBrand();
    phone.getmodel();
    phone.getResolution();
    phone.getRAM();
    phone.getROM();
    phone.getSTORAGE();
    phone.call("03340030844");
    phone.message("03346555663","03340030844");
    phone.wifi("StormFibre");
    phone.browsing("Chrome");
}
