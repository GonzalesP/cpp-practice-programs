#include <iostream>
#include <vector>
#include <memory>

class Base {
public:
    virtual void print() = 0;
};

class DerivedA : public Base {
public:
    void print() { std::cout << "DerivedA" << std::endl; }
};

class DerivedB : public Base {
public:
    void print() { std::cout << "DerivedB" << std::endl; }
};



class Piece {
public:
    virtual void print() = 0;
};

class Pawn : public Piece {
public:
    void print() { std::cout << "Pawn" << std::endl; }
};

class Knight : public Piece {
public:
    void print() { std::cout << "Knight" << std::endl; }
};

class Bishop : public Piece {
public:
    void print() { std::cout << "Bishop" << std::endl; }
};

class Rook : public Piece {
public:
    void print() { std::cout << "Rook" << std::endl; }
};

class Queen : public Piece {
public:
    void print() { std::cout << "Queen" << std::endl; }
};

class King : public Piece {
public:
    void print() { std::cout << "King" << std::endl; }
};

int main() {
    std::shared_ptr<Base> p;
    p = std::make_shared<DerivedA>();

    p->print();



    const int ranks = 8;  // rank 1-8
    const int files = 8;  // file A-H

    std::vector<std::vector<std::shared_ptr<Piece>>> chessBoard(
        ranks, std::vector<std::shared_ptr<Piece>> (files, nullptr)
    );

    // a8 - h8
    chessBoard[0][0] = std::make_shared<Rook>();
    chessBoard[0][1] = std::make_shared<Knight>();
    chessBoard[0][2] = std::make_shared<Bishop>();
    chessBoard[0][3] = std::make_shared<Queen>();
    chessBoard[0][4] = std::make_shared<King>();
    chessBoard[0][5] = std::make_shared<Bishop>();
    chessBoard[0][6] = std::make_shared<Knight>();
    chessBoard[0][7] = std::make_shared<Rook>();

    std::vector<std::shared_ptr<Piece>> playerPieces;
    playerPieces.push_back(chessBoard[0][0]);
    playerPieces.push_back(chessBoard[0][1]);
    playerPieces.push_back(chessBoard[0][2]);
    playerPieces.push_back(chessBoard[0][3]);
    playerPieces.push_back(chessBoard[0][4]);
    playerPieces.push_back(chessBoard[0][5]);
    playerPieces.push_back(chessBoard[0][6]);
    playerPieces.push_back(chessBoard[0][7]);

    std::cout << std::endl << "chessBoard" << std::endl;
    for (std::vector<std::shared_ptr<Piece>>& rank : chessBoard) {
        for (std::shared_ptr<Piece>& ptr : rank) {
            if (ptr != nullptr) {
                ptr->print();
                std::cout << "ptr: " << ptr << std::endl;
                std::cout << "&ptr: " << &ptr << std::endl;
            }
        }
    }

    std::cout << std::endl << "playerPieces" << std::endl;
    for (std::shared_ptr<Piece>& ptr : playerPieces) {
        ptr->print();
        std::cout << "ptr: " << ptr << std::endl;
        std::cout << "&ptr: " << &ptr << std::endl;
    }

    return 0;
}

// cannot use unique_ptr if you're going to store Piece in two containers
// one reference to a Piece may exist in chessBoard (2D Vector)
    // (e.g., chessBoard[0][0] points to the Rook on a8)
// and another reference to the same Piece may exist
// in a player's pieces (1D Vector)
    // (e.g., playerPieces[0] points to the Rook on a8, same as chessBoard)

// so, the trade off is that we don't use unique_ptr in order to store
// multiple references to the same object. and the benefit of having a separate
// container for playerPieces is that when calculating a player's moves,
// it is easier to inspect their pieces independently (n pieces) rather
// than inspecting the entire board (n^2 pieces)