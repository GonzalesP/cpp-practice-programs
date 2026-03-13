#include <iostream>
#include <vector>
#include <memory>

enum playerColor { white, black };

class Piece {
public:
    playerColor color;
    int row;
    int col;
    Piece(playerColor, int, int);
    virtual void print(std::ostream& os) = 0;
    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Piece>& p);
};

class Pawn : public Piece {
public:
    Pawn(playerColor, int, int);  // : Piece(color, row, col);
    void print(std::ostream& os);
};

class Knight : public Piece {
public:
    Knight(playerColor, int, int);
    void print(std::ostream& os);
};

class Bishop : public Piece {
public:
    Bishop(playerColor, int, int);
    void print(std::ostream& os);
};

class Rook : public Piece {
public:
    Rook(playerColor, int, int);
    void print(std::ostream& os);
};

class Queen : public Piece {
public:
    Queen(playerColor, int, int);
    void print(std::ostream& os);
};

class King : public Piece {
public:
    King(playerColor, int, int);
    void print(std::ostream& os);
};

std::vector<std::vector<std::shared_ptr<Piece>>> chessBoard (8, std::vector<std::shared_ptr<Piece>> (8, nullptr));

std::ostream& operator<<(std::ostream& os, std::shared_ptr<Piece>& p) {
    p->print(os);
    return os;
}
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<std::shared_ptr<Piece>>>& board) {
    for (int row = 0; row < 8; row++) {
        os << "+---+---+---+---+---+---+---+---+" << std::endl;
        for (int col = 0; col < 8; col++) {
            std::shared_ptr<Piece> piece = board[row][col];
            if (piece == nullptr)
                os << "|   ";
            else
                os << "| " << piece << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
    return os;
}

Piece::Piece(playerColor color, int row, int col) {
    this->color = color;
    this->row = row;
    this->col = col;
}

Pawn::Pawn(playerColor color, int row, int col) : Piece(color, row, col) {
    //
}

Knight::Knight(playerColor color, int row, int col) : Piece(color, row, col) {
    //
}

Bishop::Bishop(playerColor color, int row, int col) : Piece(color, row, col) {
    //
}

Rook::Rook(playerColor color, int row, int col) : Piece(color, row, col) {
    //
}

Queen::Queen(playerColor color, int row, int col) : Piece(color, row, col) {
    //
}

King::King(playerColor color, int row, int col) : Piece(color, row, col) {
    //
}

void Pawn::print(std::ostream& os) {
    switch(color) {
        case white:
            os << "P";
            break;
        case black:
            os << "p";
            break;
    }
}

void Knight::print(std::ostream& os) {
    switch(color) {
        case white:
            os << "N";
            break;
        case black:
            os << "n";
            break;
    }
}

void Bishop::print(std::ostream& os) {
    switch(color) {
        case white:
            os << "B";
            break;
        case black:
            os << "b";
            break;
    }
}

void Rook::print(std::ostream& os) {
    switch(color) {
        case white:
            os << "R";
            break;
        case black:
            os << "r";
            break;
    }
}

void Queen::print(std::ostream& os) {
    switch(color) {
        case white:
            os << "Q";
            break;
        case black:
            os << "q";
            break;
    }
}

void King::print(std::ostream& os) {
    switch(color) {
        case white:
            os << "K";
            break;
        case black:
            os << "k";
            break;
    }
}

template <typename T>
void createPiece(int row, int col, playerColor color) {
    chessBoard[row][col] = std::make_shared<T>(color, row, col);
}

void movePiece(int startRow, int startCol, int endRow, int endCol) {
    std::shared_ptr<Piece> piece = chessBoard[startRow][startCol];
    chessBoard[endRow][endCol] = piece;
    chessBoard[startRow][startCol] = nullptr;
}

void removePiece(int targetRow, int targetCol) {
    chessBoard[targetRow][targetCol] = nullptr;
}

void initializeBoard() {
    // a8-h8
    createPiece<Rook>(0, 0, black);
    createPiece<Knight>(0, 1, black);
    createPiece<Bishop>(0, 2, black);
    createPiece<Queen>(0, 3, black);
    createPiece<King>(0, 4, black);
    createPiece<Bishop>(0, 5, black);
    createPiece<Knight>(0, 6, black);
    createPiece<Rook>(0, 7, black);

    // a7-h7
    createPiece<Pawn>(1, 0, black);
    createPiece<Pawn>(1, 1, black);
    createPiece<Pawn>(1, 2, black);
    createPiece<Pawn>(1, 3, black);
    createPiece<Pawn>(1, 4, black);
    createPiece<Pawn>(1, 5, black);
    createPiece<Pawn>(1, 6, black);
    createPiece<Pawn>(1, 7, black);

    // a2-h2
    createPiece<Pawn>(6, 0, white);
    createPiece<Pawn>(6, 1, white);
    createPiece<Pawn>(6, 2, white);
    createPiece<Pawn>(6, 3, white);
    createPiece<Pawn>(6, 4, white);
    createPiece<Pawn>(6, 5, white);
    createPiece<Pawn>(6, 6, white);
    createPiece<Pawn>(6, 7, white);

    // a1-h1
    createPiece<Rook>(7, 0, white);
    createPiece<Knight>(7, 1, white);
    createPiece<Bishop>(7, 2, white);
    createPiece<Queen>(7, 3, white);
    createPiece<King>(7, 4, white);
    createPiece<Bishop>(7, 5, white);
    createPiece<Knight>(7, 6, white);
    createPiece<Rook>(7, 7, white);
}



int main() {
    initializeBoard();

    std::cout << chessBoard << std::endl;

    movePiece(6, 4, 4, 4);

    std::cout << chessBoard << std::endl;

    removePiece(7, 7);

    std::cout << chessBoard << std::endl;

    return 0;
}