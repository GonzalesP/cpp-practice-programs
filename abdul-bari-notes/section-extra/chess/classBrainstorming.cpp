#include <iostream>
#include <vector>
#include <memory>

enum color { white, black };

class ChessGame {
private:
    class Board;
    class Piece;
    class Move;
    class Player;

    std::unique_ptr<Player> white;
    std::unique_ptr<Player> black;
    std::unique_ptr<Board> board;
public:
    color turn;  // white or black's turn to move
};

class ChessGame::Board {
public:
    std::vector<std::vector<std::shared_ptr<Piece>>> board;
    void printBoard();  // add overloaded function too
    void movePiece(/*start, destination*/);
    void removePiece(/*target*/);
};
class ChessGame::Piece {
public:
    color color;
    int row;  // maybe use typedef std::pair<int, int> square;
    int col;  // and square position;
    virtual void printPiece() = 0;  // add overloaded function too
};
class ChessGame::Player {
public:
    color color;
    std::vector<std::shared_ptr<Piece>> pieces;
    std::vector<std::shared_ptr<Piece>> getPieces();
    std::shared_ptr<Piece> king;
};
class ChessGame::Move {};



int main() {
    return 0;
}