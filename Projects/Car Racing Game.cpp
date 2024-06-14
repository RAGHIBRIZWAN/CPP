#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

void DisplayBoard(const vector<vector<string>> &board)
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void MoveObstacles(vector<vector<string>> &board, const string &obstacle)
{
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

    // Clear the first row after moving obstacles down
    for (int j = 0; j < board[0].size(); ++j)
    {
        if (board[0][j] == obstacle)
        {
            board[0][j] = ".";
        }
    }
}

bool CheckCollision(int carX, int carY, const vector<vector<string>> &board, const string &obstacle)
{
    return board[carX][carY] == obstacle;
}

void GenerateObstacle(vector<vector<string>> &board, const string &obstacle)
{
    int randomPos = rand() % 8;
    board[0][randomPos] = obstacle;
}

void MoveCar(vector<vector<string>> &board, int &carX, int &carY, const string &car)
{
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
            exit(0);
        }

        board[carX][carY] = car;
    }
}

int main()
{
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
        system("CLS");

        
        MoveObstacles(board, obstacle);

        GenerateObstacle(board, obstacle);

        if (CheckCollision(carX, carY, board, obstacle))
        {
            cout << RED << "Game Over!" << RESET << endl;
            break;
        }

        DisplayBoard(board);

        MoveCar(board, carX, carY, car);

        Sleep(500);
    }

    return 0;
}
