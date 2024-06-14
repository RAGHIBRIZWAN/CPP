#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h> // For Sleep function

using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

void DisplayBoard(const vector<vector<string>> &board)
{
    // Display Board
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}


int main()
{
    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // Board
    vector<vector<string>> board(8, vector<string>(8, "."));

    string car = "^";
    string obstacle = "--";

    // Initial Position of car
    int carX = board.size() - 1;
    int carY = 0;
    board[carX][carY] = car;

    while (true)
    {
        // Clear screen
        system("CLS");

        // Move obstacles down
        for (int i = board.size() - 1; i > 0; --i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i - 1][j] == obstacle)
                {
                    board[i][j] = obstacle;
                    board[i - 1][j] = ".";
                }
            }
        }

        // Generate new obstacle at random position on the top row
        int a = rand() % 8;
        board[0][a] = obstacle;

        DisplayBoard(board);

        // Car Motion
        if (_kbhit())
        {
            char position = _getch();
            board[carX][carY] = ".";
            if (position == 'd' && carY < 7)
            {
                carY++;
            }
            else if (position == 'a' && carY > 0)
            {
                carY--;
            }
            else if (position == 'c')
            {
                return 0;
            }

            // Checking if the car hits an obstacle
            if (board[carX][carY] == obstacle)
            {
                cout << RED << "Game Over!" << RESET << endl;
                return 0;
            }

            board[carX][carY] = car; // Updating car position
        }
        Sleep(500);
    }

    return 0;
}
