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
	glDeleteFramebuffers(1, &visualizationFramebuffer);
	glDeleteTextures(1, &visualizationTexture);
	glDeleteRenderbuffers(1, &visualizationRenderbuffer);
}

void Graphics::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Consider adding depth buffer bit for 3d space

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

bool Graphics::GenerateVisualizationFramebuffer(GLsizei texW, GLsizei texH)
{
	glGenBuffers(1, &visualizationFramebuffer);
	glBindBuffer(GL_FRAMEBUFFER, visualizationFramebuffer);

	glGenTextures(1, &visualizationTexture);
	glBindTexture(GL_TEXTURE_2D, visualizationTexture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texW, texH, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, visualizationTexture, 0);

	if (glCheckFramebufferStatus(visualizationFramebuffer) == GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Visualization framebuffer generation	 failure" << std::endl;
		return false;
	}
	
	glGenRenderbuffers(1, &visualizationRenderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, visualizationRenderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, texW, texH);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, visualizationRenderbuffer);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	visualizationWidth = texW;
	visualizationHeight = texH;

	return true;
}

void Graphics::ResizeVisualizationFramebuffer(GLsizei texW, GLsizei texH)
{
	if (texW <= 0 || texH <= 0) return;

	glBindFramebuffer(GL_FRAMEBUFFER, visualizationFramebuffer);

	glBindTexture(GL_TEXTURE_2D, visualizationTexture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texW, texH, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, visualizationTexture, 0);

	glBindRenderbuffer(GL_RENDERBUFFER, visualizationRenderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, texW, texH);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, visualizationRenderbuffer);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	visualizationWidth = texW;
	visualizationHeight = texH;
}
