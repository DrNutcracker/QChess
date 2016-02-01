#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{
	//triangle object
	Models::Triangle* triangle = new Models::Triangle();
	triangle->setProgram(Shader_Manager::getShader("colorShader"));
	triangle->create();
	gameModelList["triangle"] = triangle;

	Models::Quad* quad = new Models::Quad();
	quad->setProgram(Shader_Manager::getShader("colorShader"));
	quad->create();
	gameModelList["quad"] = quad;
}

Models_Manager::~Models_Manager()
{
	for (auto model : gameModelList)//another C++11 thing. Please don't get funky
	{
		delete model.second;
	}
	gameModelList.clear();
}

void Models_Manager::deleteModel(const std::string &gameModelName)
{
	IGameObject* model = gameModelList[gameModelName];
	model->destroy();
	gameModelList.erase(gameModelName);
}

const IGameObject& Models_Manager::getModel(const std::string &gameModelName)
{
	return (*gameModelList[gameModelName]);//recomended to use .at(), but eff that. Paranoia is strong here
}

void Models_Manager::update()
{
	for (auto model : gameModelList) //another C++11 reference, pray to Cthulhu!
	{
		model.second->draw();
	}
}

void Models_Manager::draw()
{
	for (auto model : gameModelList)//another C++11 reference, cross ALL of my digits. ALL of them
	{
		model.second->draw();
	}
}