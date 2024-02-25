/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 25/2/2024
*/

#include <iostream>
using namespace std;

class RenderingEngine {

public:

    void render() {
        cout << "Rendering graphics" << endl;
    }
};

class InputHandler {

public:

    void handleInput() {
        cout << "Handling input" << endl;
    }
};

class PhysicsEngine {

public:

    void simulatePhysics() {
        cout << "Simulating physics" << endl;
    }
};

class GameEngine {
    RenderingEngine *renderingEngine;
    InputHandler *inputHandler;
    PhysicsEngine *physicsEngine;

public:

    void run() {
        cout << "Starting game engine!" << endl;
        renderingEngine -> render();
        inputHandler -> handleInput();
        physicsEngine -> simulatePhysics();
        cout << "Game engine finished!" << endl;
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.run();
}
