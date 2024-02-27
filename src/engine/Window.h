#pragma once

#include "application.h"
#include "optick.h"

struct {
	unsigned int width;
	unsigned int height;
} windowAttrib;

class Window {
public:
	Window(unsigned int w, unsigned int h);
	~Window();
private:
	Application app;

	int CreateWindow();
	GLFWwindow* window;
};
