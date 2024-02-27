#include "chunk.h"

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
	float res = 16;				// resolution of noise
	float amplitude = 16;		// amplitude of noise

	float chunkPosX = (chunkPos.x * 16);
	float chunkPosY = (chunkPos.y * 16);
	float chunkPosZ = (chunkPos.z * 16);
	float seed = 6645342345;

	// create cubes
	for (int i = 0; i < intL; i++) {
		for (int j = 0; j < intW; j++) {
			for (int k = 0; k < intH; k++) {
				terrainNoise = glm::perlin(glm::vec3(
														(i + chunkPosX) / res,	// chunk X position in perlin noise
														(k + chunkPosZ) / res,	// chunk Z position in perlin noise
														seed)					// terrain seed
													) * amplitude;				// increase 0-1 value to fit 16 unit cube

				if ((int)(round(terrainNoise)) - chunkPosY  + 16 <= j)
					blocks[i][j][k] = new Cube(textures, 0x00);
				else
					blocks[i][j][k] = new Cube(textures, 0x01);
			}
		}
	}
	
	std::cout << sizeof(blocks) << std::endl;

	// set cube neigbors
	for (int i = 0; i < intL; i++) {
		for (int j = 0; j < intW; j++) {
			for (int k = 0; k < intH; k++) {

				Cube* currentCube = blocks[i][j][k];

				std::bitset<8> bit{ "00000000" };

				if (k != 0)
					if (blocks[i][j][k - 1]->getID() == 0x01)
						bit |= 0b000001;

				if (i != (int)l - 1)
					if (blocks[i + 1][j][k]->getID() == 0x01)
						bit |= 0b000010;

				if (k != (int)h - 1)
					if (blocks[i][j][k + 1]->getID() == 0x01)
						bit |= 0b000100;

				if (i != 0)
					if (blocks[i - 1][j][k]->getID() == 0x01)
						bit |= 0b001000;

				if (j != (int)w - 1)
					if (blocks[i][j + 1][k]->getID() == 0x01)
						bit |= 0b010000;

				if (j != 0)
					if (blocks[i][j - 1][k]->getID() == 0x01)
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