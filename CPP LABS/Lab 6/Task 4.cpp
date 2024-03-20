/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 20/3/2024
*/

#include<iostream>
using namespace std;

inline double average(int runs,int dismissals){
    double average = static_cast<double>(runs)/dismissals;
    return average;         
}

inline double strikeRate(int runs, int balls){
    double strike = static_cast<double>(runs)/balls*100;
    return strike;
}

int main(){
    int totalRuns;
    int totalBalls;
    int totalDismissals;

    cout<<"Enter total number of runs: ";
    cin>>totalRuns;
    cout<<"Enter total number of balls faced: ";
    cin>>totalBalls;
    cout<<"Enter the total dismissals: ";
    cin>>totalDismissals;

    double avr = average(totalRuns,totalDismissals);
    double strike = strikeRate(totalRuns,totalBalls);

    cout<<"The average is: "<<avr<<endl;
    cout<<"The strike rate is: "<<strike<<endl;

}
