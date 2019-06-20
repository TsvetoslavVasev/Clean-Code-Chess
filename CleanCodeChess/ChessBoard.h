#pragma once
#include"ChessKing.h"

class ChessBoard
{
public:
	ChessPiece* myBoard[8][8];

	ChessBoard();
	~ChessBoard();

	void print()const;
	bool isInCheck(char color);
	bool canMove(char color);

};
ChessBoard::ChessBoard()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			myBoard[row][col] = 0;
		}
	}
	// Намираме и поставяме черните пешки
	for (int col = 0; col < 8; col++)
	{
		myBoard[6][col] = new ChessPawn('B');
	}
	myBoard[7][0] = new ChessRook('B');
	myBoard[7][1] = new ChessKnight('B');
	myBoard[7][2] = new ChessBishop('B');
	myBoard[7][3] = new ChessKing('B');
	myBoard[7][4] = new ChessQueen('B');
	myBoard[7][5] = new ChessBishop('B');
	myBoard[7][6] = new ChessKnight('B');
	myBoard[7][7] = new ChessRook('B');
	// Намираме и поставяме белите пешки
	for (int col = 0; col < 8; col++)
	{
		myBoard[1][col] = new ChessPawn('W');
	}
	myBoard[0][0] = new ChessRook('W');
	myBoard[0][1] = new ChessKnight('W');
	myBoard[0][2] = new ChessBishop('W');
	myBoard[0][3] = new ChessKing('W');
	myBoard[0][4] = new ChessQueen('W');
	myBoard[0][5] = new ChessBishop('W');
	myBoard[0][6] = new ChessKnight('W');
	myBoard[0][7] = new ChessRook('W');
}

ChessBoard::~ChessBoard()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			delete myBoard[row][col];
			myBoard[row][col] = 0;
		}
	}
}
void ChessBoard::print()const
{
	//определяме размера на квадратчетата, така че да се изпечатат симетрично
	const int squareWidth = 4;
	const int squareHeight = 3;
	for (int row = 0; row < 8 * squareHeight; row++)
	{
		int squareRow = row / squareHeight;
		// Принтираме лявата граница с цифри
		if (row % 3 == 1)
		{
			std::cout << '-' << (char)('1' + 7 - squareRow) << '-';
		}
		else 
		{
			std::cout << "---";
		}
		// Принтираме дъската
		for (int col = 0; col < 8 * squareWidth; col++)
		{
			int squareCol = col / squareWidth;
			if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && myBoard[7 - squareRow][squareCol] != 0) 
			{
				if ((col % 4) == 1)
				{
					std::cout << myBoard[7 - squareRow][squareCol]->getColor();
				}
				else
				{
					std::cout << myBoard[7 - squareRow][squareCol]->getPiece();
				}
			}
			else
			{
				if ((squareRow + squareCol) % 2 == 1) 
				{
					std::cout << '*';
				}
				else
				{
					std::cout << ' ';
				}
			}
		}
		std::cout << std::endl;
	}
	// Принтираме долната граница с цифри
	for (int row = 0; row < squareHeight; row++) 
	{
		if (row % 3 == 1) 
		{
			std::cout << "---";
			for (int col = 0; col < 8 * squareWidth; col++)
			{
				int squareCol = col / squareWidth;
				if ((col % 4) == 1)
				{
					std::cout << (squareCol + 1);
				}
				else
				{
					std::cout << '-';
				}
			}
			std::cout << std::endl;
		}
		else
		{
			for (int col = 1; col < 9 * squareWidth; col++) 
			{
				std::cout << '-';
			}
			std::cout << std::endl;
		}
	}
}

bool ChessBoard::isInCheck(char color)
{
	// Променливи, които пазят положението на царя
	int kingRow;
	int kingCol;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (myBoard[row][col] != 0)
			{
				if (myBoard[row][col]->getColor() == color)
				{
					if (myBoard[row][col]->getPiece() == 'K') 
					{
						kingRow = row;
						kingCol = col;
					}
				}
			}
		}
	}
	// Обхождаме противниковите фигури да проверим дали царя е в шасх
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (myBoard[row][col] != 0) 
			{
				if (myBoard[row][col]->getColor() != color) 
				{
					if (myBoard[kingRow][kingCol]->getPiece() == 'K' && myBoard[row][col]->isLegalMove(row, col, kingRow, kingCol, myBoard))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool ChessBoard::canMove(char color)
{
	// Oбхождаме всички фигури
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (myBoard[row][col] != 0)
			{
				//Проверка дали ако фигурата е на текучия на ход играч дали има възможен ход
				if (myBoard[row][col]->getColor() == color)
				{
					for (int moveRow = 0; moveRow < 8; moveRow++) 
					{
						for (int moveCol = 0; moveCol < 8; moveCol++) 
						{
							if (myBoard[row][col]->isLegalMove(row, col, moveRow, moveCol, myBoard))
							{
								// Правим хода ако е възможен и правим проверка дали царят е в шах
								ChessPiece* temp = myBoard[moveRow][moveCol];
								myBoard[moveRow][moveCol] = myBoard[row][col];
								myBoard[row][col] = 0;
								bool can_Move = !isInCheck(color);
								// Undo the move
								myBoard[row][col] = myBoard[moveRow][moveCol];
								myBoard[moveRow][moveCol] = temp;
								if (can_Move)return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}


