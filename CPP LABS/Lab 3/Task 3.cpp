#include <iostream>
#include <string>
using namespace std;

class Calender {
private:
    int currentYear;
    static const int months = 12;
    static const int days = 31;
    string ans[months][days];

public:
    Calender(int year) : currentYear(year) {}

    void adds(int month, int day, string task) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid month or day!" << endl;
        } else {
            ans[month - 1][day - 1] = task;
        }
    }

    void removes(int month, int day) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid month or day!" << endl;
        } else {
            if (!ans[month - 1][day - 1].empty()) {
                ans[month - 1][day - 1] = "";
                cout << "Task deleted successfully." << endl;
            } else {
                cout << "No task exists on this day." << endl;
            }
        }
    }

    void display() {
        cout << "Tasks are:" << endl;
        for (int i = 0; i < months; i++) {
            for (int j = 0; j < days; j++) {
                if (!ans[i][j].empty()) {
                    cout << "Date: " << j + 1 << "-" << i + 1 << "-" << currentYear << ": " << ans[i][j] << endl;
                }
            }
        }
    }
};

int main() {
    Calender cal(2024);
    cal.adds(1, 1, "OOP quiz");
    cal.adds(2, 28, "MVC quiz");
    cal.display();
    cout<<"After delete"<<endl;
    cal.removes(2, 28);
    cal.adds(2, 28, "DLD quiz");
    cal.display();

    return 0;
}
