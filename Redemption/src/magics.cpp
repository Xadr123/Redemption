#include "magics.h"

namespace Redemption
{
	namespace Magics
	{
		Bitboard bishopMasks[MaxSquare];
		Bitboard rookMasks[MaxSquare];
		Bitboard bishopAttacks[64][512];
		Bitboard rookAttacks[64][4096];

		void initMagics()
		{
			for (Square square = A1; square < MaxSquare; ++square)
			{
				bishopMasks[square] = generateBishopAttackMask(square);
				rookMasks[square] = generateRookAttackMask(square);

				initBishopAttacks(square);
				initRookAttacks(square);
			}
		}

		void initBishopAttacks(Square square)
		{
			Bitboard attacks = bishopMasks[square];
			int bitCount = Bitboards::popCount(attacks);
			int occupancies = 1 << bitCount;

			for (int index = 0; index < occupancies; ++index)
			{
				Bitboard occupancy = setOccupancy(index, attacks, bitCount);
				Bitboard magicIndex = (occupancy * bishopMagics[square]) >> (64 - relevantBishopBits[square]);
				bishopAttacks[square][magicIndex] = generateBishopAttacks(square, occupancy);
			}
		}

		void initRookAttacks(Square square)
		{
			Bitboard attacks = rookMasks[square];
			int bitCount = Bitboards::popCount(attacks);
			int occupancies = 1 << bitCount;

			for (int index = 0; index < occupancies; ++index)
			{
				Bitboard occupancy = setOccupancy(index, attacks, bitCount);
				Bitboard magicIndex = (occupancy * rookMagics[square]) >> (64 - relevantRookBits[square]);
				rookAttacks[square][magicIndex] = generateRookAttacks(square, occupancy);
			}
		}
	}
}