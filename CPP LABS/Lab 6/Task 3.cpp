#include<iostream>
using namespace std;

class Appointment{
    static int appointments;
    static int earnings;

public:
    static void AddAppointment(int numAppointments, int totalEarnings) {
        appointments += numAppointments;
        earnings += totalEarnings;
    }

    static int Calculate(){
        if (appointments == 0) {
            return 0;
        }
        return earnings / appointments;
    }

};

int Appointment::appointments = 0;
int Appointment::earnings = 0;

int main(){
    Appointment::AddAppointment(3, 5000);
    Appointment::AddAppointment(2, 3000);

    cout << "Average cost per appointment: $" << Appointment::Calculate() << endl;

    return 0;
}
