#include "QuantumPlayer.h"

using namespace Logic;

QuantumPlayer::QuantumPlayer(int color)
{
	playerColor = color;
	int row;
	touchedPiece = NULL;

	std::map<int, int> prevGen;
	prevGen[GamePiece::QUEEN] = 0;
	prevGen[GamePiece::BISHOP] = 0;
	prevGen[GamePiece::ROOK] = 0;
	prevGen[GamePiece::KNIGHT] = 0;
	prevGen[GamePiece::PAWN] = 0;
	
	if (playerColor == RED_BLUE)
	{
		pieces.push_back(QuantumPiece(GamePiece::KING, GamePiece::KING, 0, 3));
		pieces.push_back(QuantumPiece(GamePiece::QUEEN, getRandomType(prevGen), 0, 4));
		row = 0;
	}
	else
	{
		pieces.push_back(QuantumPiece(GamePiece::KING, GamePiece::KING, 7, 3));
		pieces.push_back(QuantumPiece(GamePiece::QUEEN, getRandomType(prevGen), 7, 4));
		row = 7;
	}

	pieces.push_back(QuantumPiece(GamePiece::ROOK, getRandomType(prevGen), row, 0));
	pieces.push_back(QuantumPiece(GamePiece::ROOK, getRandomType(prevGen), row, 7));
	pieces.push_back(QuantumPiece(GamePiece::BISHOP, getRandomType(prevGen), row, 2));
	pieces.push_back(QuantumPiece(GamePiece::BISHOP, getRandomType(prevGen), row, 5));
	pieces.push_back(QuantumPiece(GamePiece::KNIGHT, getRandomType(prevGen), row, 1));
	pieces.push_back(QuantumPiece(GamePiece::KNIGHT, getRandomType(prevGen), row, 6));
	
	if (playerColor == RED_BLUE)
		row++;
	else
		row--;
	
	for (int i = 0; i < 8; ++i)
		pieces.push_back(QuantumPiece(GamePiece::PAWN, getRandomType(prevGen), row, i));
	
}

int QuantumPlayer::getRandomType(std::map<int, int> prevGen)
{
	bool generating = true;

	while (generating)
	{
		int rand = std::rand() % 5;
		if (rand == 0 && prevGen[GamePiece::PAWN] < 8)
		{
			prevGen[GamePiece::PAWN]++;
			return GamePiece::PAWN;
		}
		else if (rand == 1 && prevGen[GamePiece::BISHOP] < 2)
		{
			prevGen[GamePiece::BISHOP]++;
			return GamePiece::BISHOP;
		}
		else if (rand == 0 && prevGen[GamePiece::KNIGHT] < 2)
		{
			prevGen[GamePiece::KNIGHT]++;
			return GamePiece::KNIGHT;
		}
		else if (rand == 0 && prevGen[GamePiece::ROOK] < 2)
		{
			prevGen[GamePiece::ROOK]++;
			return GamePiece::ROOK;
		}
		else
		{
			prevGen[GamePiece::QUEEN]++;
			return GamePiece::QUEEN;
		}
	}
	return 0;//filler
}

QuantumPlayer::~QuantumPlayer()
{
	//delete touchedPiece;
}

void QuantumPlayer::draw()
{
	for (auto piece : pieces)
		piece.draw();
}

void QuantumPlayer::update(float deltaTime)
{
	for (auto piece : pieces)
		piece.update(deltaTime);
}

int QuantumPlayer::touchPiece(int r, int c)
{
	for (size_t i = 0; i < pieces.size(); ++i)
	{
		QuantumPiece piece = pieces[i];
		if (piece.getRow() == r && piece.getCol() == c)
		{
			*touchedPiece = piece;
			return piece.getType();
		}
	}
	return 0;//no piece was touched
}

int QuantumPlayer::movePiece(int targetR, int targetC)
{
	return 0;
}