#pragma once

namespace Logic
{
	class GamePiece
	{
		public:
			//virtual ~GamePiece();

			virtual void update(float deltaTime);
			virtual void draw();

			static const int KING = 1;
			static const int QUEEN = 2;
			static const int BISHOP = 3;
			static const int ROOK = 4;
			static const int KNIGHT = 5;
			static const int PAWN = 6;
	};
}