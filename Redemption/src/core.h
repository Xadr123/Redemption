#pragma once

#include <cstdint>
#include <cassert>
#include <string>
#include <string_view>

namespace Redemption 
{
	constexpr std::string_view Name = "Redemption";
	constexpr std::string_view Version = "0.0";
	constexpr std::string_view Author = "Xadr";

	// Shortened type names for unsigned int sizes.
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	// Shortened type names for signed int sizes.
	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;

	using Bitboard = u64;

	enum Color : i16
	{
		White = 0,
		Black,
		None = 2,
		MaxColor = 2
	};

	enum PieceType : i16
	{
		NoPieceType = 0,
		Pawn,
		Knight,
		Bishop,
		Rook,
		Queen,
		King,
		MaxPieceType = 7
	};

	enum Piece : i16
	{
		NoPiece = 0,
		WhiteOffset = 0,
		WhitePawn = Pawn,
		WhiteKnight = Knight,
		WhiteBishop = Bishop,
		WhiteRook = Rook,
		WhiteQueen = Queen,
		WhiteKing = King,
		BlackOffset = 8,
		BlackPawn = Pawn + BlackOffset,
		BlackKnight = Knight + BlackOffset,
		BlackBishop = Bishop + BlackOffset,
		BlackRook = Rook + BlackOffset,
		BlackQueen = Queen + BlackOffset,
		BlackKing = King + BlackOffset,
		MaxPiece = 16
	};

	// Upside-down
	enum Square : i16
	{
		A1 = 0, B1, C1, D1, E1, F1, G1, H1,
		A2, B2, C2, D2, E2, F2, G2, H2,
		A3, B3, C3, D3, E3, F3, G3, H3,
		A4, B4, C4, D4, E4, F4, G4, H4,
		A5, B5, C5, D5, E5, F5, G5, H5,
		A6, B6, C6, D6, E6, F6, G6, H6,
		A7, B7, C7, D7, E7, F7, G7, H7,
		A8, B8, C8, D8, E8, F8, G8, H8,
		OffBoard,
		MaxSquare = 64
	};

	enum File : i16
	{
		FileA = 0,
		FileB,
		FileC,
		FileD,
		FileE,
		FileF,
		FileG,
		FileH,
		MaxFile = 8
	};

	enum Rank : i16
	{
		Rank1 = 0,
		Rank2,
		Rank3,
		Rank4,
		Rank5,
		Rank6,
		Rank7,
		Rank8,
		MaxRank = 8
	};

	enum Direction : i16
	{
		North = 8,
		South = -8,
		East = 1,
		West = -1,
		NorthEast = North + East,
		NorthWest = North + West,
		SouthEast = South + East,
		SouthWest = South + West
	};

	// Incremental/Decremental operators for Square, File, Rank and Piece Type.
	inline Square& operator++(Square& square) { return square = static_cast<Square>(square + 1); }
	inline Square& operator--(Square& square) { return square = static_cast<Square>(square - 1); }

	inline File& operator++(File& file) { return file = static_cast<File>(file + 1); }
	inline File& operator--(File& file) { return file = static_cast<File>(file - 1); }

	inline Rank& operator++(Rank& rank) { return rank = static_cast<Rank>(rank + 1); }
	inline Rank& operator--(Rank& rank) { return rank = static_cast<Rank>(rank - 1); }

	inline PieceType& operator++(PieceType& pieceType) { return pieceType = static_cast<PieceType>(pieceType + 1); }
	inline PieceType& operator--(PieceType& pieceType) { return pieceType = static_cast<PieceType>(pieceType - 1); }

	// Operators for adding direction to square.
	constexpr Square operator+(Square square, Direction direction) { return static_cast<Square>(static_cast<i16>(square) + static_cast<i16>(direction)); }
	constexpr Square operator-(Square square, Direction direction) { return static_cast<Square>(static_cast<i16>(square) - static_cast<i16>(direction)); }

	inline Square& operator+=(Square& square, Direction direction) { return square = square + direction; }
	inline Square& operator-=(Square& square, Direction direction) { return square = square - direction; }

	constexpr std::string_view SquareNames[MaxSquare] =
	{
		"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
		"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
		"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
		"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
		"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
		"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
		"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
		"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"
	};

	constexpr char PieceCharacters[MaxPiece] =
	{
		'.', 
		'P', 'N', 'B', 'R', 'Q', 'K', 
		'.', '.', 
		'p', 'n', 'b', 'r', 'q', 'k', 
		'.'
	};

	constexpr bool isValidSquare(Square square)
	{
		return (square >= A1 && square < MaxSquare);
	}

	constexpr Square fileRankToSquare(File file, Rank rank)
	{
		assert(file < MaxFile);
		assert(rank < MaxRank);

		return static_cast<Square>((rank * 8) + file);
	};

	constexpr File squareFile(Square square)
	{
		assert(isValidSquare(square));

		return static_cast<File>(square & 7);
	}

	constexpr Rank squareRank(Square square)
	{
		assert(isValidSquare(square));

		return static_cast<Rank>(square >> 3);
	}

	constexpr PieceType pieceType(Piece piece)
	{
		assert(piece < MaxPiece);

		return static_cast<PieceType>(piece & 7);
	}

	constexpr Color pieceColor(Piece piece)
	{
		assert(piece < MaxPiece);

		return static_cast<Color>(piece >> 3);
	}

	constexpr Piece makePiece(PieceType pieceType, Color color)
	{
		assert(pieceType < MaxPieceType);
		assert(color < MaxColor);

		if (color == White)
		{
			return static_cast<Piece>(pieceType);
		}
		else
		{
			return static_cast<Piece>(pieceType + 8);
		}
	}
}