#pragma once
#include "Model.h"

namespace Rendering
{
	namespace Models
	{
		class Quad : public Models::Model
		{
			public:
				Quad();
				~Quad();

				void create();
				virtual void draw() override final;//dos mas C++11 refernces. Someone go knock on Jesus's door
				virtual void update() override final;
		};
	}
}