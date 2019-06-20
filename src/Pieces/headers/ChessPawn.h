#pragma once
#include"ChessPiece.h"

class ChessPawn : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessPawn(char Color);
};

