#include "graphics.h"

#include <iostream>

Graphics::Graphics(GLFWwindow *window)
{
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "glad loader failed" << std::endl;
		return;
	}
}

Graphics::~Graphics()
{
}

void Graphics::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Consider adding depth buffer bit for 3d space

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
