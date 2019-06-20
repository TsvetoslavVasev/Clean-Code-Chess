#include"ChessKing.h"

ChessKing::ChessKing(const char Color) : ChessPiece(Color) {}

char ChessKing::getPiece()const
{
	return 'K';
}
bool ChessKing::areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) 
{
	int rowMove = destRow - currRow;
	int colMove = destCol - currCol;
	// Check id the move is 1-space in either direction
	if (((rowMove >= -1) && (rowMove <= 1)) &&
		((colMove >= -1) && (colMove <= 1)))
	{
		return true;
	}
	return false;
}
