#include <iostream>
#include <memory>

#include "window.h"

int main() {
	std::cout << "Function Visualizer!" << std::endl;

	std::shared_ptr<Window> window = std::make_shared<Window>();
	if (!window->GetWindow())
		return -1;

	window->Run();

	return 0;
}