#pragma once
#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\include\GL\freeglut.h"
#include <vector>
#include <iostream>
#include "VertexFormat.h"

namespace Rendering
{
	class IGameObject
	{
		public:
			virtual ~IGameObject() = 0;

			virtual void draw() = 0;
			virtual void update() = 0;
			virtual void setProgram(GLuint shadername) = 0;
			virtual void destroy() = 0;

			virtual GLuint getVao() const = 0;
			virtual const std::vector<GLuint>& getVbos() const = 0;
	};

	inline IGameObject::~IGameObject(){}
}
