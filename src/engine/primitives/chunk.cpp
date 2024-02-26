#include "chunk.h"

Chunk::Chunk(std::vector<Texture> textures) {

	Chunk::textures = textures;
	generateChunk();

}

Chunk::~Chunk() {

}

void Chunk::generateChunk() {

	// create cubes
	for (int i = 0; i < (int)l; i++) {
		for (int j = 0; j < (int)w; j++) {
			for (int k = 0; k < (int)h; k++) {
				blocks[i][j][k] = new Cube(textures, 0x01);
			}
		}
	}

	// set cube neigbors
	for (int i = 0; i < (int)l; i++) {
		for (int j = 0; j < (int)w; j++) {
			for (int k = 0; k < (int)h; k++) {

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

				std::cout << "Cube at [" << i << "][" << j << "][" << k << "] faces bit value : 0b" << bit << std::endl;

				blocks[i][j][k]->setNeighbors(bit);

				blocks[i][j][k]->pushBuffers();
			}
		}
	}

}

void Chunk::Draw(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos) {

	for (int i = 0; i < (int)l; i++) {
		for (int j = 0; j < (int)w; j++) {
			for (int k = 0; k < (int)h; k++) {
				glm::vec3 chunkPos = glm::vec3(i, j, k);
				blocks[i][j][k]->Draw(shader, camera, lightColor, lightPos, chunkPos);
			}
		}
	}

}