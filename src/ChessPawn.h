#pragma once
#include"ChessPiece.h"

class ChessPawn : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessPawn(char Color);
};
ChessPawn::ChessPawn(char Color) : ChessPiece(Color) {}
char ChessPawn::getPiece()const 
{
	return 'P';
}
bool ChessPawn::areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8])
{
	ChessPiece* Dest = board[destRow][destCol];
	if (Dest == 0)
	{
		// Ако позицията е свободна
		if (currCol == destCol)
		{
			if (getColor() == 'W')
			{
				if (destRow == currRow + 1) return true;
			}
			else 
			{
				if (destRow == currRow - 1) return true;
			}
		}
	}
	else 
	{
		//Ако позицията е заета, тоест пешката може асмо по диагонал
		if ((currCol == destCol + 1) || (currCol == destCol - 1))
		{
			if (getColor() == 'W') 
			{
				if (destRow == currRow + 1) return true;
			}
			else 
			{
				if (destRow == currRow - 1) return true;
			}
		}
	}
	return false;
}

