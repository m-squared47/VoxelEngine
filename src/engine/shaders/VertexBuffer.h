#pragma once

#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <vector>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 uv;
};

class VertexBuffer {
public:
	GLuint id;
	VertexBuffer();
	VertexBuffer(std::vector<Vertex>& vertices);

	void Bind();
	void Unbind();
	void Delete();

private:

};