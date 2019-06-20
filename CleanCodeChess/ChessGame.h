#pragma once
#include"ChessBoard.h"
#include<fstream>

class ChessGame
{
private:
	ChessBoard gameBoard;
	char playerTurn;
public:
	ChessGame();
	~ChessGame() {}
	void startGame();
	void getNextMove(ChessPiece* game_Board[8][8]);
	void alternateTurn();
	bool isGameOver();
};

ChessGame::ChessGame()
{
	this->playerTurn = 'W';
}

void ChessGame::startGame()
{
	do
	{
		getNextMove(this->gameBoard.myBoard);
		alternateTurn();
	} while (!isGameOver());
	gameBoard.print();
}

void ChessGame::getNextMove(ChessPiece* game_Board[8][8])
{
	bool validMove = false;
	
	do 
	{
		gameBoard.print();
		/// We get the input numbers and covert them to coordinates
		std::cout << playerTurn << "'s move: ";
		int startMove;
		std::cin >> startMove;
		int startRow = (startMove / 10) - 1;
		int startCol = (startMove % 10) - 1;

		std::cout << "To: ";
		int endMove;
		std::cin >> endMove;
		int endRow = (endMove / 10) - 1;
		int endCol = (endMove % 10) - 1;

		std::ofstream stream("Moves.txt",std::ios::app);
		stream << playerTurn << " " << (startRow + 1) << " " << (startCol + 1) << " to: " << (endRow + 1) << " " << (endCol + 1) << std::endl;
		

		// Check if the indices aren't beyond the borders of the board and if the start position and the destination are different
        if ((startRow >= 0 && startRow <= 7) &&
			(startCol >= 0 && startCol <= 7) &&
			(endCol >= 0 && endCol <= 7) &&
			(endRow >= 0 && endRow <= 7))
		{
            //Check if the two positions aren't the same
            ChessPiece* currPiece = game_Board[startRow][startCol];
            // Check if the piece is the right colour
            if ((currPiece != 0) && currPiece->getColor() == playerTurn)
            {
                // Check if the destination is valid
				if (currPiece->isLegalMove(startRow, startCol, endRow, endCol, game_Board))
				{
					ChessPiece* tempPiece = game_Board[endRow][endCol];
					game_Board[endRow][endCol] = game_Board[startRow][startCol];
					game_Board[startRow][startCol] = 0;
					// Check if the current player is in check
                    if (!gameBoard.isInCheck(playerTurn))
					{
						delete tempPiece;
						validMove = true;
					}
					else
					{
                        //We return the last move
						game_Board[startRow][startCol] = game_Board[endRow][endCol];
						game_Board[endRow][endCol] = tempPiece;
					}
				}
			}
		}
		if (!validMove)
		{
			std::cout << "Invalid move!" << "\n";
		}
	} while (!validMove);
}

void ChessGame::alternateTurn()
{
	playerTurn = (playerTurn == 'W') ? 'B' : 'W';
}

bool ChessGame::isGameOver()
{
	bool can_Move(false);
	can_Move = gameBoard.canMove(playerTurn);
	if (!can_Move)
	{
		if (gameBoard.isInCheck(playerTurn))
		{
			alternateTurn();
			std::cout << "Checkmate, " << playerTurn << " Wins!" << std::endl;
		}
		else
		{
			std::cout << "Stalemate!" << std::endl;
		}
	}
	return !can_Move;
}
