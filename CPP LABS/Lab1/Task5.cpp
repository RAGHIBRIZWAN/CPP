#include <iostream>
#include <string>
using namespace std;

void display(int num, string ***arr)
{
    for (int i = 0; i < num; i++)
    {
        cout << "Name of the event " << i + 1 << ": " << *arr[i][0] << endl;
        cout << "Date of the event " << i + 1 << ": " << *arr[i][1] << endl;
        cout << "Venue of the event " << i + 1 << ": " << *arr[i][2] << endl;
        cout << "Organizer of the event " << i + 1 << ": " << *arr[i][3] << endl;
    }
}

void search(int num, string ***arr)
{
    string reqDate;

    cout << "Enter the required date: ";
    cin >> reqDate;

    for (int i = 0; i < num; i++)
    {
        if (reqDate == *arr[i][1])
        {
            cout << "Name of the event: " << *arr[i][0] << endl;
            cout << "Date of the event: " << *arr[i][1] << endl;
            cout << "Venue of the event: " << *arr[i][2] << endl;
            cout << "Organizer of the event: " << *arr[i][3] << endl;
        }
    }
}

int main()
{
    int num, opr;
    cout << "Enter the total number of events you wish to manage: ";
    cin >> num;

    string ***arr = new string **[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = new string *[4];
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = new string;
        }

        cout << "Name of the event: ";
        cin >> *arr[i][0];
        cout << "Date of the event: ";
        cin >> *arr[i][1];
        cout << "Venue of the event: ";
        cin >> *arr[i][2];
        cout << "Organizer of the event: ";
        cin >> *arr[i][3];
    }

    while (1)
    {
        cout << "1. Display details\n2. Event search\n3. Exit\n";
        cin >> opr;
        switch (opr)
        {

        case 1:
            display(num, arr);
            break;

        case 2:
            search(num, arr);
            break;

        case 3:
            // Deallocate dynamically allocated memory
            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    delete arr[i][j];
                }
                delete[] arr[i];
            }
            delete[] arr;
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
