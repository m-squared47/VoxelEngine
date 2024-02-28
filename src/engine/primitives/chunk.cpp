#include "chunk.h"

#define TERRAIN_NOISE(i, k, x, z, seed, res, amplitude) glm::perlin(glm::vec3((i + x) / res, (k + z) / res, seed)) * amplitude			

Chunk::Chunk(std::vector<Texture> textures, glm::vec3 chunkPos) {

	Chunk::textures = textures;
	generateChunk(chunkPos);

}

Chunk::~Chunk() {

}

void Chunk::generateChunk(glm::vec3 chunkPos) {

	// cast lwh bit values to int
	int intL = static_cast<int>(l);
	int intW = static_cast<int>(w);
	int intH = static_cast<int>(h);

	float terrainNoise;			// noise value
	float res = 32;				// resolution of noise
	float amplitude = 32;		// amplitude of noise

	float chunkPosX = (chunkPos.x * intL);
	float chunkPosY = (chunkPos.y * intW);
	float chunkPosZ = (chunkPos.z * intH);
	float seed = 47;

	// create cubes
	for (int i = 0; i < intL; i++) {
		for (int j = 0; j < intW; j++) {
			for (int k = 0; k < intH; k++) {

				if ((int)(TERRAIN_NOISE(i, k, chunkPosX, chunkPosZ, seed, res, amplitude) - chunkPosY + amplitude) <= j)
					blocks[i][j][k] = new Cube(textures, 0x00);
				else
					blocks[i][j][k] = new Cube(textures, 0x01);
			}
		}
	}

	// set cube neigbors
	for (int i = 0; i < intL; i++) {
		for (int j = 0; j < intW; j++) {
			for (int k = 0; k < intH; k++) {

				Cube* currentCube = blocks[i][j][k];

				std::bitset<8> bit{ "00000000" };

				if (k != 0)
				{
					if (blocks[i][j][k - 1]->getID() == 0x01) 
						bit |= 0b000001;
				}
				else if ((int)(TERRAIN_NOISE(i, k - 1, chunkPosX, chunkPosZ, seed, res, amplitude) - chunkPosY + amplitude) > j)	// brute force face culling (REPLACE THIS FOR OBSERVING NEIGHBOR CHUNKS)
					bit |= 0b000001;

				if (i != (int)l - 1)
				{
					if (blocks[i + 1][j][k]->getID() == 0x01)
						bit |= 0b000010;
				}
				else if ((int)(TERRAIN_NOISE(i + 1, k, chunkPosX, chunkPosZ, seed, res, amplitude) - chunkPosY + amplitude) > j)
					bit |= 0b000010;

				if (k != (int)h - 1)
				{
					if (blocks[i][j][k + 1]->getID() == 0x01)
						bit |= 0b000100;
				}
				else if ((int)(TERRAIN_NOISE(i, k + 1, chunkPosX, chunkPosZ, seed, res, amplitude) - chunkPosY + amplitude) > j)
					bit |= 0b000100;

				if (i != 0)
				{
					if (blocks[i - 1][j][k]->getID() == 0x01)
						bit |= 0b001000;
				}
				else if ((int)(TERRAIN_NOISE(i - 1, k, chunkPosX, chunkPosZ, seed, res, amplitude) - chunkPosY + amplitude) > j)
					bit |= 0b001000;

				if (j != (int)w - 1)
				{
					if (blocks[i][j + 1][k]->getID() == 0x01)
						bit |= 0b010000;
				}
				else if ((int)(TERRAIN_NOISE(i, k, chunkPosX, chunkPosZ, seed, res, amplitude) - ((chunkPos.y + 1) * intH) + amplitude) > 0)
					bit |= 0b010000;

				if (j != 0)
				{
					if (blocks[i][j - 1][k]->getID() == 0x01)
						bit |= 0b100000;
				}
				else if ((int)(TERRAIN_NOISE(i, k, chunkPosX, chunkPosZ, seed, res, amplitude) - chunkPosY + amplitude) > j)
					bit |= 0b100000;

				currentCube->setNeighbors(bit);
				currentCube->pushBuffers();
			}
		}
	}

}

void Chunk::Draw(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos, glm::vec3 chunkPos) {

	float chunkPosX = (chunkPos.x * 16);
	float chunkPosY = (chunkPos.y * 16);
	float chunkPosZ = (chunkPos.z * 16);


	for (int i = 0; i < (int)l; i++) {
		for (int j = 0; j < (int)w; j++) {
			for (int k = 0; k < (int)h; k++) {

				// don't render air blocks
				if (blocks[i][j][k]->getID() == 0x0) { continue; }
				if (blocks[i][j][k]->getNeighbors() == std::bitset<8>{"00111111"}) { continue; }

				glm::vec3 cubePos = glm::vec3(
												i + chunkPosX, 
												j + chunkPosY, 
												k + chunkPosZ
											);

				blocks[i][j][k]->Draw(shader, camera, lightColor, lightPos, cubePos);
			}
		}
	}

}