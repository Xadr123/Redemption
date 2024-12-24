#include <iostream>

#include "core.h"
#include "board.h"

namespace Redemption
{
	void Board::parseFen(std::string fen)
	{
		File file = FileA;
		Rank rank = Rank8;

		std::vector<std::string> sections = split(fen, ' ');

		state = BoardState();

		// Handle piece placement
		for (char character : sections[0])
		{
			if (isdigit(character) && ((character - '0') <= MaxFile))
			{
				file = static_cast<File>(file + (character - '0'));
				continue;
			}
			else if (character == '/')
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
				continue;
			}
		}

		// Handle side to move
		if (sections[1] == "w")
		{
			state.sideToMove = White;
		}
		else if (sections[1] == "b")
		{
			state.sideToMove = Black;
		}

		// Handle castling rights
		for (char character : sections[2])
		{
			switch (character)
			{
			case 'K': 
				state.castlingRights |= WhiteKingSideCastling;
				continue;
			case 'Q':
				state.castlingRights |= WhiteQueenSideCastling;
				continue;
			case 'k':
				state.castlingRights |= BlackKingSideCastling;
				continue;
			case 'q':
				state.castlingRights |= BlackQueenSideCastling;
				continue;
			default: break;
			}
		}

		// Handle en passant
		if (sections[3] == "-")
		{
			state.enPassantSquare = OffBoard;
		}
		else
		{
			File epFile = static_cast<File>(sections[3][0] - 'a');
			Rank epRank = static_cast<Rank>(sections[3][1] - '1');
			state.enPassantSquare = fileRankToSquare(epFile, epRank);
		}

		state.halfMoveClock = std::stoi(sections[4]);
		state.fullMoveCount = std::stoi(sections[5]);
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
		std::cout << "    a   b   c   d   e   f   g   h" << '\n';
		std::cout << "Side to move: " << state.sideToMove << '\n';
		std::cout << "Castling Rights: " << state.castlingRights << '\n';
		std::cout << "En Passant Square: " << state.enPassantSquare << '\n';
		std::cout << "Half Move Clock: " << state.halfMoveClock << '\n';
		std::cout << "Full Move Count: " << state.fullMoveCount << std::endl;
	}
}