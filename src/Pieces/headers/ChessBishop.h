#pragma once
#include "ChessKnight.h"

class ChessBishop : public ChessPiece
{
private:
	char getPiece()const;
	bool areSquaresLegal(int currRow, int currCol, int destRow, int destCol, ChessPiece* board[8][8]);
public:
	ChessBishop(char Color);
};

