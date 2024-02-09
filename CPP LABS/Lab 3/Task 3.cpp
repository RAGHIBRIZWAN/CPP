#include <iostream>
using namespace std;

class Calender
{
    int year;
    string jan[31];
    string feb[28];
    string mar[31];
    string apr[30];
    string may[31];
    string jun[30];
    string jul[31];
    string aug[31];
    string sep[30];
    string oct[31];
    string nov[30];
    string dec[31];

public:
    void adds(int date, string month) {
        string task;
        cout << "Define the task: ";
        cin >> task;

        if (month == "jan") {
            jan[date - 1] = task;
        } else if (month == "feb") {
            feb[date - 1] = task;
        } else if (month == "mar") {
            mar[date - 1] = task;
        } else if (month == "apr") {
            apr[date - 1] = task;
        } else if (month == "may") {
            may[date - 1] = task;
        } else if (month == "jun") {
            jun[date - 1] = task;
        } else if (month == "jul") {
            jul[date - 1] = task;
        } else if (month == "aug") {
            aug[date - 1] = task;
        } else if (month == "sep") {
            sep[date - 1] = task;
        } else if (month == "oct") {
            oct[date - 1] = task;
        } else if (month == "nov") {
            nov[date - 1] = task;
        } else if (month == "dec") {
            dec[date - 1] = task;
        }
    }

    void removes(int date, string month) {
        if (month == "jan") {
            jan[date - 1] = "";
        } else if (month == "feb") {
            feb[date - 1] = "";
        } else if (month == "mar") {
            mar[date - 1] = "";
        } else if (month == "apr") {
            apr[date - 1] = "";
        } else if (month == "may") {
            may[date - 1] = "";
        } else if (month == "jun") {
            jun[date - 1] = "";
        } else if (month == "jul") {
            jul[date - 1] = "";
        } else if (month == "aug") {
            aug[date - 1] = "";
        } else if (month == "sep") {
            sep[date - 1] = "";
        } else if (month == "oct") {
            oct[date - 1] = "";
        } else if (month == "nov") {
            nov[date - 1] = "";
        } else if (month == "dec") {
            dec[date - 1] = "";
        }
    }


    void display()
    {
        cout << "Tasks for Jan:" << endl;
        for (int i = 0; i < 31; ++i)
        {
            if (!jan[i].empty())
            {
                cout << "jan " << i + 1 << ": " << jan[i] << endl;
            }
        }
        cout << "Tasks for Feb:" << endl;
        for (int i = 0; i < 28; ++i)
        {
            if (!feb[i].empty())
            {
                cout << "Day " << i + 1 << ": " << feb[i] << endl;
            }
        }
        cout << "Tasks for Mar:" << endl;
        for (int i = 0; i < 31; ++i)
        {
            if (!mar[i].empty())
            {
                cout << "Day " << i + 1 << ": " << mar[i] << endl;
            }
        }
        cout << "Tasks for Apr:" << endl;
        for (int i = 0; i < 30; ++i)
        {
            if (!apr[i].empty())
            {
                cout << "Day " << i + 1 << ": " << apr[i] << endl;
            }
        }
        cout << "Tasks for May:" << endl;
        for (int i = 0; i < 31; ++i)
        {
            if (!may[i].empty())
            {
                cout << "Day " << i + 1 << ": " << may[i] << endl;
            }
        }
        cout << "Tasks for Jun:" << endl;
        for (int i = 0; i < 30; ++i)
        {
            if (!jun[i].empty())
            {
                cout << "Day " << i + 1 << ": " << jun[i] << endl;
            }
        }
        cout << "Tasks for Jul:" << endl;
        for (int i = 0; i < 31; ++i)
        {
            if (!jul[i].empty())
            {
                cout << "Day " << i + 1 << ": " << jul[i] << endl;
            }
        }
        cout << "Tasks for Aug:" << endl;
        for (int i = 0; i < 31; ++i)
        {
            if (!aug[i].empty())
            {
                cout << "Day " << i + 1 << ": " << aug[i] << endl;
            }
        }
        cout << "Tasks for Sep:" << endl;
        for (int i = 0; i < 30; ++i)
        {
            if (!sep[i].empty())
            {
                cout << "Day " << i + 1 << ": " << sep[i] << endl;
            }
        }
        cout << "Tasks for Oct:" << endl;
        for (int i = 0; i < 31; ++i)
        {
            if (!oct[i].empty())
            {
                cout << "Day " << i + 1 << ": " << oct[i] << endl;
            }
        }
        cout << "Tasks for Nov:" << endl;
        for (int i = 0; i < 30; ++i)
        {
            if (!nov[i].empty())
            {
                cout << "Day " << i + 1 << ": " << nov[i] << endl;
            }
        }
        cout << "Tasks for Dec:" << endl;
        for (int i = 0; i < 31; ++i)
        {
            if (!dec[i].empty())
            {
                cout << "Day " << i + 1 << ": " << dec[i] << endl;
            }
        }
    }
};

int main()
{
    Calender cal;
    cal.adds(1, "jan");
    cal.adds(1, "feb");
    cal.adds(2, "feb");
    cal.adds(30, "jun");
    cal.display();
    cal.removes(1,"jan");
    cal.display();

}
