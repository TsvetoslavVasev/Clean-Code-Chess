#pragma once
#include<iostream>

class ChessPiece
{
private:
	virtual bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) = 0;
	char color;
public:
	ChessPiece(char Color);
	virtual char getPiece()const = 0;
	char getColor()const;
	bool isLegalMove(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
};
