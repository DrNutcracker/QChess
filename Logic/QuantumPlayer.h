#pragma once
#include "Player.h"
#include "QuantumPiece.h"
#include <stdlib.h>
#include <vector>
#include <map>

namespace Logic
{
	class QuantumPlayer : public Logic::Player
	{
		public:

			QuantumPlayer(int color);
			~QuantumPlayer();

			void update(float deltaTime);
			void draw();

			int touchPiece(int r, int c); //0 if no piece was touched (same as selecting)
			int movePiece(int targetR, int targetC); //0 if no piece was captured

		private:

			std::vector<QuantumPiece>  pieces;
			QuantumPiece * touchedPiece;
			int playerColor;

			int getRandomType(std::map<int, int> prevGen);
			

			const static int RED_BLUE = 0;
			const static int GREEN_YELLOW = 1;
	};
}