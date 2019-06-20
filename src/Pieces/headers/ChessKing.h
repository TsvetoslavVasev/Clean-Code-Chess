#pragma once
#include"ChessQueen.h"

class ChessKing : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessKing(char Color);
};

