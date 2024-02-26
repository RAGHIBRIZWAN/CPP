#include <iostream>
using namespace std;

class ChessPiece {
private:
    string pieceName, pieceColor;
    char pieceSymbol;

public:
    ChessPiece() {
        pieceName = "pawn", pieceColor = "white", pieceSymbol = 'P';
    }

    ChessPiece(string name, string color, char symbol) {
        pieceName = name, pieceColor = color, pieceSymbol = symbol;
    }

    void setPieceName(string name) {
        pieceName = name;
    }

    void setPieceColor(string color) {
        pieceColor = color;
    }

    void setPieceSymbol(char symbol) {
        pieceSymbol = symbol;
    }

    string getPieceName() {
        return pieceName;
    }

    string getPieceColor() {
        return pieceColor;
    }

    char getPieceSymbol() {
        return pieceSymbol;
    }

};

class ChessBoard {
public:
    ChessPiece boardPieces[8][8];

    ChessBoard() {
        for (int i = 2; i <= 5; i++) {
            for (int j = 0; j < 8; j++) {
                boardPieces[i][j] = ChessPiece("", "", '.');
            }
        }

        boardPieces[1][0] = ChessPiece("Rook", "white", 'R');
        boardPieces[1][1] = ChessPiece("Knight", "white", 'N');
        boardPieces[1][2] = ChessPiece("Bishop", "white", 'B');
        boardPieces[1][3] = ChessPiece("Queen", "white", 'Q');
        boardPieces[1][4] = ChessPiece("King", "white", 'K');
        boardPieces[1][5] = ChessPiece("Bishop", "white", 'B');
        boardPieces[1][6] = ChessPiece("Knight", "white", 'N');
        boardPieces[1][7] = ChessPiece("Rook", "white", 'R');
        
        for (int i = 0; i < 8; i++) {
            boardPieces[0][i] = ChessPiece("Pawn", "white", 'P');
        }

        boardPieces[6][0] = ChessPiece("Pawn", "black", 'p');
        boardPieces[6][1] = ChessPiece("Pawn", "black", 'p');
        boardPieces[6][2] = ChessPiece("Pawn", "black", 'p');
        boardPieces[6][3] = ChessPiece("Pawn", "black", 'p');
        boardPieces[6][4] = ChessPiece("Pawn", "black", 'p');
        boardPieces[6][5] = ChessPiece("Pawn", "black", 'p');
        boardPieces[6][6] = ChessPiece("Pawn", "black", 'p');
        boardPieces[6][7] = ChessPiece("Pawn", "black", 'p');

        boardPieces[7][0] = ChessPiece("Rook", "black", 'r');
        boardPieces[7][1] = ChessPiece("Knight", "black", 'n');
        boardPieces[7][2] = ChessPiece("Bishop", "black", 'b');
        boardPieces[7][3] = ChessPiece("Queen", "black", 'q');
        boardPieces[7][4] = ChessPiece("King", "black", 'k');
        boardPieces[7][5] = ChessPiece("Bishop", "black", 'b');
        boardPieces[7][6] = ChessPiece("Knight", "black", 'n');
        boardPieces[7][7] = ChessPiece("Rook", "black", 'r');
    }

    void movePiece(string source, string destination) {
        int sx = source[1] - '1';
        int sy = source[0] - 'a';
        int dx = destination[1] - '1';
        int dy = destination[0] - 'a';

        if (boardPieces[sx][sy].getPieceSymbol() == '.') {
            cout << "No piece at source position" << endl;
            return;
        }

        if (boardPieces[sx][sy].getPieceSymbol() != '.') {
            cout << "Valid move" << endl;
            boardPieces[dx][dy] = boardPieces[sx][sy];
            boardPieces[sx][sy] = ChessPiece("", "", '.');
            display();
        } else {
            cout << "Invalid move" << endl;
        }
    }

    void display() {
        cout << "  a b c d e f g h" << endl;
        for (int i = 0; i < 8; i++) {
            cout << i + 1 << " ";
            for (int j = 0; j < 8; j++) {
                cout << boardPieces[i][j].getPieceSymbol() << " ";
            }
            cout << endl;
        }
        cout << "  a b c d e f g h" << endl << endl;
    }
};

int main() {
    ChessBoard board;
    board.display();
    board.movePiece("a2", "a4");
    board.movePiece("a7", "a5");


    return 0;
}
