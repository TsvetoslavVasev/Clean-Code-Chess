#pragma once
#include"ChessRook.h"

class ChessQueen : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessQueen(char Color);
};

ChessQueen::ChessQueen(const char Color) : ChessPiece(Color) {}
char ChessQueen::getPiece()const
{
	return 'Q';
}
bool ChessQueen::areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8])
{
	//Logic from the rook class
	if (currRow == destRow)
	{
		// Rook's vertical move which the queen uses
		int colOffset = (destCol - currCol > 0) ? 1 : -1;
		for (int checkCol = currCol + colOffset; checkCol != destCol; checkCol = checkCol + colOffset)
		{
			if (board[currRow][checkCol] != 0) return false;
		}
		return true;
	}
	else if (destCol == currCol)
	{
		// Rook's horizontal move which the queen uses
		int rowOffset = (destRow - currRow > 0) ? 1 : -1;
		for (int checkRow = currRow + rowOffset; checkRow != destRow; checkRow = checkRow + rowOffset)
		{
			if (board[checkRow][currCol] != 0) return false;
		}
		return true;
	}
	// Logic from bishop class
	else if ((destCol - currCol == destRow - currRow) || (destCol - currCol == currRow - destRow))
	{

		int rowOffset = (destRow - currRow > 0) ? 1 : -1;
		int colOffset = (destCol - currCol > 0) ? 1 : -1;
		int checkRow;
		int checkCol;
		for (checkRow = currRow + rowOffset, checkCol = currCol + colOffset;
			checkRow != destRow;
			checkRow = checkRow + rowOffset, checkCol = checkCol + colOffset)
		{
			if (board[checkRow][checkCol] != 0) return false;
		}
		return true;
	}
	return false;
}
