#pragma once
#include "chess_base.hh"

//pawn class
class Pawn : public Piece{
public:
    Pawn(bool iswhite, int x, int y, char letter);
    //override inherited functions
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

//knight class
class Knight : public Piece{
public:
    Knight(bool iswhite, int x, int y, char letter);
    //override inherited functions
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

//bishop class
class Bishop : public Piece{
public:
    Bishop(bool iswhite, int x, int y, char letter);
    //override inherited functions
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

//rook class
class Rook : public Piece{
public:
    Rook(bool iswhite, int x, int y, char letter);
    //override inherited functions
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

//queen class
class Queen : public Piece{
public:
    Queen(bool iswhite, int x, int y, char letter);
    //override inherited functions
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

//king class
class King : public Piece{
public:
    King(bool iswhite, int x, int y, char letter);
    //override inherited functions
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};