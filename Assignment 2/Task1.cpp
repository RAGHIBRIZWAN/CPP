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
    FirewallTool(string level, int cost, int numDevices, vector<string> &Protocols) : SecurityTool(level, cost, numDevices), Protocols(Protocols) {}

    void generateList(int studentID)
    {
        int startPort = studentID + 1;          // Start from the next number
        for (int i = startPort; i < startPort + 23; ++i)
        {
            Ports.push_back(i);
        }
    }
    void performScan()
    {
        if (securityLevel == "High")
        {
            cout<<"PORTS: "<<endl;
            for (int i = 0; i < Ports.size(); i++)
            {
                cout<<Ports[i]<<endl;
            }
            cout<<"PROTOCOLS: "<<endl;
            for (int i = 0; i < Protocols.size(); i++)
            {
                cout<<Protocols[i]<<endl;
            }
            // cout << "Allowing traffic from ports and protocols list only" << endl;
        }
        else if (securityLevel == "Medium")
        {
            cout<<"PORTS: "<<endl;
            for (int i = 0; i < Ports.size(); i++)
            {   
                cout<<Ports[i]<<endl;
            }
            for (int i = Ports.size()-1; i < Ports.size(); i++)
            {
                cout<<Ports[i]+1<<endl;
            }

            cout<<"PROTOCOLS: "<<endl;
            for (int i = 0; i < Protocols.size(); i++)
            {
                cout<<Protocols[i]<<endl;
            }
            
            // cout << "Allowing traffic from ports and protocols list and next two ports in sequence" << endl;

        }
        else if (securityLevel == "Low")
        {
            cout<<"PORTS: "<<endl;
            for (int i = 0; i < Ports.size(); i++)
            {   
                cout<<Ports[i]<<endl;
            }
            for (int i = Ports.size()-1; i < Ports.size()+3; i++)
            {
                cout<<Ports[i]+1<<endl;
            }

            cout<<"PROTOCOLS: "<<endl;
            for (int i = 0; i < Protocols.size(); i++)
            {
                cout<<Protocols[i]<<endl;
            }
            // cout << "Allowing traffic from ports and protocols list and next 5 ports in sequence, TCP, and DNS protocol" << endl;
        }
    }
};

int main()
{
    vector<string> protocols = {"HTTPS", "FTP", "DNS"};
    FirewallTool fire("Medium", 100, 10, protocols);
    fire.generateList(1);
    fire.performScan();
}
