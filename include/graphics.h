#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Graphics
{
public:
	Graphics(GLFWwindow *window);
	~Graphics();

	void Clear();

private:
};