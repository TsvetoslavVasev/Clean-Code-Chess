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
