#include <iostream>
using namespace std;

class validateString
{
    string s;
    
public:

    validateString(){};
    validateString(string s){
        this -> s = s;
    }
    
    void check() const{
       bool hasNumber = false;
        for(int i = 0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
               hasNumber = true;
                break;
            }
        }
        if(hasNumber){
            cout<<"Number detected" << endl;
        }
        else{
            cout<<"Number not detected" << endl;
        }
    }
};

int main() {
    validateString str1("my name is Raghib");
    str1.check();
    validateString str2("hello 123");
    str2.check();

    return 0;
}
