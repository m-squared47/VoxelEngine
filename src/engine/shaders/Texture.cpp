#include "Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
	type = texType;
	// Textures
	int widthImg, heightImg, numColCh;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	glGenTextures(1, &id);
	glActiveTexture(slot);
	glBindTexture(texType, id);

	// image display setting (GL_NEAREST -> preserve pixels)
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// image display setting repeat no mirroring
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Display texture
	glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
	glGenerateMipmap(texType);

	// clean up
	stbi_image_free(bytes);
	glBindTexture(texType, 0);

}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {
	// Send to shader
	GLuint tex0Uni = glGetUniformLocation(shader.id, uniform);
	shader.Activate();
	glUniform1i(tex0Uni, unit);
}

void Texture::Bind() {
	glBindTexture(type, id);
}

void Texture::Unbind() {
	glBindTexture(type, 0);
}

void Texture::Delete() {
	glDeleteTextures(1, &id);
}