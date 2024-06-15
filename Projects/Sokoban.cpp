#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;

void DisplayBoard(vector<vector<string>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void map1(vector<vector<string>> &board, const string &player, const string &ball, const string &wall, const string &target)
{
    board[0][2] = player;
    board[1][1] = ball;
    board[1][4] = target;

    for (int i = 3; i < 4; i++)
    {
        board[0][i] = wall;
    }
    board[1][2] = wall;
    for (int i = 3; i < 4; i++)
    {
        board[2][i] = wall;
    }
}

void movePlayer(vector<vector<string>> &board, int &Px, int &Py, int &Bx, int &By, const string &player, const string &wall, const string &ball, const string &target)
{
    if (_kbhit())
    {
        char ch = _getch();
        int newPx = Px, newPy = Py;
        int newBx = Bx, newBy = By;

        if (ch == 'd' && Py < 6 && (board[Px][Py + 1] == "." || board[Px][Py + 1] == ball))
        {
            newPy++;
            if (board[Px][newPy] == ball && newPy < 6 && (board[Px][newPy + 1] == "." || board[Px][newPy + 1] == target))
            {
                if(board[Px][newPy + 1] == target){
                    newBy++;
                    cout<<"You win!";
                    exit(0);
                }
                newBy++;
            }
        }
        else if (ch == 'a' && Py > 0 && (board[Px][Py - 1] == "." || board[Px][Py - 1] == ball))
        {
            newPy--;
            if (board[Px][newPy] == ball && newPy > 0 && (board[Px][newPy - 1] == "." || board[Px][newPy - 1] == target))
            {
                if(board[Px][newPy - 1] == target){
                    newBy--;
                    cout<<"You win!";
                    exit(0);
                }
                newBy--;
            }
        }
        else if (ch == 'w' && Px > 0 && (board[Px - 1][Py] == "." || board[Px - 1][Py] == ball))
        {
            newPx--;
            if (board[newPx][Py] == ball && newPx > 0 && (board[newPx - 1][Py] == "." || board[newPx - 1][Py] == target))
            {
                if(board[newPx - 1][Py] == target){
                    newBx--;
                    cout<<"You win!";
                    exit(0);
                }
                newBx--;
            }
        }
        else if (ch == 's' && Px < board.size() - 1 && (board[Px + 1][Py] == "." || board[Px + 1][Py] == ball))
        {
            newPx++;
            if (board[newPx][Py] == ball && newPx < board.size() - 1 && (board[newPx + 1][Py] == "." || board[newPx + 1][Py] == target))
            {
                if(board[newPx + 1][Py] == target){
                    newBx++;
                    cout<<"You win!";
                    exit(0);
                }
                newBx++;
            }
        }
        else if (ch == 'c')
        {
            exit(0);
        }

        if (board[newPx][newPy] != wall && (newPx != newBx || newPy != newBy || (newBx == newPx && newBy == newPy)))
        {
            board[Px][Py] = ".";
            board[Bx][By] = ".";
            Px = newPx;
            Py = newPy;
            Bx = newBx;
            By = newBy;
            board[Px][Py] = player;
            board[Bx][By] = ball;
        }
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    vector<vector<string>> board(5, vector<string>(7, "."));
    string player = "P";
    string ball = "O";
    string wall = "|";
    string target = "T";
    int playerX = 0;
    int playerY = 2;
    int ballX = 1;
    int ballY = 1;

    map1(board, player, ball, wall, target);

    while (true)
    {
        system("cls");
        DisplayBoard(board);
        movePlayer(board, playerX, playerY, ballX, ballY, player, wall, ball, target);
        Sleep(500);
    }

    return 0;
}
