#pragma once

#include <GL/glew.h>
#include <vector>

class IndexBuffer {
public:
	GLuint id;
	IndexBuffer(std::vector<GLuint>& indices);

	void Bind();
	void Unbind();
	void Delete();

private:

};