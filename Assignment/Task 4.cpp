#include <iostream>
using namespace std;

class RollerCoaster
{
    string name;
    int height;
    int length;
    int speed;
    int capacity;
    int currentRiders;
    bool progress;

public:
    RollerCoaster()
    {
        name = "Dragon";
        height = 500;
        length = 2000;
        capacity = 20;
        speed = 100;
        currentRiders = 0;
        progress = false;
    }

    RollerCoaster(string NAME, int hei, int len, int cap,int spe,int riders)
    {
        name = NAME;
        height = hei;
        length = len;
        capacity = cap;
        speed = spe;
        currentRiders = riders;

        if ((capacity % 2 == 0) || (capacity % 3 == 0))
        {
            cout << "Capacity is in the multiple of 2 or 3"<<endl;
            // cout<<capacity<<endl;
        }
        else if (capacity < 3)
        {
            capacity = 3;
            cout << "Capacity was less than 3"<<endl;
            // cout<<capacity<<endl;
        }
        else
        {
            capacity += 1;
            cout << "Capacity is rounded off"<<endl;
            // cout<<capacity<<endl;
        }
    }

    void setint(int hei, int len, int cap,int spe)
    {
        height = hei;
        length = len;
        capacity = cap;
        speed = spe;

        if ((capacity % 2 == 0) || (capacity % 3 == 0))
        {
            cout << "Capacity is in the multiple of 2 or 3"<<endl;
        }
        else if (capacity < 3)
        {
            capacity = 3;
            cout << "Capacity was less than 3"<<endl;
        }
        else
        {
            capacity += 1;
            cout << "Capacity is rounded off"<<endl;
        }
    }

    void setstring(string NAME)
    {
        name = NAME;
    }

    int getint()
    {
        return height;
        return length;
        return capacity;
        return speed;
    }

    string getstring()
    {
        return name;
    }

    void seated()
    {
        int riders;
        if ((progress == false) && (currentRiders != capacity))
        {
            cout << "How many riders want to be seated? "<<endl;
            cin >> riders;

            int check = currentRiders + riders;

            if (check <= capacity)
            {
                currentRiders += riders;
                cout << "All the riders are seated"<<endl;
            }
            else
            {
                for (int i = riders; i >= 0; i--)
                {
                    if (check <= capacity)
                    {
                        currentRiders += riders;
                        cout << "Riders to be seated are: " << check - capacity<<endl;
                        continue;
                    }
                    --riders;
                }
            }
        }
    }

    int startRide()
    {
        if (progress == false)
        {
            if (currentRiders == capacity)
            {
                cout << "All the seats are occupied"<<endl;
            }
            else
            {
                int extra;
                extra = capacity - currentRiders;

                cout << "The extra seats are: " << extra<<endl;
            }
            progress = true;
        }
        else
        {
            return -1;
        }
    }

    void stopRide()
    {
        if (progress == true)
        {
            progress = false;
            cout << "Ride is stopped"<<endl;
        }
        else
        {
            cout << "Ride is not in progress"<<endl;
        }
    }

    void unloadRiders()
    {
        if (progress == false)
        {
            currentRiders = 0;
            cout << "All the riders are unloaded"<<endl;
        }
        else
        {
            cout << "Ride is in Progress"<<endl;
        }
    }

    void accelerate()
    {
        int acceleration;
        cout << "To how much do you want to accelerate? "<<endl;
        cin >> acceleration;

        for (int i = 0; i < 4; i++)
        {
            if (acceleration % 10 == 0)
            {
                acceleration /= 10;
            }
            else{
                speed += acceleration;
                cout << "Speed will become after applying accelerator: "<<speed<<endl;
                break;
            }
        }
    }

    void brake()
    {
        int brake;
        cout << "To how much do you want to slow down the speed? "<<endl;
        cin >> brake;

        for (int i = 0; i < 4; i++)
        {
            if (brake % 10 == 0)
            {
                brake /= 10;
            }
            else{
                speed -= brake;
                cout << "Speed will become after applying brake: "<<speed<<endl;
                break;
            }
        }
    }
};

int main()
{
    RollerCoaster coaster1;
    RollerCoaster coaster2("Raghib",200,300,25,80,15);

    cout<<"For coaster 1:"<<endl;
    coaster1.seated();
    coaster1.startRide();
    coaster1.stopRide();
    coaster1.unloadRiders();
    coaster1.startRide();
    coaster1.accelerate();
    coaster1.brake();
    cout<<endl;

    cout<<"For coaster 2:"<<endl;
    coaster2.seated();
    coaster2.startRide();
    coaster2.stopRide();
    coaster2.unloadRiders();
    coaster2.startRide();
    coaster2.accelerate();
    coaster2.brake();

}
