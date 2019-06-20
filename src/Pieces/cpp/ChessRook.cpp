#include"ChessRook.h"

ChessRook::ChessRook(char Color) : ChessPiece(Color) {}

char ChessRook::getPiece()const
{
	return 'R';
}
bool ChessRook::areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) 
{
	if (currRow == destRow) 
	{
        // Check if all crossing positions before the wanted one are empty
        // Horizontal move
		int colOffset = (destCol - currCol > 0) ? 1 : -1;
		for (int checkCol = currCol + colOffset; checkCol != destCol; checkCol = checkCol + colOffset)
		{
			if (board[currRow][checkCol] != 0) return false;
		}
		return true;
	}
	else if (destCol == currCol)
	{
        // Check if all crossing positions before the wanted one are empty
        // Vertical move
		int rowOffset = (destRow - currRow > 0) ? 1 : -1;
		for (int checkRow = currRow + rowOffset; checkRow != destRow; checkRow = checkRow + rowOffset) 
		{
			if (board[checkRow][currCol] != 0) return false;
		}
		return true;
	}
	return false;
}

