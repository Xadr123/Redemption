#include <iostream>

#include "core.h"
#include "board.h"
#include "bitboards.h"

using namespace Redemption;

int main() 
{
	std::cout << "Redemption Started." << std::endl;

	Board board = Board();

	board.parseFen(StartingFEN);
	board.printBoard();

	std::cin.get();

	return 0;
}