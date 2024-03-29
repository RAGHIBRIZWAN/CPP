#include <iostream>
#include <vector>
using namespace std;

class Player
{
    int playerID;
    string playerName;
    int health;

public:
    Player() {}
    Player(int playerID, string playerName, int health) : playerID(playerID), playerName(playerName), health(health) {}

    int getHealthPlayer()
    {
        return health;
    }

    void setHealthPlayer(int newHealth)
    {
        health = newHealth;
    }
};

class Weapon
{
    vector<string> weapons;

public:
    Weapon()
    {
        weapons = {"Sword", "Axe", "Bow", "Dagger", "Staff"};
    }

    void use()
    {
        string item;
        cout << "Which weapon do you want to use? " << endl;
        cin >> item;

        bool found = false;
        for (const string &weapon : weapons)
        {
            if (weapon == item)
            {
                found = true;
                cout << "The weapon that is chosen is: " << item << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Invalid weapon choice" << endl;
        }
    }
};

class Enemy;

class Character : public Player
{
    int level;
    string experience;
    int points;

public:
    Character(int playerID, string playerName, int health, int level, string experience) : Player(playerID, playerName, health), level(level), experience(experience), points(0) {}

    void levelUp()
    {
        points += 10;
        if (points >= 10)
        {
            level++;
            if (experience == "Beginner")
            {
                experience = "Intermediate";
                cout << experience;
            }
            else if (experience == "Intermediate")
            {
                experience = "Advanced";
                cout << experience;
            }
            else if (experience == "Advanced")
            {
                experience = "Expert";
                cout << experience;
            }
            points = 0;
        }
    }

    void playGame(Enemy &enemy)
    {
        Weapon weapon;
        weapon.use();
        points += 10;
        enemy.sethealthEnemy(enemy.gethealthEnemy()-5);

    }
};

class Enemy:public Player
{
protected:
    int health;
    int damage;

public:
    Enemy() {}
    Enemy(int damage,int health) : damage(damage),health(health) {}

    int gethealthEnemy(){
        return health;
    }

    void sethealthEnemy(int newHealth){
        health = newHealth;
    }

    void attack()
    {
        int newHealth = getHealthPlayer()-damage;
        setHealthPlayer(newHealth);
    }
};

int main()
{
    Character player1(1, "Player1", 100, 0, "Beginner");
    Enemy enemy(10,100);

    player1.playGame(enemy);
    enemy.attack();
    player1.levelUp();

    return 0;
}
