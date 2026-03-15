#include <iostream>
#include <memory>
#include <utility>
#include <vector>

enum playerColor { white, black };
enum pieceType { pawn, knight, bishop, rook, queen, king };
enum moveType { position, capture, promotion, enPassant, kingsideCastle, queensideCastle };

class Piece;

typedef int row;
typedef int col;
typedef std::pair<row, col> square;
typedef std::shared_ptr<Piece> PiecePtr;


class Piece {
public:
    pieceType type;
    playerColor color;
    square position;

    // Constructors
    Piece(pieceType type, playerColor color, square s);
    Piece(pieceType type, playerColor color, row row, col col);

    // Methods
    virtual void print(std::ostream& os) = 0;
    friend std::ostream& operator<<(std::ostream& os, PiecePtr p);
};

class Pawn : public Piece {
public:
    bool hasMoved = false;

    Pawn(pieceType type, playerColor color, square s);
    Pawn(pieceType type, playerColor color, row row, col col);
    void print(std::ostream& os);
};
class Knight : public Piece {
public:
    Knight(pieceType type, playerColor color, square s);
    Knight(pieceType type, playerColor color, row row, col col);
    void print(std::ostream& os);
};
class Bishop : public Piece {
public:
    Bishop(pieceType type, playerColor color, square s);
    Bishop(pieceType type, playerColor color, row row, col col);
    void print(std::ostream& os);
};
class Rook : public Piece {
public:
    bool hasMoved = false;

    Rook(pieceType type, playerColor color, square s);
    Rook(pieceType type, playerColor color, row row, col col);
    void print(std::ostream& os);
};
class Queen : public Piece {
public:
    Queen(pieceType type, playerColor color, square s);
    Queen(pieceType type, playerColor color, row row, col col);
    void print(std::ostream& os);
};
class King : public Piece {
public:
    bool hasMoved = false;

    King(pieceType type, playerColor color, square s);
    King(pieceType type, playerColor color, row row, col col);
    void print(std::ostream& os);
};


class Move {
public:
    moveType type;
    square start;
    square end;

    // Constructor
    Move(moveType type, square start, square end);
};


class ChessBoard {
public:
    std::vector<std::vector<PiecePtr>> board;

    std::vector<PiecePtr> whitePieces;
    std::vector<PiecePtr> blackPieces;
    PiecePtr whiteKing;
    PiecePtr blackKing;
    PiecePtr enPassantWindow = nullptr;

    std::vector<Move> whiteLegalMoves;
    std::vector<Move> blackLegalMoves;

    // Constructors
    ChessBoard();  // fill board, whitePieces, blackPieces, whiteKing, blackKing, whiteLegalMoves, blackLegalMoves
    ChessBoard(ChessBoard& b);

    // Methods
    void initializeBoard();
    void createPiece(pieceType type, playerColor color, square s);
    void movePiece(square start, square end);
    void removePiece(square s);

    void updateBoard(Move m);
    // updateBoard() helper methods
    void updatePosition(Move m);  // be sure to check if piece is Rook/King to update castle flag, and enPassantWindow
    void updateCapture(Move m);  // ^same
    void updatePromotion(Move m);
    void updateEnPassant(Move m);
    void updateKingsideCastle(Move m);  // startSquare points to WhiteKing or BlackKing
    void updateQueensideCastle(Move m);

    void updateLegalMoves(playerColor color);  // LegalMoves.clear() + for each piece calculate moves + remove illegal moves
    // updateLegalMoves() helper methods
    std::vector<Move> getPawnMoves(PiecePtr piece);
    std::vector<Move> getKnightMoves(PiecePtr piece);
    std::vector<Move> getBishopMoves(PiecePtr piece);
    std::vector<Move> getRookMoves(PiecePtr piece);
    std::vector<Move> getQueenMoves(PiecePtr piece);
    std::vector<Move> getKingMoves(PiecePtr piece);
    // more helper methods
    bool enPassantAllowed(PiecePtr piece);
    bool kingsideCastleAllowed(PiecePtr piece);
    bool queensideCastleAllowed(PiecePtr piece);

    std::vector<square> getAttackSquares(playerColor color);
    // getAttackSquares() helper methods
    std::vector<square> pawnAttackSquares(PiecePtr piece);
    std::vector<square> knightAttackSquares(PiecePtr piece);
    std::vector<square> bishopAttackSquares(PiecePtr piece);
    std::vector<square> rookAttackSquares(PiecePtr piece);
    std::vector<square> queenAttackSquares(PiecePtr piece);
    std::vector<square> kingAttackSquares(PiecePtr piece);

    bool isInCheck(playerColor color);

    friend std::ostream& operator<<(std::ostream& os, ChessBoard& cb);
};


// square operators
std::ostream& operator<<(std::ostream& os, square s) {
    std::cout << "{" << s.first << ", " << s.second << "}";
    return os;
}
bool operator==(square s1, square s2) {
    return s1.first == s2.first && s1.second == s2.second;
}



int main() {
    // initialize board
    ChessBoard b1;

    // clear board and lists for test cases
    b1.board = std::vector<std::vector<PiecePtr>>(8, std::vector<PiecePtr> (8, nullptr));
    b1.whitePieces.clear();
    b1.blackPieces.clear();


    // testing - attackedSquares (see if Rook can attack)
    b1.createPiece(king, black, {3, 7});
    b1.blackKing = b1.board[3][7];

    b1.createPiece(queen, white, {3, 0});
    std::cout << b1 << std::endl;

    
    std::cout << "b1.isInCheck(black): " << b1.isInCheck(black) << std::endl;  // 1


    return 0;
}


// Piece methods
Piece::Piece(pieceType type, playerColor color, square s) {
    this->type = type;
    this->color = color;
    this->position = s;
}
Piece::Piece(pieceType type, playerColor color, row row, col col) : Piece(type, color, {row, col}) {}

std::ostream& operator<<(std::ostream& os, PiecePtr p) {
    p->print(os);
    return os;
}


Pawn::Pawn(pieceType type, playerColor color, square s) : Piece(type, color, s) {}
Pawn::Pawn(pieceType type, playerColor color, row row, col col) : Pawn(type, color, {row, col}) {}

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

Knight::Knight(pieceType type, playerColor color, square s) : Piece(type, color, s) {}
Knight::Knight(pieceType type, playerColor color, row row, col col) : Knight(type, color, {row, col}) {}

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

Bishop::Bishop(pieceType type, playerColor color, square s) : Piece(type, color, s) {}
Bishop::Bishop(pieceType type, playerColor color, row row, col col) : Bishop(type, color, {row, col}) {}

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

Rook::Rook(pieceType type, playerColor color, square s) : Piece(type, color, s) {}
Rook::Rook(pieceType type, playerColor color, row row, col col) : Rook(type, color, {row, col}) {}

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

Queen::Queen(pieceType type, playerColor color, square s) : Piece(type, color, s) {}
Queen::Queen(pieceType type, playerColor color, row row, col col) : Queen(type, color, {row, col}) {}

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

King::King(pieceType type, playerColor color, square s) : Piece(type, color, s) {}
King::King(pieceType type, playerColor color, row row, col col) : King(type, color, {row, col}) {}

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


// Move methods
Move::Move(moveType type, square start, square end) {
    this->type = type;
    this->start = start;
    this->end = end;
}


// Board methods
ChessBoard::ChessBoard() {  // used when creating a brand new board (game first starts)
    // fill board + whitePieces + blackPieces
    initializeBoard();

    // save white king
    whiteKing = board[7][4];  // e1

    // save black king
    blackKing = board[7][3];  // d1

    // get white legal moves

    // get black legal moves
}
ChessBoard::ChessBoard(ChessBoard& chessBoard) {
    // make board DEEP copy of b
    board = std::vector<std::vector<PiecePtr>> (8, std::vector<PiecePtr> (8, nullptr));

    // copy all of chessBoard's pieces (on this->board and this->whitePieces+blackPieces)
    for (PiecePtr piece : chessBoard.whitePieces) {  // white pieces
        createPiece(piece->type, piece->color, piece->position);
        whitePieces.push_back(board[piece->position.first][piece->position.second]);
        if (piece->type == king)  // white king
            whiteKing = board[piece->position.first][piece->position.second];
    }
    for (PiecePtr piece : chessBoard.blackPieces) {  // black pieces
        createPiece(piece->type, piece->color, piece->position);
        blackPieces.push_back(board[piece->position.first][piece->position.second]);
        if (piece->type == king)  // black king
            blackKing = board[piece->position.first][piece->position.second];
    }  // TODO: find a better way to write this...

    // get white legal moves - BASED ON DEEP COPY!

    // get black legal moves - BASED ON DEEP COPY!
}

void ChessBoard::initializeBoard() {
    board = std::vector<std::vector<PiecePtr>> (8, std::vector<PiecePtr> (8, nullptr));

    // a8 - h8
    createPiece(rook, black, {0, 0});
    createPiece(knight, black, {0, 1});
    createPiece(bishop, black, {0, 2});
    createPiece(queen, black, {0, 3});
    createPiece(king, black, {0, 4});
    createPiece(bishop, black, {0, 5});
    createPiece(knight, black, {0, 6});
    createPiece(rook, black, {0, 7});

    // a7-h7
    createPiece(pawn, black, {1, 0});
    createPiece(pawn, black, {1, 1});
    createPiece(pawn, black, {1, 2});
    createPiece(pawn, black, {1, 3});
    createPiece(pawn, black, {1, 4});
    createPiece(pawn, black, {1, 5});
    createPiece(pawn, black, {1, 6});
    createPiece(pawn, black, {1, 7});

    // a2-h2
    createPiece(pawn, white, {6, 0});
    createPiece(pawn, white, {6, 1});
    createPiece(pawn, white, {6, 2});
    createPiece(pawn, white, {6, 3});
    createPiece(pawn, white, {6, 4});
    createPiece(pawn, white, {6, 5});
    createPiece(pawn, white, {6, 6});
    createPiece(pawn, white, {6, 7});

    // a1-h1
    createPiece(rook, white, {7, 0});
    createPiece(knight, white, {7, 1});
    createPiece(bishop, white, {7, 2});
    createPiece(queen, white, {7, 3});
    createPiece(king, white, {7, 4});
    createPiece(bishop, white, {7, 5});
    createPiece(knight, white, {7, 6});
    createPiece(rook, white, {7, 7});
}

void ChessBoard::createPiece(pieceType type, playerColor color, square s) {
    PiecePtr newPiece;
    switch (type) {
        case pawn:
            newPiece = std::make_shared<Pawn>(type, color, s);
            break;
        case knight:
            newPiece = std::make_shared<Knight>(type, color, s);
            break;
        case bishop:
            newPiece = std::make_shared<Bishop>(type, color, s);
            break;
        case rook:
            newPiece = std::make_shared<Rook>(type, color, s);
            break;
        case queen:
            newPiece = std::make_shared<Queen>(type, color, s);
            break;
        case king:
            newPiece = std::make_shared<King>(type, color, s);
            break;
    }
    board[s.first][s.second] = newPiece;
    switch (color) {
        case white:
            whitePieces.push_back(newPiece);
            break;
        case black:
            blackPieces.push_back(newPiece);
            break;
    }
}
void ChessBoard::movePiece(square start, square end) {
    PiecePtr piece = board[start.first][start.second];
    board[end.first][end.second] = piece;
    board[start.first][start.second] = nullptr;

    piece->position = end;
}
void ChessBoard::removePiece(square s) {
    PiecePtr piece = board[s.first][s.second];

    // remove from board
    board[s.first][s.second] = nullptr;

    // remove from pieces (list)
    int pieceIndex = 0;
    switch (piece->color) {
        case white:
            for (int p = 0; p < whitePieces.size(); p++) {
                if (piece == whitePieces[p]) {
                    pieceIndex = p;
                    break;
                }
            }
            whitePieces.erase(whitePieces.begin() + pieceIndex);
            break;
        case black:
            for (int p = 0; p < blackPieces.size(); p++) {
                if (piece == blackPieces[p]) {
                    pieceIndex = p;
                    break;
                }
            }
            blackPieces.erase(blackPieces.begin() + pieceIndex);
            break;
    }
}


void updateBoard(Move m) {}
// updateBoard() helper methods
void updatePosition(Move m) {}  // be sure to check if piece is Rook/King to update castle flag, and enPassantWindow
void updateCapture(Move m) {}  // ^same
void updatePromotion(Move m) {}
void updateEnPassant(Move m) {}
void updateKingsideCastle(Move m) {}  // startSquare points to WhiteKing or BlackKing
void updateQueensideCastle(Move m) {}


std::vector<square> ChessBoard::getAttackSquares(playerColor color) {
    std::vector<square> attackedSquares;
    switch (color) {
        case white:
            for (PiecePtr piece : whitePieces) {
                std::vector<square> attacks;
                switch (piece->type) {
                    case pawn:
                        attacks = pawnAttackSquares(piece);
                        break;
                    case knight:
                        attacks = knightAttackSquares(piece);
                        break;
                    case bishop:
                        attacks = bishopAttackSquares(piece);
                        break;
                    case rook:
                        attacks = rookAttackSquares(piece);
                        break;
                    case queen:
                        attacks = queenAttackSquares(piece);
                        break;
                    case king:
                        attacks = kingAttackSquares(piece);
                        break;
                }
                attackedSquares.insert(attackedSquares.end(), attacks.begin(), attacks.end());
            }
            break;
        case black:
            for (PiecePtr piece : blackPieces) {
                std::vector<square> attacks;
                switch (piece->type) {
                    case pawn:
                        attacks = pawnAttackSquares(piece);
                        break;
                    case knight:
                        attacks = knightAttackSquares(piece);
                        break;
                    case bishop:
                        attacks = bishopAttackSquares(piece);
                        break;
                    case rook:
                        attacks = rookAttackSquares(piece);
                        break;
                    case queen:
                        attacks = queenAttackSquares(piece);
                        break;
                    case king:
                        attacks = kingAttackSquares(piece);
                        break;
                }
                attackedSquares.insert(attackedSquares.end(), attacks.begin(), attacks.end());
            }
            break;
    }
    return attackedSquares;
}
// getAttackSquares() helper methods
std::vector<square> ChessBoard::pawnAttackSquares(PiecePtr piece) {
    std::vector<square> attackedSquares;
    square pos = piece->position;

    if (pos.second - 1 >= 0) {  // left diagonal
        PiecePtr leftDiagonal;
        switch (piece->color) {
            case white:  // white moves up
                leftDiagonal = board[pos.first - 1][pos.second - 1];  // upperLeft
                if (leftDiagonal == nullptr || leftDiagonal->color == black)
                    attackedSquares.push_back({pos.first - 1, pos.second - 1});
                break;
            case black:  // black moves down
                leftDiagonal = board[pos.first + 1][pos.second - 1];  // lowerLeft
                if (leftDiagonal == nullptr || leftDiagonal->color == white)
                    attackedSquares.push_back({pos.first + 1, pos.second - 1});
                break;
        }
    }
    if (pos.second + 1 <= 7) {  // right diagonal
        PiecePtr rightDiagonal;
        switch (piece->color) {
            case white:
                rightDiagonal = board[pos.first - 1][pos.second + 1];  // upperRight
                if (rightDiagonal == nullptr || rightDiagonal->color == black)
                    attackedSquares.push_back({pos.first - 1, pos.second + 1});
                break;
            case black:  // black moves down
                rightDiagonal = board[pos.first + 1][pos.second + 1];  // lowerRight
                if (rightDiagonal == nullptr || rightDiagonal->color == white)
                    attackedSquares.push_back({pos.first + 1, pos.second + 1});
                break;
        }
    }
    
    return attackedSquares;
}
std::vector<square> ChessBoard::knightAttackSquares(PiecePtr piece) {
    std::vector<square> attackedSquares;
    square pos = piece->position;

    if (pos.first - 2 >= 0) {  // two rows up, one col left/right
        if (pos.second - 1 >= 0) {
            PiecePtr p = board[pos.first - 2][pos.second - 1];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first - 2, pos.second - 1});
        }
        if (pos.second + 1 <= 7) {
            PiecePtr p = board[pos.first - 2][pos.second + 1];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first - 2, pos.second + 1});
        }
    }
    if (pos.first - 1 >= 0) {  // one row up, two col left/right
        if (pos.second - 2 >= 0) {
            PiecePtr p = board[pos.first - 1][pos.second - 2];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first - 1, pos.second - 2});
        }
        if (pos.second + 2 <= 7) {
            PiecePtr p = board[pos.first - 1][pos.second + 2];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first - 1, pos.second + 2});
        }
    }
    if (pos.first + 1 <= 7) {  // one row down, two col left/right
        if (pos.second - 2 >= 0) {
            PiecePtr p = board[pos.first + 1][pos.second - 2];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first + 1, pos.second - 2});
        }
        if (pos.second + 2 <= 7) {
            PiecePtr p = board[pos.first + 1][pos.second + 2];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first + 1, pos.second + 2});
        }
    }
    if (pos.first + 2 <= 7) {  // two rows down, one col left/right
        if (pos.second - 1 >= 0) {
            PiecePtr p = board[pos.first + 2][pos.second - 1];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first + 2, pos.second - 1});
        }
        if (pos.second + 1 <= 7) {
            PiecePtr p = board[pos.first + 2][pos.second + 1];
            if (p == nullptr || p->color != piece->color)
                attackedSquares.push_back({pos.first + 2, pos.second + 1});
        }
    }
    return attackedSquares;
}
std::vector<square> ChessBoard::bishopAttackSquares(PiecePtr piece) {
    std::vector<square> attackedSquares;
    square pos = piece->position;

    // check diagonal squares to see if an opponent piece is targeted
    square diag;

    // upper left
    diag = {pos.first - 1, pos.second - 1};
    while (diag.first >= 0 && diag.second >= 0) {
        if (board[diag.first][diag.second] != nullptr) {
            if (board[diag.first][diag.second]->color != piece->color)
                attackedSquares.push_back({diag.first, diag.second});
            break;
        }
        attackedSquares.push_back({diag.first, diag.second});
        diag.first--;
        diag.second--;
    }

    // upper right
    diag = {pos.first - 1, pos.second + 1};
    while (diag.first >= 0 && diag.second <= 7) {
        if (board[diag.first][diag.second] != nullptr) {
            if (board[diag.first][diag.second]->color != piece->color)
                attackedSquares.push_back({diag.first, diag.second});
            break;
        }
        attackedSquares.push_back({diag.first, diag.second});
        diag.first--;
        diag.second++;
    }

    // lower left
    diag = {pos.first + 1, pos.second - 1};
    while (diag.first <= 7 && diag.second >= 0) {
        if (board[diag.first][diag.second] != nullptr) {
            if (board[diag.first][diag.second]->color != piece->color)
                attackedSquares.push_back({diag.first, diag.second});
            break;
        }
        attackedSquares.push_back({diag.first, diag.second});
        diag.first++;
        diag.second--;
    }

    // lower right
    diag = {pos.first + 1, pos.second + 1};
    while (diag.first <= 7 && diag.second <= 7) {
        if (board[diag.first][diag.second] != nullptr) {
            if (board[diag.first][diag.second]->color != piece->color)
                attackedSquares.push_back({diag.first, diag.second});
            break;
        }
        attackedSquares.push_back({diag.first, diag.second});
        diag.first++;
        diag.second++;
    }

    return attackedSquares;
}
std::vector<square> ChessBoard::rookAttackSquares(PiecePtr piece) {
    std::vector<square> attackedSquares;
    square pos = piece->position;

    // check cardinal squares to see if an opponent piece is targeted
    square card;

    // up (north)
    card = {pos.first - 1, pos.second};
    while (card.first >= 0) {
        if (board[card.first][card.second] != nullptr) {
            if (board[card.first][card.second]->color != piece->color)
                attackedSquares.push_back({card.first, card.second});
            break;
        }
        attackedSquares.push_back({card.first, card.second});
        card.first--;
    }

    // down (south)
    card = {pos.first + 1, pos.second};
    while (card.first <= 7) {
        if (board[card.first][card.second] != nullptr) {
            if (board[card.first][card.second]->color != piece->color)
                attackedSquares.push_back({card.first, card.second});
            break;
        }
        attackedSquares.push_back({card.first, card.second});
        card.first++;
    }

    // left
    card = {pos.first, pos.second - 1};
    while (card.second >= 0) {
        if (board[card.first][card.second] != nullptr) {
            if (board[card.first][card.second]->color != piece->color)
                attackedSquares.push_back({card.first, card.second});
            break;
        }
        attackedSquares.push_back({card.first, card.second});
        card.second--;
    }

    // right
    card = {pos.first, pos.second + 1};
    while (card.second <= 7) {
        if (board[card.first][card.second] != nullptr) {
            if (board[card.first][card.second]->color != piece->color)
                attackedSquares.push_back({card.first, card.second});
            break;
        }
        attackedSquares.push_back({card.first, card.second});
        card.second++;
    }

    return attackedSquares;
}
std::vector<square> ChessBoard::queenAttackSquares(PiecePtr piece) {
    std::vector<square> attackedSquares;
    square pos = piece->position;

    // check all directions (cardinal and diagonal) for opponent pieces
    square dir;

    // up (north)
    dir = {pos.first - 1, pos.second};
    while (dir.first >= 0) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.first--;
    }

    // down (south)
    dir = {pos.first + 1, pos.second};
    while (dir.first <= 7) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.first++;
    }

    // left
    dir = {pos.first, pos.second - 1};
    while (dir.second >= 0) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.second--;
    }

    // right
    dir = {pos.first, pos.second + 1};
    while (dir.second <= 7) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.second++;
    }

    // upper left
    dir = {pos.first - 1, pos.second - 1};
    while (dir.first >= 0 && dir.second >= 0) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.first--;
        dir.second--;
    }

    // upper right
    dir = {pos.first - 1, pos.second + 1};
    while (dir.first >= 0 && dir.second <= 7) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.first--;
        dir.second++;
    }

    // lower left
    dir = {pos.first + 1, pos.second - 1};
    while (dir.first <= 7 && dir.second >= 0) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.first++;
        dir.second--;
    }

    // lower right
    dir = {pos.first + 1, pos.second + 1};
    while (dir.first <= 7 && dir.second <= 7) {
        if (board[dir.first][dir.second] != nullptr) {
            if (board[dir.first][dir.second]->color != piece->color)
                attackedSquares.push_back({dir.first, dir.second});
            break;
        }
        attackedSquares.push_back({dir.first, dir.second});
        dir.first++;
        dir.second++;
    }


    return attackedSquares;
}
std::vector<square> ChessBoard::kingAttackSquares(PiecePtr piece) {
    std::vector<square> attackedSquares;
    square pos = piece->position;

    // check all directions for opponent pieces
    if (pos.first - 1 >= 0 &&
        (board[pos.first - 1][pos.second] == nullptr ||
         board[pos.first - 1][pos.second]->color != piece->color)) {  // up
            attackedSquares.push_back({pos.first - 1, pos.second});
    }

    if (pos.first + 1 <= 7 &&
        (board[pos.first + 1][pos.second] == nullptr ||
         board[pos.first + 1][pos.second]->color != piece->color)) {  // down
            attackedSquares.push_back({pos.first + 1, pos.second});
    }

    if (pos.second - 1 >= 0 &&
        (board[pos.first][pos.second - 1] == nullptr ||
         board[pos.first][pos.second - 1]->color != piece->color)) {  // left
            attackedSquares.push_back({pos.first, pos.second - 1});
    }

    if (pos.second + 1 <= 7 &&
        (board[pos.first][pos.second + 1] == nullptr ||
         board[pos.first][pos.second + 1]->color != piece->color)) {  // right
            attackedSquares.push_back({pos.first, pos.second + 1});
    }

    if (pos.first - 1 >= 0 && pos.second - 1 >= 0 &&
        (board[pos.first - 1][pos.second - 1] == nullptr ||
         board[pos.first - 1][pos.second - 1]->color != piece->color)) {  // upper left
            attackedSquares.push_back({pos.first - 1, pos.second - 1});
    }

    if (pos.first - 1 >= 0 && pos.second + 1 <= 7 &&
        (board[pos.first - 1][pos.second + 1] == nullptr ||
         board[pos.first - 1][pos.second + 1]->color != piece->color)) {  // upper right
            attackedSquares.push_back({pos.first - 1, pos.second + 1});
    }

    if (pos.first + 1 <= 7 && pos.second - 1 >= 0 &&
        (board[pos.first + 1][pos.second - 1] == nullptr ||
         board[pos.first + 1][pos.second - 1]->color != piece->color)) {  // lower right
            attackedSquares.push_back({pos.first + 1, pos.second - 1});
    }

    if (pos.first + 1 <= 7 && pos.second + 1 <= 7 &&
        (board[pos.first + 1][pos.second + 1] == nullptr ||
         board[pos.first + 1][pos.second + 1]->color != piece->color)) {  // lower right
            attackedSquares.push_back({pos.first + 1, pos.second + 1});
    }

    return attackedSquares;
}


bool ChessBoard::isInCheck(playerColor color) {
    square kingPos;
    switch (color) {
        case white:
            kingPos = whiteKing->position;
            for (square s : getAttackSquares(black)) {
                if (kingPos == s)
                    return true;
            }
            break;
        case black:
            kingPos = blackKing->position;
            for (square s : getAttackSquares(white)) {
                if (kingPos == s)
                    return true;
            }
            break;
    }
    return false;
}


std::ostream& operator<<(std::ostream& os, ChessBoard& cb) {
    for (int row = 0; row < 8; row++) {
        os << "+---+---+---+---+---+---+---+---+" << std::endl;
        for (int col = 0; col < 8; col++) {
            std::shared_ptr<Piece> piece = cb.board[row][col];
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