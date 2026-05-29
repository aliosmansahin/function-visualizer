#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Graphics
{
public:
	Graphics(GLFWwindow *window);
	~Graphics();

	void Clear();

	bool GenerateVisualizationFramebuffer(GLsizei texW, GLsizei texH);
	void ResizeVisualizationFramebuffer(GLsizei texW, GLsizei texH);
	GLuint GetVisualizationTexture() { return visualizationTexture; }
	GLsizei GetVisualizationWidth() { return visualizationWidth; }
	GLsizei GetVisualizationHeight() { return visualizationHeight; }

	void BindFramebuffer() { glBindFramebuffer(GL_FRAMEBUFFER, visualizationFramebuffer); };
	void UnbindFramebuffer() { glBindFramebuffer(GL_FRAMEBUFFER, 0); };
private:
	GLuint visualizationFramebuffer = 0;
	GLuint visualizationRenderbuffer = 0;
	GLuint visualizationTexture = 0;

	GLsizei visualizationWidth = 0;
	GLsizei visualizationHeight = 0;
};