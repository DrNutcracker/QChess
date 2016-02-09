#include "InitGLUT.h"

using namespace Core::Init;

Core::IListener* InitGLUT::listener = NULL;
Core::WindowInfo InitGLUT::windowInformation;

void InitGLUT::init(const Core::WindowInfo &window, const Core::ContextInfo &context, const Core::FrameBufferInfo &frameBuffer)
{
	//need arguements, probably a better way to do this
	int fakeArgc = 1;
	char* fakeArgv[] = { "fake, NULL" };
	glutInit(&fakeArgc, fakeArgv);

	windowInformation = window;

	if (context.core)
	{
		glutInitContextVersion(context.majorVersion, context.minorVersion);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{//if selected, version doesn't matter
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(frameBuffer.flags);
	glutInitWindowPosition(window.positionX, window.positionY);
	glutInitWindowSize(window.width, window.height);

	glutCreateWindow(window.name.c_str());

	std::cout << "GLUT: Initialized" << std::endl;

	//callbacks used for rendering
	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	//init GLEW
	Init::InitGLEW::initialize();

	//cleanup
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//hopefully you can figure out what this method does
	printOpenGLInfo(window, context);
}

void InitGLUT::run()
{
	std::cout << "GLUT:\t Start Running" << std::endl;
	glutMainLoop();
}

void InitGLUT::close()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void InitGLUT::idleCallback()
{//cycle current display over in loop, does nothing
	glutPostRedisplay();
}

void InitGLUT::displayCallback()
{
	if (listener)
	{
		listener->notifyBeginFrame();
		listener->notifyDisplayFrame();

		glutSwapBuffers();

		listener->notifyEndFrame();
	}
	
}

void InitGLUT::reshapeCallback(int width, int height)
{
	if (windowInformation.isReshapeable == true)
	{
		if (listener)
		{
			listener->notifyReshape(width, height, windowInformation.width, windowInformation.height);
		}
		windowInformation.width = width;
		windowInformation.height = height;
	}
}

void InitGLUT::closeCallback()
{
	close();
}

void InitGLUT::enterFullScreen()
{
	glutFullScreen();
}

void InitGLUT::exitFullScreen()
{
	glutLeaveFullScreen();
}

void InitGLUT::printOpenGLInfo(const Core::WindowInfo &window, const Core::ContextInfo &context)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "******************************************************               ************************" << std::endl;
	std::cout << "GLUT: Initialize" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGL Version : " << version << std::endl;
}

void InitGLUT::setListener(Core::IListener* &iListener)
{
	listener = iListener;
}
