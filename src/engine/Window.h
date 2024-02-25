#pragma once
#include "mesh.h"

struct {
	unsigned int width;
	unsigned int height;
} windowAttrib;

class Window {
public:
	Window(unsigned int w, unsigned int h);
	virtual ~Window();
private:
	int CreateWindow();
	void handleShaders();
	GLFWwindow* window;
};
