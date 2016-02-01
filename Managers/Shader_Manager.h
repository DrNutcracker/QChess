#pragma once

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\include\GL\freeglut.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

namespace Managers
{
	class Shader_Manager
	{
		private:

			std::string readShader(const std::string &fileName);
			GLuint createShader(GLenum shaderType, const std::string &source, const std::string &shaderName);
			static std::map<std::string, GLuint> programs;

		public:

			Shader_Manager(void);
			~Shader_Manager(void);
			void createProgram(const std::string &shaderName, const std::string &vertexShaderFileName, const std::string &fragmentShaderFileName);
			static const GLuint getShader(const std::string &name);
	};
}

