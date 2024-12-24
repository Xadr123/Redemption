#include <iostream>

#include "core.h"
#include "board.h"

namespace Redemption
{
	void Board::parseFen(std::string_view fen)
	{
		File file = FileA;
		Rank rank = Rank8;

		state = BoardState();

		for (char character : fen)
		{
			if (isdigit(character))
			{
				file = static_cast<File>(file + (character - '0'));
			}
			else if (character == '/' || character == ' ')
			{
				file = FileA;
				--rank;
				continue;
			}
			else
			{
				Piece piece = pieceFromCharacter(character);
				state.pieces[fileRankToSquare(file, rank)] = piece;
				Bitboards::setBit(state.pieceBitboards[pieceType(piece)], fileRankToSquare(file, rank));
				Bitboards::setBit(state.pieceBitboards[pieceColor(piece)], fileRankToSquare(file, rank));
				++file;
			}
		}
	}

	void Board::printBoard()
	{
		std::cout << '\n' << "  +---+---+---+---+---+---+---+---+" << '\n';

		for (Rank rank = Rank8; rank >= Rank1; --rank)
		{
			std::cout << (1 + rank);

			for (File file = FileA; file < MaxFile; ++file)
			{
				Piece piece = state.pieces[fileRankToSquare(file, rank)];
				std::cout << " | " << pieceToCharacter(piece);
			}
			std::cout << " | " << '\n' << "  +---+---+---+---+---+---+---+---+" << '\n';

		}
		std::cout << "    a   b   c   d   e   f   g   h" << std::endl;
	}
}