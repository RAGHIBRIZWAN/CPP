#include <iostream>
using namespace std;

class Position {
protected:
    double x, y, z;

public:
    Position(double x, double y, double z) : x(x), y(y), z(z) {}

    void displayPosition() {
        cout << "Position: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Health {
protected:
    int health;

public:
    Health(int health) : health(health) {}

    void displayHealth() {
        cout << "Health: " << health << endl;
    }
};

class Character : public Position, public Health {
private:
    string name;

public:
    Character(string name, double x, double y, double z, int health)
        : Position(x, y, z), Health(health), name(name) {}

    void displayCharacter() {
        cout << "Character: " << name << endl;
        displayPosition();
        displayHealth();
    }

    void move(double newX, double newY, double newZ) {
        x = newX;
        y = newY;
        z = newZ;
        cout << name << " moved to (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        cout << name << " took " << damage << " damage." << endl;
        if (health <= 0) {
            cout << name << " has been defeated." << endl;
        } else {
            cout << name << " now has " << health << " health remaining." << endl;
        }
    }
};

int main() {
    Character character("Hero", 0, 0, 0, 100);

    character.displayCharacter();

    character.move(10, 10, 10);

    character.displayPosition();

    character.takeDamage(20);

    character.displayHealth();
    
    return 0;
}
