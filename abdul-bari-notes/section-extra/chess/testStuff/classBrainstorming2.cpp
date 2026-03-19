#include <iostream>
#include <vector>
#include <memory>
#include <utility>

enum playerColor { white, black };
enum pieceType { pawn, knight, bishop, rook, queen, king };
enum moveType { position, capture, kingsideCastle, queensideCastle, promotion, enPassant};

typedef int row;
typedef int col;
typedef std::vector<std::vector<std::shared_ptr<Piece>>> PiecePtrGrid;
typedef std::vector<std::shared_ptr<Piece>> PiecePtrVector;
typedef std::shared_ptr<Piece> PiecePtr;
typedef std::pair<row, col> square;


class Piece {
public:
    playerColor color;
    square position;
    Piece(playerColor, square);
    Piece(playerColor color, row r, col c) : Piece(color, {r, c}){}
    // virtual void print(std::ostream& os) = 0;
    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Piece>& p);
};

Piece::Piece(playerColor color, row r, col c) {
    this->color = color;
    position = {r, c};
}

Piece::Piece(playerColor color, square s) {
    this->color = color;
    position = s;
}

int main() {
    square s1;
    s1 = {0, 0};

    Piece p1(white, {0, 0});
    Piece p2(black, 0, 1);
    PiecePtrGrid chessBoard (8, PiecePtrVector (8, nullptr));

    return 0;
}