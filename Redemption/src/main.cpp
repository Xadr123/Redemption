#include <iostream>

#include "core.h"

using namespace Redemption;

int main() 
{
	std::cout << "Redemption Started." << std::endl;

	for (Rank rank = Rank1; rank < MaxRank; ++rank)
	{
		for (File file = FileA; file < MaxFile; ++file)
		{
			Square square = fileRankToSquare(file, rank);
			std::cout << "Square " << SquareNames[square] << '\n';
		}
	}

	std::cin.get();

	return 0;
}