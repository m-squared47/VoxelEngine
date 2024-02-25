#pragma once

#include <GL/glew.h>
#include "VertexBuffer.h"

class VertexArray {
public:
	GLuint id;
	VertexArray();

	void LinkAttrib(VertexBuffer& vb, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();

private:

};