#pragma once

#include "graphics.h"

#include <memory>

class Window {
public:
	Window();
	~Window();
	GLFWwindow* GetWindow();
	std::shared_ptr<Graphics> GetGraphics();

	void Run();
private:
	GLFWwindow* window = nullptr;
	int width = 1024, height = 768;
	std::shared_ptr<Graphics> graphics;
};