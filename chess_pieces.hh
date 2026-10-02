#pragma once
#include "chess_base.hh"

class Pawn : public Piece{
public:
    Pawn(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Knight : public Piece{
public:
    Knight(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Bishop : public Piece{
public:
    Bishop(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Rook : public Piece{
public:
    Rook(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Queen : public Piece{
public:
    Queen(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class King : public Piece{
public:
    King(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};