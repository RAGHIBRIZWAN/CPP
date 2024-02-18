#include <iostream>
#include <vector>
using namespace std;

class pet
{
protected:
    string healthStatus;
    int hungerLevel = 5;
    int happinessLevel = 5;
    int num1;
    string skills[10];

public:
    void addskills()
    {
        cout << "How many skills you want to add? " << endl;
        cin >> num1;
        for (int i = 0; i < num1; i++)
        {
            cout << "Skill: " << i + 1 << endl;
            cin >> skills[i];
        }
    }

    void displayPetDetails()
    {
        cout << "Health Status of pet is: " << healthStatus << endl;
        cout << "Hunger Level of pet is: " << hungerLevel << endl;
        cout << "Happiness Level of pet is: " << happinessLevel << endl;
        for (int i = 0; i < num1; i++)
        {
            cout << "Skill: " << i + 1 << endl;
            cout << skills[i] << endl;
        }
    }

    bool updateHappiness(bool feed)
    {

        if (happinessLevel != 10)
        {
            if (feed = true)
            {
                happinessLevel++;
                cout << "Happiness level right now is: " << happinessLevel << endl;
            }
            else
            {
                happinessLevel--;
                cout << "Happiness level right now is: " << happinessLevel << endl;
            }
        }

        else
        {
            cout << "Happiness level is already 10" << endl;
        }
    }

    void updateHunger()
    {
        hungerLevel++;
        cout << "Hunger Level Upgraded" << endl;
    }

    void updateHealth()
    {
        if (hungerLevel >= 7)
        {
            healthStatus = "Sick";
            cout << "The health status of your pet is: " << healthStatus << endl;
        }
        else
        {
            healthStatus = "Healthy";
            cout << "The health status of your pet is: " << healthStatus << endl;
        }
    }
};

class Adopter : public pet
{
    string adopterName;
    string adopterMobileNum;
    int num2;
    vector<string> records;

public:
    Adopter(string adopterName, string adopterMobileNum) : adopterName(adopterName), adopterMobileNum(adopterMobileNum) {}

    void adoptPet()
    {
        string pet;
        cout << "How many pets do you want to adopt? ";
        cin >> num2;

        for (int i = 0; i < num2; i++)
        {
            cout << "Name the pet " << i + 1<<endl;
            cin >> pet;
            records.push_back(pet);
        }
    }

    void returnPet()
    {
        string pet;
        cout << "Which Pet do you want to return? ";
        cin >> pet;

        for (int i = 0; i < num2; i++)
        {
            if (records[i] == pet)
            {
                records[i] = "";
            }
        }
    }

    void displayPets()
    {
        for (int i = 0; i < num2; i++)
        {
            if (!records[i].empty())
            {
                cout << "Pet Number: " << i + 1 << endl;
                cout << "Species is: " << records[i] << endl;
                cout << "Health Status is: " << healthStatus << endl;
                cout << "Hunger Level is: " << hungerLevel << endl;
                cout << "Happiness Level is: " << happinessLevel << endl;
            }
        }
    }
};

int main()
{
    Adopter adopt("Raghib", "03340030844");
    adopt.addskills();
    adopt.displayPetDetails();
    cout << "After Updation: "<<endl;
    adopt.updateHunger();
    adopt.updateHappiness(true);
    adopt.updateHealth();
    adopt.displayPetDetails();
    cout << "AGAIN Updation: "<<endl;
    adopt.updateHunger();
    adopt.updateHappiness(true);
    adopt.updateHealth();
    adopt.displayPetDetails();
    cout << "Adopter class started"<<endl;
    adopt.adoptPet();
    adopt.displayPets();
    adopt.returnPet();
    cout << "Display after returning dog"<<endl;
    adopt.displayPets();
}
