#pragma once
#include "GamePiece.h"
#include <stdlib.h> //for rand()
//#include "../Rendering/Models/"

namespace Logic
{
	class QuantumPiece : public Logic::GamePiece
	{
		public:
			QuantumPiece(int pType, int sType, int r, int c);
			~QuantumPiece();

			void update(float deltaTime);
			void draw() override;

			void setPosition(int r, int c);
			int getRow();
			int getCol();
			bool isInSuperPosition();
			int getType();
			void setPrimaryType(int type);
			void setSecondaryType(int type);
			void setSuperPosition(bool isQ);


		private:
			int primaryType, secondaryType;
			int currentType;
			int row, col;

			static const int SUPER_POSITION = 0;
	};
}