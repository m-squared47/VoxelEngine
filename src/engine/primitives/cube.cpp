#include "cube.h"

Cube::Cube(std::vector<Texture>& textures) {
	Cube::textures = textures;
	applyVertAndInd();
	
	va.Bind();

	// generate buffers
	VertexBuffer vb(vertices);
	IndexBuffer ib(indices);

	// link vertex buffer attributes
	va.LinkAttrib(vb, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	va.LinkAttrib(vb, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(GLfloat)));
	va.LinkAttrib(vb, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(GLfloat)));
	va.LinkAttrib(vb, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(GLfloat)));

	// unbind to prevent modifying
	va.Unbind();
	vb.Unbind();
	ib.Unbind();
}

Cube::~Cube() {
	// TODO: Destroy Cube
}

void Cube::applyVertAndInd() {
	Cube::vertices =
	{	//				|Vertex Coords|				|Colors|					|Normals|				|Tex Coords|
		Vertex{glm::vec3( l, -h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f,-1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-l, -h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f,-1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(-l,  h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f,-1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3( l,  h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f,-1.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{glm::vec3( l, -h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3( l, -h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( l,  h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3( l,  h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{glm::vec3(-l, -h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3( l, -h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( l,  h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(-l,  h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{glm::vec3(-l, -h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-l, -h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(-l,  h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(-l,  h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{glm::vec3( l,  h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-l,  h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(-l,  h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3( l,  h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{glm::vec3(-l, -h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f,-1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3( l, -h, -w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f,-1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( l, -h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f,-1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(-l, -h,  w),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3( 0.0f,-1.0f, 0.0f), glm::vec2(1.0f, 0.0f)}
	};

	Cube::indices = {
		0, 3, 2,	// Front Lower Tri
		0, 1, 2,	// Front Upper Tri

		4, 6, 7,	// Right Lower Tri
		4, 5, 6,	// Right Upper Tri

		8, 11, 10,	// Back Lower Tri
		8, 9, 10,	// Back Upper Tri

		12, 15, 14,	// Left Lower Tri
		12, 13, 14,	// Left Upper Tri

		16, 19, 18,	// Top Lower Tri
		16, 17, 18,	// Top Upper Tri

		20, 23, 22,	// Bottom Lower Tri
		20, 21, 22 	// Bottom Upper Tri
	};
}

void Cube::faceVectors() {
	// TODO: face culling
}

void Cube::Update() {
	// TODO: update cube
}

void Cube::Draw(Shader& shader, Camera& camera, glm::vec4 lightColor, glm::vec3 lightPos, glm::vec3 chunkPos) {

	glm::vec3 offset = glm::vec3(Cube::l * 3);
	glm::vec3 objPos = chunkPos * offset;			// cube
	glm::mat4 objModel = glm::mat4(1.0f);
	objModel = glm::translate(objModel, objPos);

	shader.Activate();

	glUniformMatrix4fv(glGetUniformLocation(shader.id, "model"), 1, GL_FALSE, glm::value_ptr(objModel));
	glUniform4f(glGetUniformLocation(shader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shader.id, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	va.Bind();

	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;

	for (unsigned int i = 0; i < textures.size(); i++) {
		std::string num;
		std::string type = textures[i].type;

		if (type == "diffuse") num = std::to_string(numDiffuse++);
		else
			if (type == "specular") num = std::to_string(numSpecular++);

		textures[i].texUnit(shader, (type + num).c_str(), i);
		textures[i].Bind();
	}

	glUniform3f(glGetUniformLocation(shader.id, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
