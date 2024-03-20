#include<iostream>
using namespace std;

class Character {
protected:
    int health;
    int damage;

public:
    Character(int health, int damage) : health(health), damage(damage) {}

    void display() {
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
    }
};

class Enemy : public Character {
public:
    Enemy(int health, int damage) : Character(health, damage) {}

    void display() {
        cout << "Enemy:" << endl;
        Character::display();
    }
};

class Player : public Character {
public:
    Player(int health, int damage) : Character(health, damage) {}

    void display() {
        cout << "Player:" << endl;
        Character::display();
    }
};

class Wizard : public Player {
private:
    int magicPower;
    string spells;

public:
    Wizard(int health, int damage, int magicPower, string spells)
        : Player(health, damage), magicPower(magicPower), spells(spells) {}

    void display() {
        cout << "Wizard:" << endl;
        Player::display();
        cout << "Magic Power: " << magicPower << endl;
        cout << "Spells: " << spells << endl;
    }
};

int main() {
    Wizard wiz(10, 5, 20, "Hello");
    wiz.display();

    return 0;
}
