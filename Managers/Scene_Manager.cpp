#include "Scene_Manager.h"

using namespace Managers;

Scene_Manager::Scene_Manager()
{
	glEnable(GL_DEPTH_TEST);

	shaderManager = new Shader_Manager();
	shaderManager->createProgram("colorShader", "Shaders\\Vertex_Shader.glsl", "Shaders\\Fragment_Shader.glsl");

	modelsManager = new Models_Manager();
}

Scene_Manager::~Scene_Manager()
{
	delete shaderManager;
	delete modelsManager;
}

void Scene_Manager::notifyBeginFrame()
{
	//triangle's update does nothing, but for future consistency, JUST DO IT
	modelsManager->update();
}

void Scene_Manager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	modelsManager->draw();
}

void Scene_Manager::notifyEndFrame()
{
	//nothing yet
}

void Scene_Manager::notifyReshape(int width, int height, int prevWidth, int prevHeight)
{
	//nothing yet
}