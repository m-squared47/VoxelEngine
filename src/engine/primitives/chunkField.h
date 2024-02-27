#pragma once

#include "chunk.h"

class ChunkField {
public:

	ChunkField();
	~ChunkField();

	float getNoiseValue(int x, int y, int z);

	void Draw(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos);

private:

	int l = 5;
	int h = 2;
	int w = 5;

	std::vector<std::vector<::std::vector<Chunk*>>> field;

	void generateChunks();

};