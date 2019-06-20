#pragma once
#include"ChessPawn.h"

class ChessKnight : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessKnight(char Color);
};

ChessKnight::ChessKnight(char Color) : ChessPiece(Color) {}

char ChessKnight::getPiece()const
{
	return 'N';
}
bool ChessKnight::areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) 
{
	// In the case of the knight it does not matter if the desired position is taken or not because it does not change the movement
	if ((currCol == destCol + 1) || (currCol == destCol - 1))
	{
		if ((currRow == destRow + 2) || (currRow == destRow - 2)) return true;
	}
	if ((currCol == destCol + 2) || (currCol == destCol - 2)) 
	{
		if ((currRow == destRow + 1) || (currRow == destRow - 1)) return true;
	}
	return false;
}
