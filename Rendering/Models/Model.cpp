#include "Model.h"

using namespace Rendering;
using namespace Models;

Model::Model(){}

Model::~Model()
{
	destroy();
}

void Model::draw()
{
	//will be overridden
}

void Model::update()
{
	//will be overridden
}

void Model::setProgram(GLuint program)
{
	this->program = program;
}

GLuint Model::getVao() const
{
	return vao;
}

const std::vector<GLuint>& Model::getVbos() const
{
	return vbos;
}

void Model::destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}