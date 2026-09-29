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

    Pawn* pawn = new Pawn(true);
    setPieceAt(pawn, 0, 0);
}

Piece* ChessBoard::getPieceAt(int x, int y) {
    return board[x][y];
}

void ChessBoard::setPieceAt(Piece* piece, int x, int y) {
    board[x][y] = piece;
}
        
ChessBoard::~ChessBoard() {}