#pragma once

#include "core.h"
#include "bitboards.h"

namespace Redemption
{
	struct BoardState
	{
		Bitboard pieceBitboards[MaxPieceType]{};
		Bitboard colorBitboards[MaxColor]{};
		Piece pieces[MaxSquare]{};

		Color sideToMove{};
		u64 castlingRights{};
		Square enPassantSquare{};
		i16 HalfMoveClock{};
		i16 FullMoveCount{};
		i16 FiftyMoveCounter{};
	};

	class Board
	{
	public:
		Board() = default;
		~Board() = default;

		BoardState state;

		void parseFen(std::string_view fen);
		void printBoard();
	};
}