#pragma once

#include "core.h"
#include "bitboards.h"

namespace Redemption
{
	enum CastlingPermissions : i16
	{
		WhiteKingSideCastling = 1,
		WhiteQueenSideCastling = 2,
		BlackKingSideCastling = 4,
		BlackQueenSideCastling = 8
	};

	struct BoardState
	{
		Bitboard pieceBitboards[MaxPieceType]{};
		Bitboard colorBitboards[MaxColor]{};
		Piece pieces[MaxSquare]{};

		Color sideToMove{};
		i16 castlingRights{};
		Square enPassantSquare{};
		i16 halfMoveClock{};
		i16 fullMoveCount{};
		i16 fiftyMoveCounter{};
	};

	class Board
	{
	public:
		Board() = default;
		~Board() = default;

		BoardState state;

		void parseFen(std::string fen);
		void printBoard();
	};
}