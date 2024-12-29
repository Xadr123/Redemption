#include "bitboards.h"

namespace Redemption
{
	namespace Bitboards
	{
		Bitboard pawnAttacks[MaxColor][MaxSquare]{};
		Bitboard knightAttacks[MaxSquare]{};
		Bitboard kingAttacks[MaxSquare]{};

		void printBitboard(Bitboard bits)
		{
			std::cout << '\n' << "  +---+---+---+---+---+---+---+---+" << '\n';

			for (Rank rank = Rank8; rank >= Rank1; --rank)
			{
				std::cout << 1 + rank;

				for (File file = FileA; file < MaxFile; ++file)
				{
					Square square{ fileRankToSquare(file, rank) };
					char bit{ checkBit(bits, square) ? 'X' : ' ' };
					std::cout << " | " << bit;
				}
				std::cout << " | " << '\n' << "  +---+---+---+---+---+---+---+---+" << '\n';

			}
			std::cout << "    a   b   c   d   e   f   g   h" << std::endl;
		}

		void initBitboards()
		{
			for (Square square = A1; square < MaxSquare; ++square)
			{
				pawnAttacks[White][square] = generatePawnAttacks(White, square);
				pawnAttacks[Black][square] = generatePawnAttacks(Black, square);
				knightAttacks[square] = generateKnightAttacks(square);
				kingAttacks[square] = generateKingAttacks(square);
			}
		}
	}
}