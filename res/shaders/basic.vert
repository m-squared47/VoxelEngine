#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aColor;
layout (location = 3) in vec2 aTex;

out vec3 currPos;	// current position of the model output for frag
out vec3 Normal;	// normal output for frag shader
out vec3 color;		// color output to fragment shader
out vec2 texCoord;	// texture coord output to fragment shader

uniform mat4 camMatrix;	// import camera matrix
uniform mat4 model;		// import model matrix

void main()
{

	currPos = vec3(model * vec4(aPos, 1.0f));
	Normal = aNormal;
	color = aColor;
	texCoord = aTex;
	gl_Position = camMatrix * vec4(currPos, 1.0);

}