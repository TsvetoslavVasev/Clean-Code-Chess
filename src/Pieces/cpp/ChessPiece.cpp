#include"ChessPiece.h"

ChessPiece::ChessPiece(char Color) : color(Color) {}
char ChessPiece:: getColor()const
{
	return color;
}
bool ChessPiece::isLegalMove(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]) 
{
	//Dest saves the position of the desired move
	ChessPiece* Dest = board[destRow][destCol];
	if ((Dest == 0) || (color != Dest->getColor()))
	{
		return areSquaresLegal(currRow, currCol, destRow, destCol, board);
	}
	return false;
}

