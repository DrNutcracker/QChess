#pragma once
#include <vector>
#include "../IGameObject.h"

namespace Rendering
{
	namespace Models
	{
		class Model : public IGameObject
		{
			public:
				Model();
				virtual ~Model();

				//methods from interface
				virtual void draw() override;//override is C++11 syntax, please don't fuck up
				virtual void update() override;
				virtual void setProgram(GLuint shaderName) override;
				virtual void destroy() override;

				virtual GLuint getVao() const override;
				virtual const std::vector<GLuint>& getVbos() const override;

			protected:
				GLuint vao;
				GLuint program;
				std::vector<GLuint> vbos;
		};
	}
}