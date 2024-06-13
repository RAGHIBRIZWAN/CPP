#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
using namespace std;

void DisplayBoard(vector<vector<string>> &board)
{
    // Display Board
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    //Board
    vector<vector<string>> board = {
        {".", ".", ".", ".", "."},
        {".", ".", ".", ".", "."},
        {".", ".", ".", ".", "."},
        {".", ".", ".", ".", "."},
        {".", ".", ".", ".", "."}};
    string apple = "o";
    string snake = "--";
    bool checkSnake = false;
    bool checkApple = false;
    int score = 0;

    // Controls
    char a = 'a';
    char w = 'w';
    char s = 's';
    char d = 'd';
    char position;
    int snakeX = 0, snakeY = 0;

    // Initial Position of snake
    board[0][0] = snake;
    DisplayBoard(board);

    while (1)
    {
        // Apple Position
        while (!checkApple) {
            int a = rand() % 5;
            int b = rand() % 5;
            if (board[a][b] == ".") {
                board[a][b] = apple;
                checkApple = true;
            }
        }

        DisplayBoard(board);
        // Snake Motion
        if(_kbhit){
            position = _getch();
            board[snakeX][snakeY] = ".";
            if (position == 'd' && snakeY < 4 && board[snakeX][snakeY + 1] != snake) {
                snakeY++;
            } else if (position == 'w' && snakeX > 0 && board[snakeX - 1][snakeY] != snake) {
                snakeX--;
            } else if (position == 'a' && snakeY > 0 && board[snakeX][snakeY - 1] != snake) {
                snakeY--;
            } else if (position == 's' && snakeX < 4 && board[snakeX + 1][snakeY] != snake) {
                snakeX++;
            }
            else if(position == 'c'){
                cout<<score;
                return 0;
            }
            // Checking if the snake eats the apple
            if (board[snakeX][snakeY] == apple) {
                score++;
                checkApple = false;
            }
            board[snakeX][snakeY] = snake; // Updating snake position
            system("CLS");
        }
    }
}
