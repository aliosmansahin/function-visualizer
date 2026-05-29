#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "imgui_internal.h"

class Interface {
public:
	Interface(GLFWwindow* window);
	~Interface();

	void NewFrame();
	void Render();

	void DrawDockSpace();

	void DrawVisualizationWindow(unsigned int framebufferTexture);

	ImVec2 GetViewportPanelSize() { return viewportPanelSize; }
private:
	ImGuiID dockspaceId;
	ImVec2 viewportPanelSize;
};