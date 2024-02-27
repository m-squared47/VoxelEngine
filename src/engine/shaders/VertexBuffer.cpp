#include "VertexBuffer.h"

VertexBuffer::VertexBuffer() {

}

VertexBuffer::VertexBuffer(std::vector<Vertex>& vertices) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void VertexBuffer::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Delete() {
	glDeleteBuffers(1, &id);
}