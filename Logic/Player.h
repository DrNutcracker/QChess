#pragma once

namespace Logic
{
	class Player
	{
		public:

			//virtual ~Player() = 0;

			virtual void update(float deltaTime) = 0;
			virtual void draw() = 0;

			
	};
}