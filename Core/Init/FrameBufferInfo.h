#pragma once
#include "..\..\Dependencies\glew\glew.h"
#include "..\..\Dependencies\freeglut\include\GL\freeglut.h"

namespace Core
{
	struct FrameBufferInfo
	{
		unsigned int flags;
		bool msaa;

		FrameBufferInfo()
		{
			flags = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
			msaa = false;
		}

		FrameBufferInfo(bool color, bool depth, bool stencil, bool msaa)
		{
			flags = GLUT_DOUBLE; //need always
			if (color)
				flags |= GLUT_RGBA | GLUT_ALPHA;
			if (depth)
				flags |= GLUT_DEPTH;
			if (stencil)
				flags |= GLUT_STENCIL;
			if (msaa)
				flags |= GLUT_MULTISAMPLE;
			this->msaa = msaa;
		}

		FrameBufferInfo(const FrameBufferInfo &otherFrameBufferInfo)
		{
			flags = otherFrameBufferInfo.flags;
			msaa = otherFrameBufferInfo.msaa;
		}

		void operator=(const FrameBufferInfo &otherFrameBufferInfo)
		{
			flags = otherFrameBufferInfo.flags;
			msaa = otherFrameBufferInfo.msaa;
		}
	};
}