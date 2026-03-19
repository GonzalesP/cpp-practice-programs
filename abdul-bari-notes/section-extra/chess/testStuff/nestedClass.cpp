#include <iostream>

// class definitions - would be moved to separate header files
// (e.g., Outer.h Inner.h)
class Outer {
private:
    class Inner;
    void fun();
};

class Outer::Inner {
private:
    void nuf();
};


// main.cpp
int main() {
    return 0;
}


// class implementations
void Outer::fun() {
    std::cout << "sup" << std::endl;
}

void Outer::Inner::nuf() {
    std::cout << "sup 2" << std::endl;
}

/* general plan (?):

class chessGame {
    class chessBoard;
    class player;

    playerTurn turn;  // enum { white, black } ?
    chessBoard board;
    player White;
    player Black;
    ...
}

class chessGame::chessBoard {
}

class chessGame::player {
}

*/