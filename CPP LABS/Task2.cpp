#include <iostream>
using namespace std;

int main(){
    int std,n,math,eng,sci,total,avg;
    
    char grade;
    cout<<"Enter the number of students: "<<endl;
    cin>>std;
    int arr[std][3];
    for (int i = 0; i < std; i++)
    {
        cout<<"Enter the marks of maths"<<endl;
        cin>>math;
        cout<<"Enter the marks of english"<<endl;
        cin>>eng;
        cout<<"Enter the marks of science"<<endl;
        cin>>sci;

        total = math+eng+sci;
        
        arr[i][0] = total;
        
        avg = total/3;
        
        arr[i][1] = avg;
        
        if((total/300)*100 == 90 || (total/300)*100 >= 90){
            cout<<"Your grade is A";
        }
        if((total/300)*100 == 80 || (total/300)*100 < 90){
            cout<<"Your grade is B";
        }
        if((total/300)*100 == 70 || (total/300)*100 < 80){
            cout<<"Your grade is C";
        }
        if((total/300)*100 == 60 || (total/300)*100 < 70){
            cout<<"Your grade is D";
        }
        if((total/300)*100 < 60){
            cout<<"Your grade is F";
        }
        
    }
    
    for(int j = 0; j < std; j++){
        for(int k = 0; k < 3; k++){
            cout<<arr[j][k]<<endl;
        }
    }

}
