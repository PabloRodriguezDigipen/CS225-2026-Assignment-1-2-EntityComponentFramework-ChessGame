#include "chess_base.hh"
#include "chess_pieces.hh"

Piece::Piece(bool iswhite) {
    is_color_white = iswhite;
}

Piece::Piece(bool iswhite, int x, int y, char letter) {
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool Piece::isWhite() {
    return is_color_white;
}

PositionComponent* Piece::getPosition() {
    PositionComponent* position = dynamic_cast<PositionComponent*>(getComponent("Position"));
    return position;
}
        
VisualComponent* Piece::getVisual() {
    VisualComponent* visual = dynamic_cast<VisualComponent*>(getComponent("Visual"));
    return visual;
}

Piece::~Piece() {}



void ChessBoard::initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 2; j < BOARD_SIZE - 2; j++){
            board[i][j] = nullptr;
        }
    }

    {
        Pawn* wPawn1 = new Pawn(true, 0, 1, 'P');
        setPieceAt(wPawn1, 0, 1);
        Pawn* wPawn2 = new Pawn(true, 1, 1, 'P');
        setPieceAt(wPawn2, 1, 1);
        Pawn* wPawn3 = new Pawn(true, 2, 1, 'P');
        setPieceAt(wPawn3, 2, 1);
        Pawn* wPawn4 = new Pawn(true, 3, 1, 'P');
        setPieceAt(wPawn4, 3, 1);
        Pawn* wPawn5 = new Pawn(true, 4, 1, 'P');
        setPieceAt(wPawn5, 4, 1);
        Pawn* wPawn6 = new Pawn(true, 5, 1, 'P');
        setPieceAt(wPawn6, 5, 1);
        Pawn* wPawn7 = new Pawn(true, 6, 1, 'P');
        setPieceAt(wPawn7, 6, 1);
        Pawn* wPawn8 = new Pawn(true, 7, 1, 'P');
        setPieceAt(wPawn8, 7, 1);

        Rook* wRook1 = new Rook(true, 0, 0, 'R');
        setPieceAt(wRook1, 0, 0);
        Knight* wKnight1 = new Knight(true, 1, 0, 'N');
        setPieceAt(wKnight1, 1, 0);
        Bishop* wBishop1 = new Bishop(true, 2, 0, 'B');
        setPieceAt(wBishop1, 2, 0);
        Queen* wQueen = new Queen(true, 3, 0, 'Q');
        setPieceAt(wQueen, 3, 0);
        King* wKing = new King(true, 4, 0, 'K');
        setPieceAt(wKing, 4, 0);
        Bishop* wBishop2 = new Bishop(true, 5, 0, 'B');
        setPieceAt(wBishop2, 5, 0);
        Knight* wKnight2 = new Knight(true, 6, 0, 'N');
        setPieceAt(wKnight2, 6, 0);
        Rook* wRook2 = new Rook(true, 7, 0, 'R');
        setPieceAt(wRook2, 7, 0);



        Pawn* bPawn1 = new Pawn(false, 0, 6, 'p');
        setPieceAt(bPawn1, 0, 6);
        Pawn* bPawn2 = new Pawn(false, 1, 6, 'p');
        setPieceAt(bPawn2, 1, 6);
        Pawn* bPawn3 = new Pawn(false, 2, 6, 'p');
        setPieceAt(bPawn3, 2, 6);
        Pawn* bPawn4 = new Pawn(false, 3, 6, 'p');
        setPieceAt(bPawn4, 3, 6);
        Pawn* bPawn5 = new Pawn(false, 4, 6, 'p');
        setPieceAt(bPawn5, 4, 6);
        Pawn* bPawn6 = new Pawn(false, 5, 6, 'p');
        setPieceAt(bPawn6, 5, 6);
        Pawn* bPawn7 = new Pawn(false, 6, 6, 'p');
        setPieceAt(bPawn7, 6, 6);
        Pawn* bPawn8 = new Pawn(false, 7, 6, 'p');
        setPieceAt(bPawn8, 7, 6);

        Rook* bRook1 = new Rook(false, 0, 7, 'r');
        setPieceAt(bRook1, 0, 7);
        Knight* bKnight1 = new Knight(false, 1, 7, 'n');
        setPieceAt(bKnight1, 1, 7);
        Bishop* bBishop1 = new Bishop(false, 2, 7, 'b');
        setPieceAt(bBishop1, 2, 7);
        Queen* bQueen = new Queen(false, 3, 7, 'q');
        setPieceAt(bQueen, 3, 7);
        King* bKing = new King(false, 4, 7, 'k');
        setPieceAt(bKing, 4, 7);
        Bishop* bBishop2 = new Bishop(false, 5, 7, 'b');
        setPieceAt(bBishop2, 5, 7);
        Knight* bKnight2 = new Knight(false, 6, 7, 'n');
        setPieceAt(bKnight2, 6, 7);
        Rook* bRook2 = new Rook(false, 7, 7, 'r');
        setPieceAt(bRook2, 7, 7);
    }
}

Piece* ChessBoard::getPieceAt(int x, int y) {
    return board[x][y];
}

void ChessBoard::setPieceAt(Piece* piece, int x, int y) {
    board[x][y] = piece;
}
        
ChessBoard::~ChessBoard() {}