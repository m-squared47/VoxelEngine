#include "camera.h"

Camera::Camera(int width, int height, glm::vec3 Position) {
	Camera::width = width;
	Camera::height = height;
	Camera::Position = Position;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	proj = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);

	cameraMatrix = proj * view;

}

void Camera::Matrix(Shader& shader, const char* uniform) {
	glUniformMatrix4fv(glGetUniformLocation(shader.id, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::Inputs(GLFWwindow* window) {
	/* KEYS */
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {						// Forward
		Position += speed * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {						// Left
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {						// Backward
		Position += speed * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {						// Right
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {					// Up
		Position += speed * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {			// Down
		Position += speed * -Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {			// +speed
		speed = 0.5f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {		// normal speed
		speed = 0.05f;
	}

	/* MOUSE */
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {	// rotate camera with mouse

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick) {
			// set cursor to center of window
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		// get mouse window position
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = sens * (float)(mouseY - (height / 2)) / height;
		float rotY = sens * (float)(mouseX - (width / 2)) / width;

		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

		if (
			!(glm::angle(newOrientation, Up) <= glm::radians(5.0f)
			|| 
			glm::angle(newOrientation, -Up) <= glm::radians(5.0f))
		){
			Orientation = newOrientation;
		}

		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
}