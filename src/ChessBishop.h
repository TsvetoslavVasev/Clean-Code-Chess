#pragma once
#include "ChessKnight.h"

class ChessBishop : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessBishop(char Color);
};

ChessBishop::ChessBishop(char Color) : ChessPiece(Color) {}

 char ChessBishop::getPiece()const
{
	return 'B';
}

 bool ChessBishop::areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) 
 {
	 if ((destCol - currCol == destRow - currRow) || (destCol - currCol == currRow - destRow)) 
	 {
		 //// Check if all crossed positions before the desired one are free

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
 
