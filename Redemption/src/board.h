#pragma once

#include <vector>
#include <sstream>

#include "core.h"
#include "bitboards.h"

namespace Redemption
{
	enum CastlingPermissions : i8
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

		Color sideToMove {};
		i16 castlingRights {};
		Square enPassantSquare {};
		i16 halfMoveClock {};
		i16 fullMoveCount {};
		i16 fiftyMoveCounter {};
	};

	std::vector<std::string> splitString(std::string string, char delimiter);

	class Board
	{
	public:
		Board() = default;
		~Board() = default;

		BoardState boardState = BoardState();

		void printBoard();
		void parseFen(std::string fen);
	};
}