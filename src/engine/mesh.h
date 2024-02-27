#pragma once

#include "core/macros.h"
#include "shaders/Texture.h"
#include "shaders/VertexArray.h"
#include "shaders/IndexBuffer.h"
#include "camera.h"

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	VertexArray va;

	Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);

	void Draw(Shader& shader, Camera& camera);

private:

};