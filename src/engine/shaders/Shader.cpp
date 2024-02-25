#include "Shader.h"

std::string get_file_contents(const char* filename) {
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexShader, const char* fragmentShader) {
	std::cout << "Vertex Shader Path: " << vertexShader << std::endl;
	std::cout << "Fragment Shader Path: " << fragmentShader << std::endl;

	std::string vc = get_file_contents(vertexShader);
	std::string fc = get_file_contents(fragmentShader);

	const char* vertexSource = vc.c_str();
	const char* fragmentSource = fc.c_str();

	// Create Vertex Shader Object and get its reference
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vs, 1, &vertexSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vs);
	compileErrors(vs, "VERTEX");

	// Create Fragment Shader Object and get its reference
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fs, 1, &fragmentSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fs);
	compileErrors(fs, "FRAGMENT");

	// Create Shader Program Object and get its reference
	id = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(id, vs);
	glAttachShader(id, fs);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(id);
	compileErrors(id, "PROGRAM");

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vs);
	glDeleteShader(fs);
}

void Shader::Activate() {
	glUseProgram(id);
}

void Shader::Delete() {
	glDeleteProgram(id);
}

void Shader::compileErrors(unsigned int shader, const char* type) {
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILE_ERROR for: " << type << "\n" << std::endl;
		}
		else {
			glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
			if (hasCompiled == GL_FALSE) {
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "SHADER_LINKING_ERROR for: " << type << "\n" << std::endl;
			}
		}
	}
}