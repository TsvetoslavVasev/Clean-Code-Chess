#pragma once
#include"ChessBishop.h"

class ChessRook : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessRook(char Color);
};

ChessRook::ChessRook(char Color) : ChessPiece(Color) {}

char ChessRook::getPiece()const
{
	return 'R';
}
bool ChessRook::areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) 
{
	if (currRow == destRow) 
	{
		// Проверяваме дали всички пресичащи се позиции преди желаната са празни
		//хоризонтален ход
		int colOffset = (destCol - currCol > 0) ? 1 : -1;
		for (int checkCol = currCol + colOffset; checkCol != destCol; checkCol = checkCol + colOffset)
		{
			if (board[currRow][checkCol] != 0) return false;
		}
		return true;
	}
	else if (destCol == currCol)
	{
		// Проверяваме дали всички пресичащи се позиции преди желаната са празни
		//вертикален ход
		int rowOffset = (destRow - currRow > 0) ? 1 : -1;
		for (int checkRow = currRow + rowOffset; checkRow != destRow; checkRow = checkRow + rowOffset) 
		{
			if (board[checkRow][currCol] != 0) return false;
		}
		return true;
	}
	return false;
}

