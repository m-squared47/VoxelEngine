#pragma once
#include "../mesh.h"
#include <bitset>

enum faces {
	front	= 0,
	right	= 1,
	back	= 2,
	left	= 3,
	top		= 4,
	bottom	= 5
};

class Cube{
public:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	VertexArray va;

	Cube(std::vector<Texture>& textures, unsigned char ID);
	virtual ~Cube();

	unsigned char getID() const;
	std::bitset<8> getNeighbors() const;
	void setNeighbors(std::bitset<8> bit);
	void pushBuffers();
	void Update();
	void Draw(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos, glm::vec3 chunkPos);

private:
	// dimensions of a cube
	float l = 0.1f;
	float h = 0.1f;
	float w = 0.1f;

	unsigned char ID;	// block ID

	std::vector<std::vector<Vertex>> facesVert;		// vertexes by face
	std::vector<std::vector<GLuint>> facesInd;		// indices by face
	std::bitset<8> renderFace;						// For face culling. Tells if a face should be rendered

	void applyVertAndInd();							// generates vertexes and indices
	void applyUniforms(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos, glm::vec3 chunkPos);	// Send uniforms to the shader
	void faceVectors();								// splits the vectors and indexes with their respective face
	
};