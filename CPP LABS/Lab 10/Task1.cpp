/*
Name: Raghib Rizwan Rabani
NU ID: 23K-0012
*/
#include<iostream>
using namespace std;

class Logo{
    friend class Platform;
    string log;
public:
    Logo(string log):log(log){}
};
class Platform{
public:
    void display(Logo &obj){
        obj.log = "doge coin";
        cout<<obj.log;
    }
};
class Server{
    
};

int main(int argc, char const *argv[])
{
    Logo logo("Blue Bird");
    Platform plat;
    plat.display(logo);
    return 0;
}
