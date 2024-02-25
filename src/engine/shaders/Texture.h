#pragma once

#include <GL/glew.h>
#include <stb_image.h>

#include "shader.h"

class Texture {
public:
	GLuint id;
	const char* type;
	GLuint unit;

	Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType);

	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
private:

};