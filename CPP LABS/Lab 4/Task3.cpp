#include <iostream>
using namespace std;

class WeekDays
{
    string days[10];
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
        currentDay = current;
    }

    void GetCurrentDay()
    {
        for (int i = 0; i < 7; i++)
        {
            if (currentDay == i)
            {
                cout << "Current day is: " << days[i];
            }
        }
    }

    void GetNextDay()
    {
        for (int i = 0; i < 7; i++)
        {
            if (currentDay+1 == i)
            {
                cout << "Current day is: " << days[i];
            }
        }
    }

    void GetPreviousDay()
    {
        for (int i = 0; i < 7; i++)
        {
            if (currentDay-1 == i)
            {
                cout << "Current day is: " << days[i];
            }
        }
    }
};

int main()
{
}
