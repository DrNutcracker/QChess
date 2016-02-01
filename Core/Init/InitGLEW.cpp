#include "InitGLEW.h"

using namespace Core;
using namespace Core::Init;

void InitGLEW::initialize()
{
	glewExperimental = true;

	if (glewInit() == GLEW_OK)
	{
		std::cout << "GLEW: initialize" << std::endl;
	}

	if (glewIsSupported("GL_VERSION_4_3"))//this computer has openGL 4.3 and components of 4.4/4.5
	{
		std::cout << "OpenGL Version is 4.3\n ";
	}
	else
	{
		std::cout << "OpenGL 4.3 not supported\n ";
	}
}