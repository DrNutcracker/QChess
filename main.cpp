#pragma once
#include "Core\Init\InitGLUT.h"
#include "Managers\Scene_Manager.h"

using namespace Core;
using namespace Init;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("OpenGL Beginner Tutorial"),
		200, 200, //position
		400, 300, //size
		true); //reshape

	ContextInfo context(4, 3, true);
	FrameBufferInfo frameBuffer(true, true, true, true);
	InitGLUT::init(window, context, frameBuffer);

	IListener* scene = new Managers::Scene_Manager();
	Init::InitGLUT::setListener(scene);

	InitGLUT::run();

	delete scene;

	return 0;
}