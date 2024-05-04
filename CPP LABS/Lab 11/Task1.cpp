/*
Programmer: Raghib Rizwan Rabani
NU ID: 23K-0012
*/

#include<iostream>
using namespace std;

class Convert{
protected:
    float val1,val2;
public:
    Convert(float val1,float val2):val1(val1),val2(val2){}
    virtual void compute(){}
};

class l_to_g : public Convert{
public:
    l_to_g(float val1):Convert(val1, 0){}
    void compute(){
        val2 = val1 * 0.264172;
        cout<<val2<<endl;
    }
};

class f_to_c : public Convert{
public:
    f_to_c(float val1):Convert(val1, 0){}
    void compute(){
        val2 = (val1 - 32) * (5.0/9.0);
        cout<<val2<<endl;
    }
};

int main(){
    l_to_g l(4);
    f_to_c f(70);

    Convert* con1 = &l;
    Convert* con2 = &f;

    con1->compute();
    con2->compute();
}
