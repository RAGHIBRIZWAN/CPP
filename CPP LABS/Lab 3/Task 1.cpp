#include <iostream>
using namespace std;

class BoardMarker
{
    string Brand;
    string Shade;
    bool Refillable;
    bool Status;

public:
    void setBrand(string brand)
    {
        Brand = brand;
    }
    void getBrand(string brand)
    {
        cout<<Brand<<endl;
    }
    void setShade(string shade)
    {
        Shade = shade;
    }

    void getShade(string shade)
    {
        cout<<Shade<<endl;
    }
    void setRefillable(bool refill)
    {
        Refillable = refill;
    }
    void setStatus(bool status)
    {
        Status = status;
    }

    void writing(){
        if(Status == false){
            cout<<"Ink is finished"<<endl;
        }
        else{
            cout<<"You can write more"<<endl;
        }
    }

    void refill(){
        if(Refillable){
            cout<<"It is refillable"<<endl;
        }
        else{
        cout<<"It is not refillable"<<endl;
        }
    }

};

int main()
{
    BoardMarker marker;
    marker.setBrand("Dollor");
    marker.setShade("Black");
    marker.setRefillable(true);
    marker.setStatus(true);
    marker.writing();
    marker.refill();
    marker.getBrand();
    marker.getShade();
}
