#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <conio.h>
#include <ctime>
using namespace std;

bool isDraw(const vector<vector<string>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell.empty()) return false;
        }
    }
    return true;
}

int main()
{
    string ans;
    bool check = true;
    vector<vector<string>> board = {
        {"", "", ""},
        {"", "", ""},
        {"", "", ""},
    };
    string player1, player2;
    cout << "Choose for Player 1: X or O" << endl;
    cin >> player1;

    while (check)
    {
        if (player1 == "X")
        {
            player2 = "O";
        }
        else if (player1 == "O")
        {
            player2 = "X";
        }
        
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ""  && board[i][1] != "" && board[i][2] != "")
            {
                check = false;
                ans = board[i][0];

                if (ans == player1)
                {
                    cout << "player1 Wins";
                }
                else
                {
                    cout << "Player2 Wins";
                }
                return 0;
            }
            else if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != "" && board[1][i] != "" && board[2][i] != ""){
                check = false;
                ans = board[0][i];

                if (ans == player1)
                {
                    cout << "player1 Wins";
                }
                else
                {
                    cout << "Player2 Wins";
                }
                return 0;
            }
            else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != "" && board[1][1] != "" && board[2][2] != ""){
                check = false;
                ans = board[0][0];

                if (ans == player1)
                {
                    cout << "player1 Wins";
                }
                else
                {
                    cout << "Player2 Wins";
                }
                return 0;
            }
            else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != "" && board[1][1] != "" && board[2][0] != ""){
                check = false;
                ans = board[0][2];

                if (ans == player1)
                {
                    cout << "player1 Wins";
                }
                else
                {
                    cout << "Player2 Wins";
                }
                return 0;
            }
            else if(isDraw(board)){
                cout<<"Game Draw";
                return 0;
            }
            else{
                break;
            }
        }
        
        int choose1, choose2;
        cout << "Select Position for player1: ";
        cin >> choose1 >> choose2;

        board[choose1][choose2] = player1;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                cout << board[i][j] << "     |";
            }
            cout << endl;
        }
        
        cout << "Select Position for player2: ";
        cin >> choose1 >> choose2;

        board[choose1][choose2] = player2;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                cout << board[i][j] << "     |";
            }
            cout << endl;
        }
    }
}
