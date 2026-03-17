#include <iostream>
#include <memory>
#include <utility>
#include <vector>

enum playerColor { white, black };
enum pieceType { pawn, knight, bishop, rook, queen, king };
enum moveType { position, capture, enPassant, kingsideCastle, queensideCastle };

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

    friend std::ostream& operator<<(std::ostream& os, Move& m);
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

    playerColor playerTurn = white;  // indicates whose turn it is
    bool isCopyBoard = false;  // used in the logic for checking "future board states"
        // a future board state is created by copying a board's current state and modifying it by one move
        // isCopyBoard will be used when checking if a promotion move is legal (e.g., if moving a pawn to the 8th rank
        // puts a King under check, it is illegal, so you would not want to prompt the user for a promotion choice
        // when checking this board state)
        // isCopyBoard will be updated to true whenever the copy constructor is called
            // used when parsing LegalMoves

    // Constructors
    ChessBoard();  // fill board, whitePieces, blackPieces, whiteKing, blackKing, whiteLegalMoves, blackLegalMoves
    ChessBoard(ChessBoard& b);

    // Methods
    void initializeBoard();
    void createPiece(pieceType type, playerColor color, square s);
    void movePiece(square start, square end);
    void removePiece(square s);
    void promotePiece(playerColor color, square s);

    void updateBoard(Move m);
    // updateBoard() helper methods
    void updatePosition(Move m);  // be sure to check if piece is Rook/King to update castle flag, and enPassantWindow
    void updateCapture(Move m);  // ^same
    // void updatePromotion(Move m);
        // to account for a pawn possibly capturing AND promoting at the same time, the promote process will be included
        // into the logic of updatePosition() and updateCapture()
        // furthermore, a new helper function will be used to handle the promotion logic (e.g., taking a piece type)
        // this helper function is called promotePiece(pieceType type, playerColor color, square s);
    void updateEnPassant(Move m);
    void updateKingsideCastle(Move m);  // startSquare points to WhiteKing or BlackKing
    void updateQueensideCastle(Move m);

    void updateWhiteLegalMoves();  // LegalMoves.clear() + for each piece calculate moves + remove illegal moves
    void updateBlackLegalMoves();
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
    // testing en passant and promotion
    ChessBoard b1;
    std::cout << b1 << std::endl;

    std::vector<Move> moves1;
    // moves1.push_back(Move(, {, }, {, }));
    moves1.push_back(Move(position, {6, 4}, {4, 4}));  // e4
    moves1.push_back(Move(position, {1, 3}, {3, 3}));  // d5

    moves1.push_back(Move(capture, {4, 4}, {3, 3}));  // exd5
    moves1.push_back(Move(position, {1, 4}, {3, 4}));  // e5

    moves1.push_back(Move(enPassant, {3, 3}, {2, 4}));  //dxe6 e.p.
    moves1.push_back(Move(position, {1, 0}, {2, 0}));  // a6

    moves1.push_back(Move(capture, {2, 4}, {1, 5}));  // exf7 (ignore the King check lol)
    moves1.push_back(Move(position, {1, 1}, {2, 1}));  // b6

    // new: capture and promote
    moves1.push_back(Move(capture, {1, 5}, {0, 6}));  // fxg8[Q]

    for (Move m : moves1) {
        b1.updateBoard(m);
        std::cout << b1 << std::endl;
    }


    // position and promote
    ChessBoard b2;
    std::cout << b2 << std::endl;

    std::vector<Move> moves2;
    // moves2.push_back(Move(, {, }, {, }));
    moves2.push_back(Move(position, {6, 4}, {4, 4}));  // e4
    moves2.push_back(Move(position, {1, 3}, {3, 3}));  // d5

    moves2.push_back(Move(capture, {4, 4}, {3, 3}));  // exd5
    moves2.push_back(Move(position, {1, 4}, {3, 4}));  // e5

    moves2.push_back(Move(enPassant, {3, 3}, {2, 4}));  //dxe6 e.p.
    moves2.push_back(Move(position, {1, 0}, {2, 0}));  // a6

    moves2.push_back(Move(capture, {2, 4}, {1, 5}));  // exf7
    moves2.push_back(Move(position, {0, 5}, {1, 4}));  // Be7

    // new: position and promote
    moves2.push_back(Move(position, {1, 5}, {0, 5}));  // f8[Q]

    for (Move m : moves2) {
        b2.updateBoard(m);
        std::cout << b2 << std::endl;
    }



    // testing kingside castle
    /*
    ChessBoard b2;
    std::cout << b2 << std::endl;

    std::vector<Move> moves2;
    // moves2.push_back(Move(, {, }, {, }));
    moves2.push_back(Move(position, {6, 4}, {4, 4}));  // e4
    moves2.push_back(Move(position, {1, 4}, {3, 4}));  // e5

    moves2.push_back(Move(position, {7, 5}, {6, 4}));  // Be2
    moves2.push_back(Move(position, {0, 5}, {1, 4}));  // Be7

    moves2.push_back(Move(position, {7, 6}, {5, 5}));  // Nf3
    moves2.push_back(Move(position, {0, 6}, {2, 5}));  // Nf6

    moves2.push_back(Move(kingsideCastle, {7, 4}, {7, 6}));  // O-O
    moves2.push_back(Move(kingsideCastle, {0, 4}, {0, 6}));

    b2.updateBoard(moves2[0]);  std::cout << b2 << std::endl;
    b2.updateBoard(moves2[1]);  std::cout << b2 << std::endl;
    b2.updateBoard(moves2[2]);  std::cout << b2 << std::endl;
    b2.updateBoard(moves2[3]);  std::cout << b2 << std::endl;
    b2.updateBoard(moves2[4]);  std::cout << b2 << std::endl;
    b2.updateBoard(moves2[5]);  std::cout << b2 << std::endl;

    
    b2.playerTurn = white;
    b2.updateBoard(moves2[6]);
    std::cout << b2 << std::endl;

    b2.playerTurn = black;
    b2.updateBoard(moves2[7]);
    std::cout << b2 << std::endl;
    }
    */

    // testing queenside castle
    /*
    ChessBoard b3;
    std::cout << b3 << std::endl;

    std::vector<Move> moves3;
    // moves3.push_back(Move(, {, }, {, }));
    moves3.push_back(Move(position, {6, 3}, {5, 3}));  // d3
    moves3.push_back(Move(position, {1, 3}, {2, 3}));  // d6

    moves3.push_back(Move(position, {7, 2}, {5, 4}));  // Be3
    moves3.push_back(Move(position, {0, 2}, {2, 4}));  // Be6

    moves3.push_back(Move(position, {7, 1}, {5, 2}));  // Nc3
    moves3.push_back(Move(position, {0, 1}, {2, 2}));  // Nc6

    moves3.push_back(Move(position, {7, 3}, {6, 3}));  // Qd2
    moves3.push_back(Move(position, {0, 3}, {1, 3}));  // Qd7

    moves3.push_back(Move(queensideCastle, {7, 4}, {7, 2}));  // O-O-O
    moves3.push_back(Move(queensideCastle, {0, 4}, {0, 2}));  // O-O-O

    b3.updateBoard(moves3[0]);  std::cout << b3 << std::endl;
    b3.updateBoard(moves3[1]);  std::cout << b3 << std::endl;
    b3.updateBoard(moves3[2]);  std::cout << b3 << std::endl;
    b3.updateBoard(moves3[3]);  std::cout << b3 << std::endl;
    b3.updateBoard(moves3[4]);  std::cout << b3 << std::endl;
    b3.updateBoard(moves3[5]);  std::cout << b3 << std::endl;
    b3.updateBoard(moves3[6]);  std::cout << b3 << std::endl;
    b3.updateBoard(moves3[7]);  std::cout << b3 << std::endl;


    b3.playerTurn = white;
    b3.updateBoard(moves3[8]);
    std::cout << b3 << std::endl;

    b3.playerTurn = black;
    b3.updateBoard(moves3[9]);
    std::cout << b3 << std::endl;
    */

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

std::ostream& operator<<(std::ostream& os, Move& m) {
    os << "{" << m.type << ", " << m.start << ", " << m.end << "}";
    return os;
}


// Board methods
ChessBoard::ChessBoard() {  // used when creating a brand new board (game first starts)
    // fill board + whitePieces + blackPieces
    initializeBoard();

    // save white king
    whiteKing = board[7][4];  // e1

    // save black king
    blackKing = board[0][4];  // e8

    // get white legal moves

    // get black legal moves
}
ChessBoard::ChessBoard(ChessBoard& chessBoard) {
    isCopyBoard = true;

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
void ChessBoard::promotePiece(playerColor color, square s) {  // s - endSquare (8th rank), indicates where pawn landed (and will be replaced)
    removePiece(s);  // remove the Pawn

    // get input on what piece to create: N, B, R, Q
    bool validInput = false;
    char pieceInput;
    while (!validInput) {
        try {
            std::cout << "Choose a piece type to promote to (N, B, R, Q): ";
            std::cin >> pieceInput;
            if (pieceInput != 'N' && pieceInput != 'B' && pieceInput != 'R' && pieceInput != 'Q') {
                throw 1;
            }
            validInput = true;
        }
        catch (...) {
            std::cout << "Invalid input for pawn promotion." << std::endl;
        }
    }

    // create the new piece
    switch (pieceInput) {
        case 'N':
            createPiece(knight, color, s);
            break;
        case 'B':
            createPiece(bishop, color, s);
            break;
        case 'R':
            createPiece(rook, color, s);
            break;
        case 'Q':
            createPiece(queen, color, s);
            break;
    }
}


void ChessBoard::updateBoard(Move m) {
    switch (m.type) {
        case position:
            updatePosition(m);
            break;
        case capture:
            updateCapture(m);
            break;
        // case promotion:
        //     updatePromotion(m);
        //     break;
        case enPassant:
            updateEnPassant(m);
            break;
        case kingsideCastle:
            updateKingsideCastle(m);
            break;
        case queensideCastle:
            updateQueensideCastle(m);
            break;
    }
}
// updateBoard() helper methods
void ChessBoard::updatePosition(Move m) {  // be sure to check if piece is Rook/King to update castle flag, and enPassantWindow
    // check if piece is Pawn/King/Rook for hasMoved flag
    PiecePtr piece = board[m.start.first][m.start.second];
    
    if (piece->type == pawn) {
        std::shared_ptr<Pawn> pawnPtr = std::dynamic_pointer_cast<Pawn>(piece);  // turn PiecePtr into PawnPtr
        if (pawnPtr->hasMoved == false) {
            pawnPtr->hasMoved = true;

            // if pawn moves up/down twice, it is in the enPassantWindow
            switch (pawnPtr->color) {
                case white:
                    if (m.end.first == m.start.first - 2)  // pawn moved twice -> enter ep window
                        enPassantWindow = piece;
                    else
                        enPassantWindow = nullptr;  // regular position move (pawn moves up once) -> clear window
                    break;
                case black:
                    if (m.end.first == m.start.first + 2)
                        enPassantWindow = piece;
                    else
                        enPassantWindow = nullptr;
                    break;
            }

            movePiece(m.start, m.end);
            return;  // end early to prevent clearing enPassantWindow prematurely (for pawn)
        }
    }
    else if (piece->type == rook) {
        std::shared_ptr<Rook> rookPtr = std::dynamic_pointer_cast<Rook>(piece);  // turn PiecePtr into PawnPtr
        if (rookPtr->hasMoved == false) {
            rookPtr->hasMoved = true;
        }
    }
    else if (piece->type == king) {
        std::shared_ptr<King> kingPtr = std::dynamic_pointer_cast<King>(piece);  // turn PiecePtr into PawnPtr
        if (kingPtr->hasMoved == false) {
            kingPtr->hasMoved = true;
        }
    }

    enPassantWindow = nullptr;
    movePiece(m.start, m.end);

    // check if piece was a pawn and if it landed on 1st/8th rank for promotion (row 7 or 0)
    // exception: if board is a copy board (i.e., being used to check the validity of Move m, do not call promotion)
    // promotion should only be called when a Move is executed on the actual game board (not a copy/future state board)
    if (isCopyBoard == false && std::dynamic_pointer_cast<Pawn>(piece) != nullptr) {
        switch (piece->color) {
            // white pawn promotes on 8th rank (row 0)
            case white:
                if (piece->position.first == 0)
                    promotePiece(white, piece->position);
                break;
            // black pawn promotes on 1st rank (row 7)
            case black:
                if (piece->position.first == 7)
                    promotePiece(black, piece->position);
                break;
        }
    }
}
void ChessBoard::updateCapture(Move m) {
    // check if piece is Pawn/King/Rook for hasMoved flag
    PiecePtr piece = board[m.start.first][m.start.second];

    if (piece->type == pawn) {
        std::shared_ptr<Pawn> pawnPtr = std::dynamic_pointer_cast<Pawn>(piece);  // turn PiecePtr into PawnPtr
        if (pawnPtr->hasMoved == false) {
            pawnPtr->hasMoved = true;
        }
    }
    else if (piece->type == rook) {
        std::shared_ptr<Rook> rookPtr = std::dynamic_pointer_cast<Rook>(piece);  // turn PiecePtr into PawnPtr
        if (rookPtr->hasMoved == false) {
            rookPtr->hasMoved = true;
        }
    }
    else if (piece->type == king) {
        std::shared_ptr<King> kingPtr = std::dynamic_pointer_cast<King>(piece);  // turn PiecePtr into PawnPtr
        if (kingPtr->hasMoved == false) {
            kingPtr->hasMoved = true;
        }
    }
    
    enPassantWindow = nullptr;
    removePiece(m.end);
    movePiece(m.start, m.end);

    // check if piece was a pawn and if it landed on 1st/8th rank for promotion (row 7 or 0)
    // exception: if board is a copy board (i.e., being used to check the validity of Move m, do not call promotion)
    // promotion should only be called when a Move is executed on the actual game board (not a copy/future state board)
    if (isCopyBoard == false && std::dynamic_pointer_cast<Pawn>(piece) != nullptr) {
        switch (piece->color) {
            // white pawn promotes on 8th rank (row 0)
            case white:
                if (piece->position.first == 0)
                    promotePiece(white, piece->position);
                break;
            // black pawn promotes on 1st rank (row 7)
            case black:
                if (piece->position.first == 7)
                    promotePiece(black, piece->position);
                break;
        }
    }
}
// void ChessBoard::updatePromotion(Move m) {
//     enPassantWindow = nullptr;
//     removePiece(m.start);  // remove the pawn at m.start (e.g. e7)
    
//     // get input on what piece to create: N, B, R, Q
//     bool validInput = false;
//     char pieceInput;
//     while (!validInput) {
//         try {
//             std::cout << "Choose a piece type to promote to (N, B, R, Q): ";
//             std::cin >> pieceInput;
//             if (pieceInput != 'N' && pieceInput != 'B' && pieceInput != 'R' && pieceInput != 'Q') {
//                 throw 1;
//             }
//             validInput = true;
//         }
//         catch (...) {
//             std::cout << "Invalid input for pawn promotion." << std::endl;
//         }
//     }

//     // create the new piece
//     switch (pieceInput) {
//         case 'N':
//             createPiece(knight, playerTurn, m.end);
//             break;
//         case 'B':
//             createPiece(bishop, playerTurn, m.end);
//             break;
//         case 'R':
//             createPiece(rook, playerTurn, m.end);
//             break;
//         case 'Q':
//             createPiece(queen, playerTurn, m.end);
//             break;
//     }
//     // Note to self: using the Move class to generalize player inputs
//     // may have been an oversight, because certain information is truncated
//     // (e.g., the Move class does not contain data describing what kind of piece
//     // a player may want to promote to when making a promotion move, nor does it
//     // contain data describing what color the future piece will be - which is why
//     // playerTurn had to be added to ChessBoard)
//     // something to keep in mind when designing future programs ):
// }
void ChessBoard::updateEnPassant(Move m) {  // check enPassantWindow
    enPassantWindow = nullptr;
    movePiece(m.start, m.end);  // move pawn behind captured pawn

    // captured pawn is in the SAME column (file), 1 rank below/above (depending on color) AFTER pawn moves (m.end)
    // when White uses enPassant, their pawn lands in the 6th rank (row 2) - i.e., the captured pawn was in row 3
    // when Black uses enPassant, their pawn lands in the 3rd rank (row 5) - the captured pawn was in row 4

    // remove the captured pawn based on who is using enPassant
    switch (playerTurn) {
        case white:  // captured pawn is in row 3, same column as white pawn's destination
            removePiece({3, m.end.second});
            break;
        case black:
            removePiece({4, m.end.second});
            break;
    }
}
void ChessBoard::updateKingsideCastle(Move m) {
    enPassantWindow = nullptr;

    // first, check who is using O-O. then, update the king and kingside rook (hasMoved = true). last, update the board with O-O
    std::shared_ptr<King> kingPtr;
    std::shared_ptr<Rook> rookPtr;  // kingside rook
    switch (playerTurn) {
        case white:
            kingPtr = std::dynamic_pointer_cast<King>(whiteKing);
            rookPtr = std::dynamic_pointer_cast<Rook>(board[7][7]);
            kingPtr->hasMoved = true;
            rookPtr->hasMoved = true;
            movePiece({7, 4}, {7, 6});  // white king moves two files right
            movePiece({7, 7}, {7, 5});  // rook jumps over white king
            break;
        case black:
            kingPtr = std::dynamic_pointer_cast<King>(blackKing);
            rookPtr = std::dynamic_pointer_cast<Rook>(board[0][7]);
            kingPtr->hasMoved = true;
            rookPtr->hasMoved = true;
            movePiece({0, 4}, {0, 6});  // white king moves two files right
            movePiece({0, 7}, {0, 5});  // rook jumps over white king
            break;
    }
}
void ChessBoard::updateQueensideCastle(Move m) {  // startSquare points to WhiteKing or BlackKing
    enPassantWindow = nullptr;
    
    // first, check who is using O-O. then, update the king and kingside rook (hasMoved = true). last, update the board with O-O
    std::shared_ptr<King> kingPtr;
    std::shared_ptr<Rook> rookPtr;  // kingside rook
    switch (playerTurn) {
        case white:
            kingPtr = std::dynamic_pointer_cast<King>(whiteKing);
            rookPtr = std::dynamic_pointer_cast<Rook>(board[7][0]);
            kingPtr->hasMoved = true;
            rookPtr->hasMoved = true;
            movePiece({7, 4}, {7, 2});  // white king moves two files right
            movePiece({7, 0}, {7, 3});  // rook jumps over white king
            break;
        case black:
            kingPtr = std::dynamic_pointer_cast<King>(blackKing);
            rookPtr = std::dynamic_pointer_cast<Rook>(board[0][0]);
            kingPtr->hasMoved = true;
            rookPtr->hasMoved = true;
            movePiece({0, 4}, {0, 2});  // white king moves two files right
            movePiece({0, 0}, {0, 3});  // rook jumps over white king
            break;
    }
}


void ChessBoard::updateWhiteLegalMoves() {  // LegalMoves.clear() + for each piece calculate moves + remove illegal moves
    std::vector<Move> pieceMoves;

    whiteLegalMoves.clear();
    for (PiecePtr piece : whitePieces) {
        pieceMoves.clear();
        switch (piece->type) {
            case pawn:
                pieceMoves = getPawnMoves(piece);
                break;
            case knight:
                pieceMoves = getKnightMoves(piece);
                break;
            case bishop:
                pieceMoves = getBishopMoves(piece);
                break;
            case rook:
                pieceMoves = getRookMoves(piece);
                break;
            case queen:
                pieceMoves = getQueenMoves(piece);
                break;
            case king:
                pieceMoves = getKingMoves(piece);
                break;
        }
        whiteLegalMoves.insert(whiteLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
    }
    // remove illegal moves
    for (int move = whiteLegalMoves.size() - 1; move >= 0; move--) {
        ChessBoard futureState(*this);
        futureState.updateBoard(whiteLegalMoves[move]);
        if (futureState.isInCheck(white) == true) {  // white move puts white king in check -> illegal
            whiteLegalMoves.erase(whiteLegalMoves.begin() + move);
        }
    }
}
void ChessBoard::updateBlackLegalMoves() {
    std::vector<Move> pieceMoves;

    blackLegalMoves.clear();
    for (PiecePtr piece : blackPieces) {
        pieceMoves.clear();
        switch (piece->type) {
            case pawn:
                pieceMoves = getPawnMoves(piece);
                break;
            case knight:
                pieceMoves = getKnightMoves(piece);
                break;
            case bishop:
                pieceMoves = getBishopMoves(piece);
                break;
            case rook:
                pieceMoves = getRookMoves(piece);
                break;
            case queen:
                pieceMoves = getQueenMoves(piece);
                break;
            case king:
                pieceMoves = getKingMoves(piece);
                break;
        }
        blackLegalMoves.insert(blackLegalMoves.end(), pieceMoves.begin(), pieceMoves.end());
    }
    // remove illegal moves
    for (int move = blackLegalMoves.size() - 1; move >= 0; move--) {
        ChessBoard futureState(*this);
        futureState.updateBoard(blackLegalMoves[move]);
        if (futureState.isInCheck(black) == true) {  // white move puts white king in check -> illegal
            blackLegalMoves.erase(blackLegalMoves.begin() + move);
        }
    }
}
// updateLegalMoves() helper methods
std::vector<Move> ChessBoard::getPawnMoves(PiecePtr piece) {
    std::vector<Move> moves;
    std::shared_ptr<Pawn> pawn = std::dynamic_pointer_cast<Pawn>(piece);
    square pos = pawn->position;
    switch(pawn->color) {
        case white:
            // position moves
            if (board[pos.first - 1][pos.second] == nullptr) {
                moves.push_back(Move(position, pos, {pos.first - 1, pos.second}));
                if (pawn->hasMoved == false && board[pos.first - 2][pos.second] == nullptr)
                    moves.push_back(Move(position, pos, {pos.first - 2, pos.second}));
            }
            // capture moves
            if (pos.second - 1 >= 0 &&
                board[pos.first - 1][pos.second - 1] != nullptr &&
                board[pos.first - 1][pos.second - 1]->color == black) {
                moves.push_back(Move(capture, pos, {pos.first - 1, pos.second - 1}));
            }
            if (pos.second + 1 <= 7 &&
                board[pos.first - 1][pos.second + 1] != nullptr &&
                board[pos.first - 1][pos.second + 1]->color == black) {
                moves.push_back(Move(capture, pos, {pos.first - 1, pos.second + 1}));
            }
            // enPassant
            if (enPassantAllowed(piece) == true)
                moves.push_back(Move(enPassant, pos, {pos.first - 1, enPassantWindow->position.second}));
            break;
        case black:
            // position moves
            if (board[pos.first + 1][pos.second] == nullptr) {
                moves.push_back(Move(position, pos, {pos.first + 1, pos.second}));
                if (pawn->hasMoved == false && board[pos.first + 2][pos.second] == nullptr)
                    moves.push_back(Move(position, pos, {pos.first + 2, pos.second}));
            }
            // capture moves
            if (pos.second - 1 >= 0 &&
                board[pos.first + 1][pos.second - 1] != nullptr &&
                board[pos.first + 1][pos.second - 1]->color == white) {
                moves.push_back(Move(capture, pos, {pos.first - 1, pos.second - 1}));
            }
            if (pos.second + 1 <= 7 &&
                board[pos.first + 1][pos.second + 1] != nullptr &&
                board[pos.first + 1][pos.second + 1]->color == white) {
                moves.push_back(Move(capture, pos, {pos.first - 1, pos.second + 1}));
            }
            // enPassant
            if (enPassantAllowed(piece) == true)
                moves.push_back(Move(enPassant, pos, {pos.first - 1, enPassantWindow->position.second}));
            break;
    }
    return moves;
}
std::vector<Move> ChessBoard::getKnightMoves(PiecePtr piece) {
    std::vector<Move> moves;
    square pos = piece->position;
    if (pos.first - 2 >= 0) {
        if (pos.second - 1 >= 0) {
            if (board[pos.first - 2][pos.second - 1] == nullptr)
                moves.push_back(Move(position, pos, {pos.first - 2, pos.second - 1}));
            else if (board[pos.first - 2][pos.second - 1]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first - 2, pos.second - 1}));
        }
        if (pos.second + 1 <= 7) {
            if (board[pos.first - 2][pos.second + 1] == nullptr)
                moves.push_back(Move(position, pos, {pos.first - 2, pos.second + 1}));
            else if (board[pos.first - 2][pos.second + 1]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first - 2, pos.second + 1}));
        }
    }
    if (pos.first - 1 >= 0) {
        if (pos.second - 2 >= 0) {
            if (board[pos.first - 1][pos.second - 2] == nullptr)
                moves.push_back(Move(position, pos, {pos.first - 1, pos.second - 2}));
            else if (board[pos.first - 1][pos.second - 2]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first - 1, pos.second - 2}));
        }
        if (pos.second + 2 <= 7) {
            if (board[pos.first - 1][pos.second + 2] == nullptr)
                moves.push_back(Move(position, pos, {pos.first - 1, pos.second + 2}));
            else if (board[pos.first - 1][pos.second + 2]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first - 1, pos.second + 2}));
        }
    }
    if (pos.first + 1 <= 7) {
        if (pos.second - 2 >= 0) {
            if (board[pos.first + 1][pos.second - 2] == nullptr)
                moves.push_back(Move(position, pos, {pos.first + 1, pos.second - 2}));
            else if (board[pos.first + 1][pos.second - 2]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first + 1, pos.second - 2}));
        }
        if (pos.second + 2 <= 7) {
            if (board[pos.first + 1][pos.second + 2] == nullptr)
                moves.push_back(Move(position, pos, {pos.first + 1, pos.second + 2}));
            else if (board[pos.first + 1][pos.second + 2]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first + 1, pos.second + 2}));
        }
    }
    if (pos.first + 2 <= 7) {
        if (pos.second - 1 >= 0) {
            if (board[pos.first + 2][pos.second - 1] == nullptr)
                moves.push_back(Move(position, pos, {pos.first + 2, pos.second - 1}));
            else if (board[pos.first + 2][pos.second - 1]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first + 2, pos.second - 1}));
        }
        if (pos.second + 1 <= 7) {
            if (board[pos.first + 2][pos.second + 1] == nullptr)
                moves.push_back(Move(position, pos, {pos.first + 2, pos.second + 1}));
            else if (board[pos.first + 2][pos.second + 1]->color != piece->color)
                moves.push_back(Move(capture, pos, {pos.first + 2, pos.second + 1}));
        }
    }
    return moves;
}
std::vector<Move> ChessBoard::getBishopMoves(PiecePtr piece) {
    //
}
std::vector<Move> ChessBoard::getRookMoves(PiecePtr piece) {
    //
}
std::vector<Move> ChessBoard::getQueenMoves(PiecePtr piece) {
    //
}
std::vector<Move> ChessBoard::getKingMoves(PiecePtr piece) {
    //
}

// more helper methods
bool ChessBoard::enPassantAllowed(PiecePtr piece) {
    if (enPassantWindow != nullptr && enPassantWindow->color != piece->color) {
        square epPos = enPassantWindow->position;
        if (piece->position == square{epPos.first, epPos.second - 1} || piece->position == square{epPos.first, epPos.second + 1})
            return true;
    }
    return false;
}
bool ChessBoard::kingsideCastleAllowed(PiecePtr piece) {
    //
}
bool ChessBoard::queensideCastleAllowed(PiecePtr piece) {
    //
}


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