#include <iostream>
#include<vector>
using namespace std;

int main(){
    int std,n,math,eng,sci,total,avg;
    
    char grade;
    cout<<"Enter the number of students: "<<endl;
    cin>>std;
    int arr[std][2];
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
        
        float percentage = (static_cast<float>(total) / 300) * 100;

        if (percentage >= 90) {
            cout << "Your grade is A" << endl;
        } else if (percentage >= 80 && percentage < 90) {
            cout << "Your grade is B" << endl;
        } else if (percentage >= 70 && percentage < 80) {
            cout << "Your grade is C" << endl;
        } else if (percentage >= 60 && percentage < 70) {
            cout << "Your grade is D" << endl;
        } else if (percentage < 60) {
            cout << "Your grade is F" << endl;
        }
        
    }
    
    for (int j = 0; j < std; j++) {
        cout << "For Student " << j + 1 << ": ";
        cout << "Total Marks: " << arr[j][0] << ", Average Marks: " << arr[j][1] << endl;
    }

}   
