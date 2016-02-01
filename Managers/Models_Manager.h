#pragma once
#include <map>
#include "Shader_Manager.h"
#include "..\Rendering\IGameObject.h"
#include "..\Rendering\Models\Triangle.h"
#include "..\Rendering\Models\Quad.h"

using namespace Rendering;

namespace Managers
{
	class Models_Manager
	{
		public:
			Models_Manager();
			~Models_Manager();

			void draw();
			void update();
			void deleteModel(const std::string &gameModelName);
			const IGameObject& getModel(const std::string &gameModelName);

		private:
			std::map<std::string, IGameObject*> gameModelList; //change to vector for larger games
	};
}
