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
    ChessBoard();
    ChessBoard(ChessBoard& b);

    // Methods
    void initializeBoard();  // fill board, whitePieces, blackPieces, whiteKing, blackKing, whiteLegalMoves, blackLegalMoves
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


int main() {
    ChessBoard b1;

    std::cout << "A" << std::endl;
    std::cout << b1 << std::endl;

    // update b1
    b1.movePiece({6, 4}, {4, 4});
    std::cout << "B" << std::endl;
    std::cout << b1 << std::endl;

    b1.movePiece({1, 3}, {3, 3});
    std::cout << "C" << std::endl;
    std::cout << b1 << std::endl;

    // remove piece

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


// Board
ChessBoard::ChessBoard() {
    // fill board
    initializeBoard();

    // record white pieces - should probably make an initializeWhitePieces() method
    whitePieces.push_back(board[6][0]);  // a2-h2
    whitePieces.push_back(board[6][1]);
    whitePieces.push_back(board[6][2]);
    whitePieces.push_back(board[6][3]);
    whitePieces.push_back(board[6][4]);
    whitePieces.push_back(board[6][5]);
    whitePieces.push_back(board[6][6]);
    whitePieces.push_back(board[6][7]);
    whitePieces.push_back(board[7][0]);  // a1-h1
    whitePieces.push_back(board[7][1]);
    whitePieces.push_back(board[7][2]);
    whitePieces.push_back(board[7][3]);
    whitePieces.push_back(board[7][4]);
    whitePieces.push_back(board[7][5]);
    whitePieces.push_back(board[7][6]);
    whitePieces.push_back(board[7][7]);

    // record black pieces
    blackPieces.push_back(board[0][0]);  // a8-h8
    blackPieces.push_back(board[0][1]);
    blackPieces.push_back(board[0][2]);
    blackPieces.push_back(board[0][3]);
    blackPieces.push_back(board[0][4]);
    blackPieces.push_back(board[0][5]);
    blackPieces.push_back(board[0][6]);
    blackPieces.push_back(board[0][7]);
    blackPieces.push_back(board[1][0]);  // a7-h7
    blackPieces.push_back(board[1][1]);
    blackPieces.push_back(board[1][2]);
    blackPieces.push_back(board[1][3]);
    blackPieces.push_back(board[1][4]);
    blackPieces.push_back(board[1][5]);
    blackPieces.push_back(board[1][6]);
    blackPieces.push_back(board[1][7]);

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
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            PiecePtr piece = chessBoard.board[row][col];
            if (piece != nullptr) {
                createPiece(piece->type, piece->color, piece->position);  // copy all piece positions
                switch (piece->color) {
                    case white:
                        whitePieces.push_back(board[row][col]);  // record white pieces
                        break;
                    case black:
                        blackPieces.push_back(board[row][col]);  // record black pieces
                        break;
                }
                if (piece->type == king) {
                    switch (piece->color) {
                        case white:
                            whiteKing = board[row][col];  // save white king
                            break;
                        case black:
                            blackKing = board[row][col];  // save black king
                            break;
                    }
                }
            }
        }
    }

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
    switch (type) {
        case pawn:
            board[s.first][s.second] = std::make_shared<Pawn>(type, color, s);
            break;
        case knight:
            board[s.first][s.second] = std::make_shared<Knight>(type, color, s);
            break;
        case bishop:
            board[s.first][s.second] = std::make_shared<Bishop>(type, color, s);
            break;
        case rook:
            board[s.first][s.second] = std::make_shared<Rook>(type, color, s);
            break;
        case queen:
            board[s.first][s.second] = std::make_shared<Queen>(type, color, s);
            break;
        case king:
            board[s.first][s.second] = std::make_shared<King>(type, color, s);
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
    // remove from board
    // remove from pieces (list)
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