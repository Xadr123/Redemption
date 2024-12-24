#pragma once

#include <bit>

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

		constexpr Bitboard squareBitboard(Square square)
		{
			return static_cast<Bitboard>(1ULL << square);
		}

		constexpr Square lsb(Bitboard bits)
		{
			return static_cast<Square>(std::countr_zero(bits));
		}

		constexpr Square popLsb(Bitboard& bits)
		{
			const Square square = lsb(bits);

			bits &= bits - 1;

			return square;
		}

		constexpr int popCount(Bitboard& bits)
		{
			return std::popcount(bits);
		}

		constexpr void setBit(Bitboard& bits, Square square)
		{
			bits |= squareBitboard(square);
		}

		constexpr bool checkBit(Bitboard& bits, Square square)
		{
			return (bits & squareBitboard(square)) != 0;
		}
	}
}