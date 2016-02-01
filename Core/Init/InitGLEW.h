#pragma once
#include "..\..\Dependencies\glew\glew.h"
#include "..\..\Dependencies\freeglut\include\GL\freeglut.h"
#include <iostream>

namespace Core
{
	namespace Init
	{
		class InitGLEW
		{
			public:
				static void initialize();
		};
	}
}