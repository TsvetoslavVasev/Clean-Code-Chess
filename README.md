
# Simple Chess Project for the Clean Code course at FMI

## The main logic for the pieces move and how they are recognized is in the abstract parent class ChessPiece.

## The class ChessBoard represents the 8X8 game board and is responsible for seting up the pieces on the board, alocating the dynamic memory, and deallocation of the used memory when its not needed anymore. Finally it's responsible for representing how the board look and its current state on the console.

## Finally the class ChessGame is the class that starts the game by creating a game board. It is responsible for geting the next moves, alternating the player turns, saving all the made moves in a .txt file and finally representing when one of the players won or that the game has reached a stalemate.
