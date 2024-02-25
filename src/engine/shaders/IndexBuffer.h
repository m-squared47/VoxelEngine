#pragma once

#include <GL/glew.h>

class IndexBuffer {
public:
	GLuint id;
	IndexBuffer(GLuint* indices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();

private:

};