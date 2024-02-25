#include "VertexArray.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &id);
}

void VertexArray::LinkAttrib(VertexBuffer& vb, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
	vb.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vb.Unbind();
}

void VertexArray::Bind() {
	glBindVertexArray(id);
}

void VertexArray::Unbind() {
	glBindVertexArray(0);
}

void VertexArray::Delete() {
	glDeleteVertexArrays(1, &id);
}