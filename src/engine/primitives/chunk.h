#pragma once

#include "cube.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/noise.hpp>

class Chunk {
public:
	Chunk(std::vector<Texture> textures, glm::vec3 chunkPos);
	~Chunk();

	// draw all blocks
	void Draw(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos, glm::vec3 chunkPos);

private:
	unsigned char l = 0x10;	// chunk is 16 in legth
	unsigned char w = 0x10;	// chunk is 16 in width
	unsigned char h = 0x10;	// chunk is 16 in height

	Cube* blocks[16][16][16];		// cube array for blocks in a chunk
	std::vector<Texture> textures;	// block textures

	// fills blocks array with cubes
	void generateChunk(glm::vec3 chunkPos);

};