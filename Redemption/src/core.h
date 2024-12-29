#pragma once

#include <cstdint>
#include <cassert>
#include <string>

namespace Redemption
{
	// Shortened type names for unsigned int sizes.
	using u8 = std::uint8_t;
	using u16 = std::uint16_t;
	using u32 = std::uint32_t;
	using u64 = std::uint64_t;

	// Shortened type names for signed int sizes.
	using i8 = std::int8_t;
	using i16 = std::int16_t;
	using i32 = std::int32_t;
	using i64 = std::int64_t;

	using Bitboard = std::uint64_t;

	enum Color : i8
	{
		NoColor,
		White,
		Black,
		MaxColor
	};

	enum PieceType : i8
	{
		NoPieceType,
		Pawn,
		Knight,
		Bishop,
		Rook,
		Queen,
		King,
		MaxPieceType
	};

	enum Piece : i8
	{
		NoPiece,
		WhitePiece = 0,
		BlackPiece = 8,
		WhitePawn = WhitePiece + Pawn,
		WhiteKnight = WhitePiece + Knight,
		WhiteBishop = WhitePiece + Bishop,
		WhiteRook = WhitePiece + Rook,
		WhiteQueen = WhitePiece + Queen,
		WhiteKing = WhitePiece + King,
		BlackPawn = BlackPiece + Pawn,
		BlackKnight = BlackPiece + Knight,
		BlackBishop = BlackPiece + Bishop,
		BlackRook = BlackPiece + Rook,
		BlackQueen = BlackPiece + Queen,
		BlackKing = BlackPiece + King,
		MaxPiece = 16
	};

	// Reversed
	enum Square : i8
	{
		A1, B1, C1, D1, E1, F1, G1, H1,
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

	enum File : i8
	{
		FileA,
		FileB,
		FileC,
		FileD,
		FileE,
		FileF,
		FileG,
		FileH,
		MaxFile
	};

	enum Rank : i8
	{
		Rank1,
		Rank2,
		Rank3,
		Rank4,
		Rank5,
		Rank6,
		Rank7,
		Rank8,
		MaxRank
	};

	enum Direction : i8
	{
		North = 8,
		DoubleNorth = 16,
		South = -8,
		DoubleSouth = -16,
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

	// String arrays for names colors and squares. For debugging mainly.
	constexpr std::string_view ColorNames[MaxColor] =
	{
		"No Color",
		"White",
		"Black"
	};

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

	constexpr char pieceToCharacter(Piece piece)
	{
		switch (piece)
		{
		case NoPiece: return ' ';
		case WhitePawn: return 'P';
		case WhiteKnight: return 'N';
		case WhiteBishop: return 'B';
		case WhiteRook: return 'R';
		case WhiteQueen: return 'Q';
		case WhiteKing: return 'K';
		case BlackPawn: return 'p';
		case BlackKnight: return 'n';
		case BlackBishop: return 'b';
		case BlackRook: return 'r';
		case BlackQueen: return 'q';
		case BlackKing: return 'k';
		default: return ' ';
		}
	}

	constexpr Piece pieceFromCharacter(char character)
	{
		switch (character)
		{
		case 'P': return WhitePawn;
		case 'N': return WhiteKnight;
		case 'B': return WhiteBishop;
		case 'R': return WhiteRook;
		case 'Q': return WhiteQueen;
		case 'K': return WhiteKing;
		case 'p': return BlackPawn;
		case 'n': return BlackKnight;
		case 'b': return BlackBishop;
		case 'r': return BlackRook;
		case 'q': return BlackQueen;
		case 'k': return BlackKing;
		case ' ': return NoPiece;
		default: return NoPiece;
		}
	}

	constexpr char pieceTypeToCharacter(Piece piece)
	{
		switch (piece)
		{
		case NoPiece: return ' ';
		case Pawn: return 'p';
		case Knight: return 'n';
		case Bishop: return 'b';
		case Rook: return 'r';
		case Queen: return 'q';
		case King: return 'k';
		default: return ' ';
		}
	}

	constexpr PieceType pieceTypeFromCharacter(char character)
	{
		switch (character)
		{
		case 'P': return Pawn;
		case 'N': return Knight;
		case 'B': return Bishop;
		case 'R': return Rook;
		case 'Q': return Queen;
		case 'K': return King;
		case 'p': return Pawn;
		case 'n': return Knight;
		case 'b': return Bishop;
		case 'r': return Rook;
		case 'q': return Queen;
		case 'k': return King;
		case ' ': return NoPieceType;
		default: return NoPieceType;
		}
	}

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

		if (piece < BlackPiece)
		{
			return White;
		}
		else
		{
			return Black;
		}
	}
}
