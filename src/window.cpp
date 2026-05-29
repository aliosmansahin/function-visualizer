#include "window.h"

#include <iostream>

Window::Window()
{
	if (glfwInit() == GLFW_FALSE)
	{
		std::cerr << "Couldn't initialize glfw" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(width, height, "Function Visualizer", NULL, NULL);
	if (!window)
	{
		std::cerr << "Couldn't create glfw window" << std::endl;
		glfwTerminate();
		return;
	}

	graphics = std::make_shared<Graphics>(window);
}

Window::~Window()
{
	glfwTerminate();
}

GLFWwindow *Window::GetWindow()
{
	return window;
}

std::shared_ptr<Graphics> Window::GetGraphics()
{
	return graphics;
}

void Window::Run()
{
	while (!glfwWindowShouldClose(window))
	{
		/* Update and draw code here */

		graphics->Clear();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}