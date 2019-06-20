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
