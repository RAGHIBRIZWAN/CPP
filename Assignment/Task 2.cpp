#include <iostream>
using namespace std;

class Table
{
    int totalSeats;
    int occupied;
    bool clean;

public:
   Table() : totalSeats(4), occupied(0), clean(true) {}

    // Parameterized constructor
    Table(int totalSeats) : totalSeats((totalSeats == 8) ? 8 : 4), occupied(0), clean(true) {}

    bool isclean()
    {
        return clean;
    }

    void occupy()
    {
        if (clean == false)
        {
            cout << "Table is dirty, No one can be seated.\n";
        }
        occupied = totalSeats;
        clean = false;
    }

    void haveLunch()
    {
        if (occupied == 0)
        {
            cout << "No one is seated at the table.\n";
            return;
        }
        else
        {
            cout << "People are eating.\n";
            clean = false;
        }
    }

    void leave()
    {
        occupied = 0;
        clean = true;
    }

    bool isFullyOccupied()
    {
        return occupied == totalSeats;
    }

    void cleanTable()
    {
        if (occupied != 0)
        {
            cout << "Table is not empty. Cannot clean.\n";
            return;
        }

        clean = true;
    }

    int getCapacity()
    {
        return totalSeats;
    }

    int getOccupiedSeats()
    {
        return occupied;
    }

    int getFreeSeats()
    {
        return totalSeats - occupied;
    }
};

void OccupyTable(Table tables[], int size, int group)
{
    for (int i = 0; i < size; i++)
    {
        if (!tables[i].isFullyOccupied() && tables[i].isclean())
        {
            tables[i].occupy();
            cout << "Group of " << group << " seated at table " << i + 1 << " (Capacity: " << tables[i].getCapacity() << ").\n";
            return;
        }
    }
    cout << "No available table for a group of " << group << ".\n";
}

void EmptyTable(Table &table)
{
    table.leave();
    cout << "Table emptied.\n";
}

int main()
{
    Table tables[5] = {Table(8), Table(8), Table(4), Table(4), Table(4)};

    OccupyTable(tables, 5, 4); // Group of 4 seated at table 1 (Capacity: 8).
    OccupyTable(tables, 5, 6);

    tables[0].haveLunch();
    tables[0].leave();
    tables[0].cleanTable();

    EmptyTable(tables[1]); 

    return 0;
}
