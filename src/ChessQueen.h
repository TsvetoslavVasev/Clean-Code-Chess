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
	//Логика от топа
	if (currRow == destRow)
	{
		// Вертикален ход на топа, който царицата използва
		int colOffset = (destCol - currCol > 0) ? 1 : -1;
		for (int checkCol = currCol + colOffset; checkCol != destCol; checkCol = checkCol + colOffset)
		{
			if (board[currRow][checkCol] != 0) return false;
		}
		return true;
	}
	else if (destCol == currCol)
	{
		// Хоризонтален ход на топа, който царицата изпозлва
		int rowOffset = (destRow - currRow > 0) ? 1 : -1;
		for (int checkRow = currRow + rowOffset; checkRow != destRow; checkRow = checkRow + rowOffset)
		{
			if (board[checkRow][currCol] != 0) return false;
		}
		return true;
	}
	//Логика от офицера
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
