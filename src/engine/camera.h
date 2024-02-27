#pragma once
#define GLM_ENABLE_EXPERIMENTAL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtx/rotate_vector.hpp>
#include <GLM/gtx/vector_angle.hpp>

#include "shaders/shader.h"

class Camera {
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(-1.0f, 0.0f, 0.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	// prevents camera jumping
	bool firstClick = true;

	// width and height of window
	int width;
	int height;

	// camera speed and mouse sensitivity
	float speed = 0.05f;
	float sens = 10.0f;

	Camera(int width, int height, glm::vec3 Position);

	// update and send camera matrix to vertex shader
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	void Matrix(Shader& shader, const char* uniform);
	// polls key and mouse events for camera inputs
	void Inputs(GLFWwindow* window);

private:

};