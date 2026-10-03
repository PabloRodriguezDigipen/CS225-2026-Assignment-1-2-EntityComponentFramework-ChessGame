#include "chess_pieces.hh"

Pawn::Pawn(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Pawn::canMoveTo(int x, int y) {
	PositionComponent* pos = getPosition();
    if (pos == nullptr)
        return false;
    
	if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

    int direction = 1;
    if (!isWhite())
        direction = -1;

	if (x == pos->getX() && y == pos->getY() + direction)
        return true;

	if ((x - 1 == pos->getX() && y == pos->getY() + direction) ||
		(x + 1 == pos->getX() && y == pos->getY() + direction))
        return true;

    if (x == pos->getX() && y == pos->getY() + 2 * direction) {
        if (isWhite() && pos->getY() == 1)
            return true;

        if (!isWhite() && pos->getY() == 6)
            return true;
    }

	return false;
}

PieceType Pawn::getType() {
 return PAWN;
}


Knight::Knight(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Knight::canMoveTo(int x, int y) {
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;


	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;

	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	if ((rowDiff + colDiff == 3 && pos->getY() != y) || (rowDiff + colDiff == 3 && pos->getX() != x))
		return true;

	return false;
}

PieceType Knight::getType() {
 return KNIGHT;
}


Bishop::Bishop(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Bishop::canMoveTo(int x, int y) {
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;

	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	if (rowDiff == colDiff && rowDiff > 0)
		return true;

	return false;
}

PieceType Bishop::getType() {
    return BISHOP;
}


Rook::Rook(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Rook::canMoveTo(int x, int y) {
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	if ((pos->getX() == x && pos->getY() != y) || (pos->getX() != x && pos->getY() == y))
		return true;

	return false;
}

PieceType Rook::getType() {
    return ROOK;
}


Queen::Queen(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Queen::canMoveTo(int x, int y) {
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;
	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	if (rowDiff == colDiff && rowDiff > 0)
		return true;

	if ((pos->getY() == y && pos->getX() != x) || (pos->getY() != y && pos->getX() == x))
		return true;
	return false;
}

PieceType Queen::getType() {
    return QUEEN;
}


King::King(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool King::canMoveTo(int x, int y) {
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;
    
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;

	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	if ((rowDiff + colDiff == 1) || (rowDiff + colDiff == 2 && pos->getX() != x && pos->getY() != y))
		return true;
	return false;
}

PieceType King::getType() {
    return KING;
}