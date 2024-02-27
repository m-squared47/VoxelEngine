#include "chunkField.h"

ChunkField::ChunkField() {
	generateChunks();
}

ChunkField::~ChunkField() {

}

void ChunkField::generateChunks() {

	std::string shaderDir = std::string(__FILE__);
	std::cout << shaderDir << std::endl;
	shaderDir = shaderDir.substr(0, shaderDir.find_last_of("\\/") + 1); // Remove file name from path

	std::string srcEngine = "src\\engine\\primitives";								// Remove "src/engine/"
	size_t pos = shaderDir.find(srcEngine);
	if (pos != std::string::npos) {
		shaderDir.erase(pos, srcEngine.length());
	}

	Texture textures[]{
		Texture((shaderDir + "res\\textures\\asphalt.jpg").c_str(), "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		Texture((shaderDir + "res\\textures\\asphalt.jpg").c_str(), "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));

	std::vector<Chunk*> chunks;
	std::vector<std::vector<Chunk*>> chunkPlane;

	for (int i = 0; i < ChunkField::l; i++) {
		for (int j = 0; j < ChunkField::h; j++) {
			for (int k = 0; k < ChunkField::w; k++) {
				chunks.emplace_back(new Chunk(tex, glm::vec3(i, j, k)));	// row of chunks
				std::cout << "Generating chunk [" << i << "][" << j << "][" << k << "]" << std::endl;
			}

			chunkPlane.push_back(chunks);	// plane of chunks
			chunks.clear();
		}

		field.push_back(chunkPlane);	// cube of chunks
		chunkPlane.clear();
	}

}

float ChunkField::getNoiseValue(int x, int y, int z) {
	return glm::perlin(glm::vec3(x, y, z));
}
         
void ChunkField::Draw(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos) {

	int x = 0;
	int y = 0;
	int z = 0;

	for (auto& plane : ChunkField::field) {
		y = 0;
		for (auto& row : plane) {
			z = 0;
			for (auto& chunk : row) {
				chunk->Draw(shader, camera, lightColor, lightPos, glm::vec3(x, y, z));
				z++;
			}
			y++;
		}
		x++;
	}

}