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

ChessPiece::ChessPiece(char Color) : color(Color) {}
char ChessPiece:: getColor()const
{
	return color;
}
bool ChessPiece::isLegalMove(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) 
{
	//Dest пази позицията на желания код
	ChessPiece* Dest = board[destRow][destCol];
	if ((Dest == 0) || (color != Dest->getColor()))
	{
		return areSquaresLegal(currRow, currCol, destRow, destCol, board);
	}
	return false;
}

