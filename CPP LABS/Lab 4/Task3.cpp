/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 15/2/2024
*/

#include <iostream>
using namespace std;

class WeekDays
{
    string days[7];
    int currentDay;

public:
    WeekDays()
    {
        days[0] = "Mon";
        days[1] = "Tue";
        days[2] = "Wed";
        days[3] = "Thurs";
        days[4] = "Fri";
        days[5] = "Sat";
        days[6] = "Sun";
    }

    WeekDays(int current)
    {
        days[0] = "Mon";
        days[1] = "Tue";
        days[2] = "Wed";
        days[3] = "Thurs";
        days[4] = "Fri";
        days[5] = "Sat";
        days[6] = "Sun";
        currentDay = current;
    }

    void GetCurrentDay()
    {
        cout << "Current Day is: " << days[currentDay] << endl;
    }

    void GetNextDay()
    {
        int nextDay = (currentDay + 1) % 7;
        cout << "Next Day is: " << days[nextDay] << endl;
    }

    void GetPreviousDay()
    {
        int previousDay = (currentDay - 1 + 7) % 7;
        cout << "Previous Day is: " << days[previousDay] << endl;
    }

    void GetNthDay()
    {
        int n;
        cout << "Enter the number of days from today: ";
        cin >> n;
        int nthDay = (currentDay + n) % 7;
        cout << "Day after " << n << " days is: " << days[nthDay] << endl;
    }
};

int main()
{
    WeekDays week(6);
    week.GetCurrentDay();
    week.GetNextDay();
    week.GetPreviousDay();
    week.GetNthDay();
}
