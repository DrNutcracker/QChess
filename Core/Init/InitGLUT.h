#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include "InitGLEW.h"
#include "IListener.h"
#include <iostream>

namespace Core
{
	namespace Init
	{
		class InitGLUT
		{
			public:
				
				static void init(const Core::WindowInfo &window, const Core::ContextInfo &context, const Core::FrameBufferInfo &frameBuffer);
				static void run();
				static void close();

				void enterFullScreen();
				void exitFullScreen();

				static void printOpenGLInfo(const Core::WindowInfo &window, const Core::ContextInfo &context);

				static void setListener(Core::IListener* &iListener);

			private:

				static void idleCallback();
				static void displayCallback();
				static void reshapeCallback(int width, int height);
				static void closeCallback();

				static Core::IListener* listener;
				static Core::WindowInfo windowInformation;
		};
	}
}



