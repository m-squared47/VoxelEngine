#pragma once

#include <GL/glew.h>

class VertexBuffer {
public:
	GLuint id;
	VertexBuffer(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();

private:

};