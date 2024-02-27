#pragma once

#include <GL/glew.h>
#include <vector>

class IndexBuffer {
public:
	GLuint id;
	IndexBuffer();
	IndexBuffer(std::vector<GLuint>& indices);

	void Bind();
	void Unbind();
	void Delete();

private:

};