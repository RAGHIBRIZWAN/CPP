#include <iostream>
#include <vector>
using namespace std;

class Appliance
{
protected:
    bool isOn;
    string name;

public:
    Appliance(bool isOn, string name) : isOn(isOn), name(name) {}

    bool turnOn()
    {
        isOn = true;
        return isOn;
    }
};

class Wireless
{
protected:
    vector<string> networks;
    vector<string> passwords;
    bool isConnect;

public:
    Wireless(vector<string> networks,vector<string> passwords) : networks(networks), passwords(passwords), isConnect(true) {}

    void connect(string networkName, string password)
    {
        for (int i = 0; i < networks.size(); i++)
        {
            if (networks[i] == networkName && passwords[i] == password)
            {
                isConnect = true;
                cout << "Connected to " << networks[i] << endl;
                return;
            }
        }

        cout << "Failed to connect" << endl;
    }

    void disconnect()
    {
        isConnect = false;
        cout << "Disconnected" << endl;
    }

    bool isConnected()
    {
        return isConnect;
    }
};

class Light : public Appliance, public Wireless
{
protected:
    double brightness;

public:
    Light(bool isOn, string name, double brightness) : Appliance(isOn, name), brightness(brightness), Wireless({}, {})
    {
    }

    void changeBrightness()
    {
        if (isOn && isConnect)
        {
            string change;
            cout << "Do you want to increase or decrease brightness? ";
            cin >> change;

            if (change == "increase")
            {
                double increment;
                cout << "By how much? ";
                cin >> increment;
                if (brightness + increment <= 20)
                {
                    brightness += increment;
                    cout << "Brightness increased to " << brightness << endl;
                }
                else
                {
                    cout << "Brightness cannot exceed 20" << endl;
                }
            }
            else if (change == "decrease")
            {
                double decrement;
                cout << "By how much? ";
                cin >> decrement;
                if (brightness - decrement >= 0)
                {
                    brightness -= decrement;
                    cout << "Brightness decreased to " << brightness << endl;
                }
                else
                {
                    cout << "Brightness cannot be negative" << endl;
                }
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        else
        {
            cout << "Light is off or not connected" << endl;
        }
    }
};

class Television : public Appliance, public Wireless
{
protected:
    vector<int> channelList;

public:
    Television(bool isOn, string name, vector<int> channelList) : Appliance(isOn, name), channelList(channelList), Wireless({}, {})
    {
    }

    void changeChannel()
    {
        if (isOn && isConnect)
        {
            int newChannel;
            cout << "Enter the new channel: ";
            cin >> newChannel;

            for (int channel : channelList)
            {
                if (channel == newChannel)
                {
                    cout << "Channel changed to " << newChannel << endl;
                    return;
                }
            }

            cout << "Channel not found in the channel list" << endl;
        }
        else
        {
            cout << "Television is off or not connected" << endl;
        }
    }
};

int main()
{
    vector<string> networks = {"Network1", "Network2"};
    vector<string> passwords = {"Password1", "Password2"};

    Wireless wire(networks,passwords);
    
    Light light(true, "Light1", 10);
    light.connect("Network1", "Password1");
    light.changeBrightness();
    light.disconnect();

    vector<int> channels = {1, 2, 3, 4, 5};
    Television tv(true, "TV1", channels);
    tv.connect("Network1", "Password1");
    tv.changeChannel();
    tv.disconnect();

    return 0;
}
