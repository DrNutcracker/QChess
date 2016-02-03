#pragma once

namespace Logic
{
	class GamePiece
	{
		public:
			//virtual ~GamePiece() = 0;

			virtual void update(float deltaTime) = 0;
			virtual void draw() = 0;

			static const int KING = 1;
			static const int QUEEN = 2;
			static const int BISHOP = 3;
			static const int ROOK = 4;
			static const int KNIGHT = 5;
			static const int PAWN = 6;
	};
}