#pragma once
#include"ChessPawn.h"

class ChessKnight : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessKnight(char Color);
};
