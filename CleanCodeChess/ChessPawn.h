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
		// Logic in case the desired position is free
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
		// Logic if the position is not available. The pawn can move only diagonal
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

