#pragma once

#include "core.h"
#include "bitboards.h"

namespace Redemption
{
	namespace Magics
	{
		constexpr Bitboard bishopMagics[MaxSquare] =
		{
			0x4050020801003200ULL, 0x20080140408000ULL, 0x14082981000002ULL, 0x8108208020201051ULL, 0x41104010a40000ULL, 0x842482004000920ULL, 0x1390088a088145cULL, 0x890044040c094410ULL,
			0x10900408082040ULL, 0x800081008c08900ULL, 0x84860481020601f0ULL, 0xa41042100007ULL, 0x4009011040904009ULL, 0x20c20804042000ULL, 0x8000020101884102ULL, 0x20862601042000ULL,
			0x2428004031440090ULL, 0x10420304011404ULL, 0x8081011021002100ULL, 0x48a8005686094000ULL, 0x24085480a00082ULL, 0x800206a10042010ULL, 0x800410005a080400ULL, 0x20800200440280ULL,
			0x144013a0230400ULL, 0x201100048422800ULL, 0x4001010810084200ULL, 0x800a0800140050a0ULL, 0x4000840008802000ULL, 0x848820221080200ULL, 0x8040840021015800ULL, 0x200101000020880cULL,
			0xc012010e82a1000ULL, 0x204108200808218cULL, 0x405001080020ULL, 0x101600800010104ULL, 0xc0020200002080ULL, 0x420401080c1000ULL, 0x4010010042491410ULL, 0xcc330200004041ULL,
			0x4040440800400ULL, 0x212011088008240ULL, 0x4100210040408800ULL, 0x400082214002800ULL, 0x2040201c10104300ULL, 0x1230200800440020ULL, 0x18980a0404480400ULL, 0x2004480049000240ULL,
			0x2144040402081000ULL, 0x22021080804202cULL, 0x2040182108088120ULL, 0xc250010908480008ULL, 0x4184200420820400ULL, 0xd0041002420100ULL, 0x20e02240810424ULL, 0x20820421112302ULL,
			0x4021005a202000ULL, 0x800048044022006ULL, 0x302031107a29000ULL, 0x810200081020880cULL, 0x1200120105a0600ULL, 0x2912c21020c10100ULL, 0x4441400222240120ULL, 0x4008811002004901ULL
		};

		constexpr Bitboard rookMagics[MaxSquare] =
		{
			0x1880008622400010ULL, 0x280200081400010ULL, 0x4200084600108020ULL, 0x500100024582100ULL, 0x380080024000b80ULL, 0x5100010002c40008ULL, 0x20020a804012200ULL, 0x9600064100608402ULL,
			0x2002081084200ULL, 0x104802000804000ULL, 0x40100200100104aULL, 0x3202001200220840ULL, 0x5001100040800ULL, 0x1008800200800400ULL, 0x1010001020004ULL, 0x2001410408102ULL,
			0x8080808000400020ULL, 0x2040028042200080ULL, 0x5002020020401080ULL, 0x530120042002008ULL, 0x8001010008000411ULL, 0x9010004000208ULL, 0x5040010020108ULL, 0x100020009006084ULL,
			0x270400080008820ULL, 0x4100400100208108ULL, 0x4182008200201048ULL, 0x400080480100081ULL, 0x4002002200041009ULL, 0x5001004900220400ULL, 0x2518400300208ULL, 0x100004200008421ULL,
			0x2000400c88800120ULL, 0x2000409102002200ULL, 0x4001002007004010ULL, 0x880a001022004008ULL, 0x8810401800800ULL, 0x800400800200ULL, 0x2059105204002801ULL, 0x20000400420000a1ULL,
			0x800020804000800dULL, 0x200050014008ULL, 0x4830008020008010ULL, 0x10080010008080ULL, 0x8001004802050010ULL, 0xa42001020040400ULL, 0x4021088040001ULL, 0x800484044a0001ULL,
			0x400410080022500ULL, 0x800401000200840ULL, 0x820892a001004100ULL, 0x2000080080100080ULL, 0x608080004008080ULL, 0x2009000400082300ULL, 0xae080110820400ULL, 0x1800142440810200ULL,
			0x3402604910082ULL, 0x2000108200402502ULL, 0x818200a9406112ULL, 0x802100900004a039ULL, 0x1002000410200802ULL, 0x221000804000201ULL, 0xa000210210480084ULL, 0x1040100802042ULL
		};

		constexpr u8 relevantBishopBits[MaxSquare] =
		{
			6, 5, 5, 5, 5, 5, 5, 6,
			5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 7, 7, 7, 7, 5, 5,
			5, 5, 7, 9, 9, 7, 5, 5,
			5, 5, 7, 9, 9, 7, 5, 5,
			5, 5, 7, 7, 7, 7, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5,
			6, 5, 5, 5, 5, 5, 5, 6
		};

		constexpr u8 relevantRookBits[MaxSquare] =
		{
			12, 11, 11, 11, 11, 11, 11, 12,
			11, 10, 10, 10, 10, 10, 10, 11,
			11, 10, 10, 10, 10, 10, 10, 11,
			11, 10, 10, 10, 10, 10, 10, 11,
			11, 10, 10, 10, 10, 10, 10, 11,
			11, 10, 10, 10, 10, 10, 10, 11,
			11, 10, 10, 10, 10, 10, 10, 11,
			12, 11, 11, 11, 11, 11, 11, 12
		};

		extern Bitboard bishopMasks[MaxSquare];
		extern Bitboard rookMasks[MaxSquare];
		extern Bitboard bishopAttacks[64][512];
		extern Bitboard rookAttacks[64][4096];

		void initMagics();
		void initBishopAttacks(Square square);
		void initRookAttacks(Square square);

		constexpr Bitboard generateBishopAttackMask(Square square)
		{
			Bitboard attacks = 0ULL;

			File file = squareFile(square);
			Rank rank = squareRank(square);

			File targetFile = static_cast<File>(file + 1);
			Rank targetRank = static_cast<Rank>(rank + 1);
			while ((targetRank < Rank8) && (targetFile < FileH))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				++targetFile;
				++targetRank;

			}

			targetFile = static_cast<File>(file - 1);
			targetRank = static_cast<Rank>(rank - 1);
			while ((targetRank > Rank1 && targetFile > FileA))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				--targetFile;
				--targetRank;
			}

			targetFile = static_cast<File>(file + 1);
			targetRank = static_cast<Rank>(rank - 1);
			while ((targetRank > Rank1 && targetFile < FileH))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				++targetFile;
				--targetRank;
			}

			targetFile = static_cast<File>(file - 1);
			targetRank = static_cast<Rank>(rank + 1);
			while ((targetRank < Rank8 && targetFile > FileA))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				--targetFile;
				++targetRank;
			}

			return attacks;
		}

		constexpr Bitboard generateRookAttackMask(Square square)
		{
			Bitboard attacks = 0ULL;

			File file = squareFile(square);
			Rank rank = squareRank(square);

			for (Rank targetRank = static_cast<Rank>(rank + 1); targetRank < Rank8; ++targetRank)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(file, targetRank));
			}

			for (Rank targetRank = static_cast<Rank>(rank - 1); targetRank > Rank1; --targetRank)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(file, targetRank));
			}

			for (File targetFile = static_cast<File>(file + 1); targetFile < FileH; ++targetFile)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, rank));
			}

			for (File targetFile = static_cast<File>(file - 1); targetFile > FileA; --targetFile)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, rank));
			}

			return attacks;
		}

		constexpr Bitboard generateBishopAttacks(Square square, Bitboard occupied)
		{
			Bitboard attacks = 0ULL;

			File file = squareFile(square);
			Rank rank = squareRank(square);

			File targetFile = static_cast<File>(file + 1);
			Rank targetRank = static_cast<Rank>(rank + 1);
			while ((targetRank <= Rank8) && (targetFile <= FileH))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(targetFile, targetRank)))
				{
					break;
				}

				++targetFile;
				++targetRank;

			}

			targetFile = static_cast<File>(file - 1);
			targetRank = static_cast<Rank>(rank - 1);
			while ((targetRank >= Rank1 && targetFile >= FileA))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(targetFile, targetRank)))
				{
					break;
				}

				--targetFile;
				--targetRank;
			}

			targetFile = static_cast<File>(file + 1);
			targetRank = static_cast<Rank>(rank - 1);
			while ((targetRank >= Rank1 && targetFile <= FileH))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(targetFile, targetRank)))
				{
					break;
				}

				++targetFile;
				--targetRank;
			}

			targetFile = static_cast<File>(file - 1);
			targetRank = static_cast<Rank>(rank + 1);
			while ((targetRank <= Rank8 && targetFile >= FileA))
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, targetRank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(targetFile, targetRank)))
				{
					break;
				}

				--targetFile;
				++targetRank;
			}

			return attacks;
		}

		constexpr Bitboard generateRookAttacks(Square square, Bitboard occupied)
		{
			Bitboard attacks = 0ULL;

			File file = squareFile(square);
			Rank rank = squareRank(square);

			for (Rank targetRank = static_cast<Rank>(rank + 1); targetRank <= Rank8; ++targetRank)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(file, targetRank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(file, targetRank)))
				{
					break;
				}
			}

			for (Rank targetRank = static_cast<Rank>(rank - 1); targetRank >= Rank1; --targetRank)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(file, targetRank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(file, targetRank)))
				{
					break;
				}
			}

			for (File targetFile = static_cast<File>(file + 1); targetFile <= FileH; ++targetFile)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, rank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(targetFile, rank)))
				{
					break;
				}
			}

			for (File targetFile = static_cast<File>(file - 1); targetFile >= FileA; --targetFile)
			{
				attacks |= Bitboards::squareBitboard(fileRankToSquare(targetFile, rank));

				if (Bitboards::checkBit(occupied, fileRankToSquare(targetFile, rank)))
				{
					break;
				}
			}

			return attacks;
		}

		constexpr Bitboard setOccupancy(int index, Bitboard attacks, int bitCount)
		{
			Bitboard occupancy = 0ULL;

			for (int i = 0; i < bitCount; ++i)
			{
				Square square = Bitboards::popLsb(attacks);

				if ((index & (1 << i)) != 0)
				{
					occupancy |= Bitboards::squareBitboard(square);
				}
			}

			return occupancy;
		}

		constexpr Bitboard getBishopAttacks(Square square, Bitboard occupied)
		{
			Bitboard occupancy = occupied;
			occupancy &= bishopMasks[square];
			occupancy *= bishopMagics[square];
			occupancy >>= 64 - relevantBishopBits[square];

			return bishopAttacks[square][occupancy];
		}

		constexpr Bitboard getRookAttacks(Square square, Bitboard occupied)
		{
			Bitboard occupancy = occupied;
			occupancy &= rookMasks[square];
			occupancy *= rookMagics[square];
			occupancy >>= 64 - relevantRookBits[square];

			return rookAttacks[square][occupancy];
		}

		constexpr Bitboard getQueenAttacks(Square square, Bitboard occupied)
		{
			return getRookAttacks(square, occupied) | getBishopAttacks(square, occupied);
		}
	}
}