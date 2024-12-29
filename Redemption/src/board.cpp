#include "board.h"

namespace Redemption
{
	void Board::printBoard()
	{
		std::cout << '\n' << "  +---+---+---+---+---+---+---+---+" << '\n';

		for (Rank rank = Rank8; rank >= Rank1; --rank)
		{
			std::cout << (1 + rank);

			for (File file = FileA; file < MaxFile; ++file)
			{
				Piece piece = boardState.pieces[fileRankToSquare(file, rank)];
				std::cout << " | " << pieceToCharacter(piece);
			}
			std::cout << " | " << '\n' << "  +---+---+---+---+---+---+---+---+" << '\n';

		}
		std::cout << "    a   b   c   d   e   f   g   h" << '\n';
		std::cout << '\n' << "Side to move: " << ColorNames[boardState.sideToMove] << '\n';
		std::cout << "Castling Rights: " << boardState.castlingRights << '\n';
		std::cout << "En Passant Square: " << SquareNames[boardState.enPassantSquare] << '\n';
		std::cout << "Half Move Clock: " << boardState.halfMoveClock << '\n';
		std::cout << "Full Move Count: " << boardState.fullMoveCount << std::endl;
	}

	void Board::parseFen(std::string fen)
	{
		File file = FileA;
		Rank rank = Rank8;

		std::vector<std::string> sections = splitString(fen, ' ');

		boardState = BoardState();

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
				boardState.pieces[fileRankToSquare(file, rank)] = piece;
				Bitboards::setBit(boardState.pieceBitboards[pieceType(piece)], fileRankToSquare(file, rank));
				Bitboards::setBit(boardState.colorBitboards[pieceColor(piece)], fileRankToSquare(file, rank));
				++file;
				continue;
			}
		}

		// Handle side to move
		if (sections[1] == "w")
		{
			boardState.sideToMove = White;
		}
		else if (sections[1] == "b")
		{
			boardState.sideToMove = Black;
		}

		// Handle castling rights
		for (char character : sections[2])
		{
			switch (character)
			{
			case 'K':
				boardState.castlingRights |= WhiteKingSideCastling;
				continue;
			case 'Q':
				boardState.castlingRights |= WhiteQueenSideCastling;
				continue;
			case 'k':
				boardState.castlingRights |= BlackKingSideCastling;
				continue;
			case 'q':
				boardState.castlingRights |= BlackQueenSideCastling;
				continue;
			default: break;
			}
		}

		// Handle en passant
		if (sections[3] == "-")
		{
			boardState.enPassantSquare = OffBoard;
		}
		else
		{
			File epFile = static_cast<File>(sections[3][0] - 'a');
			Rank epRank = static_cast<Rank>(sections[3][1] - '1');
			boardState.enPassantSquare = fileRankToSquare(epFile, epRank);
		}

		boardState.halfMoveClock = static_cast<i16>(std::stoi(sections[4]));
		boardState.fullMoveCount = static_cast<i16>(std::stoi(sections[5]));
	}

	// Found at https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	std::vector<std::string> splitString(std::string string, char delimiter) {
		std::vector<std::string> result;
		std::stringstream ss(string);
		std::string item;

		while (getline(ss, item, delimiter)) {
			result.push_back(item);
		}

		return result;
	}
}
