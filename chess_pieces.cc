#include "chess_pieces.hh"

//constructor sends everything to piece constructor
Pawn::Pawn(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Pawn::canMoveTo(int x, int y) {
	//get the position and check it exists
	PositionComponent* pos = getPosition();
    if (pos == nullptr)
        return false;
    
	//check the destiny is inside bounds
	if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	//determine the direction depending on the color
    int direction = 1;
    if (!isWhite())
        direction = -1;

	//1 step forward
	if (x == pos->getX() && y == pos->getY() + direction)
        return true;

	//diagonal move
	if ((x - 1 == pos->getX() && y == pos->getY() + direction) ||
		(x + 1 == pos->getX() && y == pos->getY() + direction))
        return true;

	//first step
    if (x == pos->getX() && y == pos->getY() + 2 * direction) {
		//for whites
        if (isWhite() && pos->getY() == 1)
            return true;
		//for blacks
        if (!isWhite() && pos->getY() == 6)
            return true;
    }

	//return false by default
	return false;
}

//return the pawn piece type
PieceType Pawn::getType() {
 return PAWN;
}


//constructor sends everything to piece constructor
Knight::Knight(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Knight::canMoveTo(int x, int y) {
	//get the position and check it exists
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

	//check the destiny is inside bounds
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	//calculate the difference between the current and destiny row
	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;
	//calculate the difference between the current and destiny column
	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	//if the combined difference of rows and columns is 3 and both are > 0, it is an L sahpe
	if ((rowDiff + colDiff == 3 && pos->getY() != y) || (rowDiff + colDiff == 3 && pos->getX() != x))
		return true;

	//return false by default
	return false;
}

//return the knight piece type
PieceType Knight::getType() {
 return KNIGHT;
}


//constructor sends everything to piece constructor
Bishop::Bishop(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Bishop::canMoveTo(int x, int y) {
	//get the position and check it exists
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

	//check the destiny is inside bounds
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	//calculate the difference between the current and destiny row
	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;
	//calculate the difference between the current and destiny column
	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	//if both diferences are equal and > 0, it moves diagonally
	if (rowDiff == colDiff && rowDiff > 0)
		return true;

	//return false by default
	return false;
}

//return the bishop piece type
PieceType Bishop::getType() {
    return BISHOP;
}


//constructor sends everything to piece constructor
Rook::Rook(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Rook::canMoveTo(int x, int y) {
	//get the position and check it exists
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

	//check the destiny is inside bounds
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	//if it only moves in one direction, it is a valid move
	if ((pos->getX() == x && pos->getY() != y) || (pos->getX() != x && pos->getY() == y))
		return true;

	//return false by default
	return false;
}

//return the rook piece type
PieceType Rook::getType() {
    return ROOK;
}


//constructor sends everything to piece constructor
Queen::Queen(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool Queen::canMoveTo(int x, int y) {
	//get the position and check it exists
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;

	//check the destiny is inside bounds
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	//if it only moves in one direction, it is a valid move (rook style)
	if ((pos->getX() == x && pos->getY() != y) || (pos->getX() != x && pos->getY() == y))
		return true;

	//calculate the difference between the current and destiny row
	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;
	//calculate the difference between the current and destiny column
	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	//if both diferences are equal and > 0, it moves diagonally (bishop style)
	if (rowDiff == colDiff && rowDiff > 0)
		return true;
		
	//return false by default
	return false;
}

//return the queen piece type
PieceType Queen::getType() {
    return QUEEN;
}


//constructor sends everything to piece constructor
King::King(bool iswhite, int x, int y, char letter)
    : Piece(iswhite, x, y, letter) {}

bool King::canMoveTo(int x, int y) {
	//get the position and check it exists
	const PositionComponent* pos = getPosition();
	if (!pos)
		return false;
    
	//check the destiny is inside bounds
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;

	//calculate the difference between the current and destiny row
	int rowDiff = y - pos->getY();
	if (rowDiff < 0)
		rowDiff = -rowDiff;
	//calculate the difference between the current and destiny column
	int colDiff = x - pos->getX();
	if (colDiff < 0)
		colDiff = -colDiff;

	//if the combined difference is 1, or 2, but diagonaly, it is a valid move
	if ((rowDiff + colDiff == 1) || (rowDiff + colDiff == 2 && pos->getX() != x && pos->getY() != y))
		return true;
		
	//return false by default
	return false;
}

//return the king piece type
PieceType King::getType() {
    return KING;
}