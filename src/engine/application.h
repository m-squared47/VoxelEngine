#pragma once 

#include "mesh.h"
#include "primitives/chunkField.h"

class Application {

public:
	Application();
	Application(GLFWwindow* window);
	~Application();

	void Update(GLFWwindow* window);	// Update all elements
	void Draw();	// Draw all elements

private:
	int winW, winH;	// width and height of current window

};