#pragma once

#include <iostream>

#include "core.h"

namespace Redemption
{
	namespace Bitboards
	{
		constexpr Bitboard bbFileA = 0x0101010101010101ULL;
		constexpr Bitboard bbFileB = 0x0202020202020202ULL;
		constexpr Bitboard bbFileC = 0x0404040404040404ULL;
		constexpr Bitboard bbFileD = 0x0808080808080808ULL;
		constexpr Bitboard bbFileE = 0x1010101010101010ULL;
		constexpr Bitboard bbFileF = 0x2020202020202020ULL;
		constexpr Bitboard bbFileG = 0x4040404040404040ULL;
		constexpr Bitboard bbFileH = 0x8080808080808080ULL;

		constexpr Bitboard bbRank1 = 0x00000000000000FFULL;
		constexpr Bitboard bbRank2 = 0x000000000000FF00ULL;
		constexpr Bitboard bbRank3 = 0x0000000000FF0000ULL;
		constexpr Bitboard bbRank4 = 0x00000000FF000000ULL;
		constexpr Bitboard bbRank5 = 0x000000FF00000000ULL;
		constexpr Bitboard bbRank6 = 0x0000FF0000000000ULL;
		constexpr Bitboard bbRank7 = 0x00FF000000000000ULL;
		constexpr Bitboard bbRank8 = 0xFF00000000000000ULL;

		constexpr Bitboard bbNotFileA = 0xFEFEFEFEFEFEFEFEULL;
		constexpr Bitboard bbNotFileH = 0x7F7F7F7F7F7F7F7FULL;
		constexpr Bitboard bbNotFileAB = 0xFCFCFCFCFCFCFCFCULL;
		constexpr Bitboard bbNotFileGH = 0x3F3F3F3F3F3F3F3FULL;

		extern Bitboard pawnAttacks[MaxColor][MaxSquare];
		extern Bitboard knightAttacks[MaxSquare];
		extern Bitboard kingAttacks[MaxSquare];

		void printBitboard(Bitboard bits);

		void initBitboards();

		constexpr Bitboard squareBitboard(Square square)
		{
			return static_cast<Bitboard>(1ULL << square);
		}

		constexpr Square lsb(Bitboard bits)
		{
			if (bits == 0) { return OffBoard; }

			i16 count{};

			while ((bits & 1) == 0)
			{
				++count;
				bits >>= 1;
			}

			return static_cast<Square>(count);
		}

		constexpr Square popLsb(Bitboard& bits)
		{
			const Square square = lsb(bits);

			bits &= bits - 1;

			return square;
		}

		constexpr int popCount(Bitboard bits)
		{
			bits -= (bits >> 1) & 0x5555555555555555ULL;
			bits = (bits & 0x3333333333333333ULL) + ((bits >> 2) & 0x3333333333333333ULL);
			bits = (bits + (bits >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
			return ((bits * 0x0101010101010101ULL) >> 56);
		}

		constexpr void setBit(Bitboard& bits, Square square)
		{
			bits |= squareBitboard(square);
		}

		constexpr bool checkBit(Bitboard& bits, Square square)
		{
			return (bits & squareBitboard(square)) != 0;
		}

		constexpr Bitboard shiftDirection(Bitboard bits, Direction direction)
		{
			switch (direction)
			{
			case North: return bits << 8;
			case South: return bits >> 8;
			case East: return (bits & bbNotFileH) << 1;
			case West: return (bits & bbNotFileA) >> 1;
			case NorthEast: return (bits & bbNotFileH) << 9;
			case NorthWest: return (bits & bbNotFileA) << 7;
			case SouthEast: return (bits & bbNotFileH) >> 7;
			case SouthWest: return (bits & bbNotFileA) >> 9;
			default: return 0ULL;
			}
		}

		constexpr Bitboard generatePawnAttacks(Color color, Square square)
		{
			assert(isValidSquare(square));
			assert(color < MaxColor);

			if (color == White)
			{
				return (shiftDirection(squareBitboard(square), NorthWest) | shiftDirection(squareBitboard(square), NorthEast));
			}
			else
			{
				return (shiftDirection(squareBitboard(square), SouthWest) | shiftDirection(squareBitboard(square), SouthEast));
			}
		}

		constexpr Bitboard generateKnightAttacks(Square square)
		{
			assert(isValidSquare(square));

			Bitboard attacks = 0ULL;

			attacks |= (squareBitboard(square) << 17) & bbNotFileA;
			attacks |= (squareBitboard(square) << 15) & bbNotFileH;
			attacks |= (squareBitboard(square) << 10) & bbNotFileAB;
			attacks |= (squareBitboard(square) << 6) & bbNotFileGH;
			attacks |= (squareBitboard(square) >> 17) & bbNotFileH;
			attacks |= (squareBitboard(square) >> 15) & bbNotFileA;
			attacks |= (squareBitboard(square) >> 10) & bbNotFileGH;
			attacks |= (squareBitboard(square) >> 6) & bbNotFileAB;

			return attacks;
		}

		constexpr Bitboard generateKingAttacks(Square square)
		{
			assert(isValidSquare(square));

			Bitboard attacks = 0ULL;

			attacks |= (squareBitboard(square) << 9) & bbNotFileA;
			attacks |= squareBitboard(square) << 8;
			attacks |= (squareBitboard(square) << 7) & bbNotFileH;
			attacks |= (squareBitboard(square) << 1) & bbNotFileA;
			attacks |= (squareBitboard(square) >> 9) & bbNotFileH;
			attacks |= squareBitboard(square) >> 8;
			attacks |= (squareBitboard(square) >> 7) & bbNotFileA;
			attacks |= (squareBitboard(square) >> 1) & bbNotFileH;

			return attacks;
		}
	}
}
