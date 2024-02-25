#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "shaders/VertexBuffer.h"
#include "shaders/VertexArray.h"
#include "shaders/IndexBuffer.h"
#include "shaders/Shader.h"
#include "shaders/Texture.h"

#include "camera.h"

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
};
