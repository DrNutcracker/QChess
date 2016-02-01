#pragma once
#include <string>

namespace Core
{
	struct WindowInfo
	{
		std::string name;
		int width, height;
		int positionX, positionY;
		bool isReshapeable;

		WindowInfo()
		{
			name = "OpenGL Tutorial";
			width = 400;
			height = 300;
			positionX = 200;
			positionY = 200;
			isReshapeable = true;
		}

		WindowInfo(std::string name, int startingX, int startingY, int w, int h, bool canReshape)
		{
			this->name = name;
			this->positionX = startingX;
			this->positionY = startingY;
			this->width = w;
			this->height = h;
			this->isReshapeable = canReshape;
		}

		WindowInfo(const WindowInfo &otherWindow)
		{
			name = otherWindow.name;
			positionX = otherWindow.positionX;
			positionY = otherWindow.positionY;
			width = otherWindow.width;
			height = otherWindow.height;
			isReshapeable = otherWindow.isReshapeable;
		}

		void operator=(const WindowInfo &otherWindow)
		{
			name = otherWindow.name;
			positionX = otherWindow.positionX;
			positionY = otherWindow.positionY;
			width = otherWindow.width;
			height = otherWindow.height;
			isReshapeable = otherWindow.isReshapeable;
		}
	};
}