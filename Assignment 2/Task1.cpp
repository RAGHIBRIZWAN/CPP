#include <iostream>
#include <vector>
using namespace std;

class SecurityTool
{
protected:
    string securityLevel;
    int cost;
    int numDevices;

public:
    SecurityTool(string level, int cost, int numDevices)
    {
        if (level != "High" && level != "Medium" && level != "Low")
        {
            cout << "Invalid security level";
        }
        this->securityLevel = level;

        if (cost <= 0)
        {
            cout << "Invalid cost";
        }
        this->cost = cost;

        if (numDevices <= 0)
        {
            cout << "Invalid number of devices";
        }
        this->numDevices = numDevices;
    }

    void performScan()
    {
        cout << "Performing generic security scan" << endl;
    }
};

class FirewallTool : public SecurityTool
{
    vector<int> Ports;
    vector<string> Protocols;

public:
    FirewallTool(string level, int cost, int numDevices, vector<int> &Ports, vector<string> &Protocols) : SecurityTool(level, cost, numDevices), Ports(Ports), Protocols(Protocols) {}

    void generateList(int studentID)
    {
        int digit = (studentID % 100) / 10; // Assuming studentID is at least 10 digits long
        int startPort = digit + 1;          // Start from the next number
        for (int i = startPort; i < startPort + 23; ++i)
        {
            Ports.push_back(i);
        }
    }
    void performScan()
    {
        if (securityLevel == "High")
        {
            cout << "Allowing traffic from ports and protocols list only" << endl;
        }
        else if (securityLevel == "Medium")
        {
            cout << "Allowing traffic from ports and protocols list and next two ports in sequence" << endl;
        }
        else if (securityLevel == "Low")
        {
            cout << "Allowing traffic from ports and protocols list and next 5 ports in sequence, TCP, and DNS protocol" << endl;
        }
    }
};

int main()
{
    vector<int> ports = {10, 20, 30};
    vector<string> protocols = {"HTTPS", "FTP", "DNS"};
    FirewallTool fire("High", 100, 10, ports, protocols);
    fire.performScan();
    fire.generateList(1234567891);
}
