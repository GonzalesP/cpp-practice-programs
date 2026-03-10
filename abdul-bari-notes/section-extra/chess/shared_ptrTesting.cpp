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
        ranks, std::vector<std::shared_ptr<Piece>> (files)
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

    for (std::vector<std::shared_ptr<Piece>>& rank : chessBoard) {
        for (std::shared_ptr<Piece>& p : rank)
            p->print();
    }

    return 0;
}