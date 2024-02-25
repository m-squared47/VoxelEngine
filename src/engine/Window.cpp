#include "Window.h"

// Vertices coordinates
// CUBE
GLfloat vertices[] =
{
	//	Coords				// Colors				// Texture Coords	 // Normals
	-0.5f,  0.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,          0.0f, 0.0f, -1.0f,    // Front LL       0
	-0.5f,  1.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,          0.0f, 0.0f, -1.0f,    // Front UL       1
	 0.5f,  1.0f, -0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,          0.0f, 0.0f, -1.0f,    // Front UR       2
	 0.5f,  0.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          0.0f, 0.0f, -1.0f,    // Front LR       3

	 0.5f,  0.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,          1.0f, 0.0f, 0.0f,    // Right LL        4
	 0.5f,  1.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,          1.0f, 0.0f, 0.0f,    // Right UL        5
	 0.5f,  1.0f,  0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,          1.0f, 0.0f, 0.0f,    // Right UR        6
	 0.5f,  0.0f,  0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          1.0f, 0.0f, 0.0f,    // Right LR        7

	-0.5f,  0.0f,  0.5f,    0.8f, 0.3f, 0.2f,       1.0f, 0.0f,          0.0f, 0.0f, 1.0f,    // Back LL         8
	-0.5f,  1.0f,  0.5f,    0.8f, 0.3f, 0.2f,       1.0f, 1.0f,          0.0f, 0.0f, 1.0f,    // Back UL         9
	 0.5f,  1.0f,  0.5f,    1.0f, 0.6f, 0.32f,      0.0f, 1.0f,          0.0f, 0.0f, 1.0f,    // Back UR         10
	 0.5f,  0.0f,  0.5f,    0.9f, 0.45f, 0.17f,     0.0f, 0.0f,          0.0f, 0.0f, 1.0f,    // Back LR         11
																											     
	-0.5f,  0.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,         -1.0f, 0.0f, 0.0f,    // Left LL         12
	-0.5f,  1.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,         -1.0f, 0.0f, 0.0f,    // Left UL         13
	-0.5f,  1.0f, -0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,         -1.0f, 0.0f, 0.0f,    // Left UR         14
	-0.5f,  0.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,         -1.0f, 0.0f, 0.0f,    // Left LR         15
																											     
	-0.5f,  1.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,          0.0f, 1.0f, 0.0f,    // Top LL          16
	-0.5f,  1.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,          0.0f, 1.0f, 0.0f,    // Top UL          17
	 0.5f,  1.0f,  0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,          0.0f, 1.0f, 0.0f,    // Top UR          18
	 0.5f,  1.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          0.0f, 1.0f, 0.0f,    // Top LR          19
																											     
	-0.5f,  0.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,          0.0f, -1.0f, 0.0f,   // Bottom LL       20
	-0.5f,  0.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,          0.0f, -1.0f, 0.0f,   // Bottom UL       21
	 0.5f,  0.0f,  0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,          0.0f, -1.0f, 0.0f,   // Bottom UR       22
	 0.5f,  0.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          0.0f, -1.0f, 0.0f    // Bottom LR       23
};

// Indices for vertices order
GLuint indices[] =
{
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

GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};


/* Constructor */
Window::Window(unsigned int w, unsigned int h) {
    windowAttrib.width = w;
    windowAttrib.height = h;
    Window::CreateWindow();
}

/* Destructor */
Window::~Window() {
    // code
}

/* Create GL context and link with GLEW             */
/* Creates a window and outputs working GL version  */
int Window::CreateWindow() {

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Failed to Initialize GLFW. Exiting Application." << std::endl;
		return -1;
	}

	/* Using OpenGL 4.6.0 Core */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(windowAttrib.width, windowAttrib.height, "VoxelEngine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error glewInit" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	glViewport(0, 0, windowAttrib.width, windowAttrib.height);

	// find path to shaders
	std::string shaderDir = std::string(__FILE__);
	shaderDir = shaderDir.substr(0, shaderDir.find_last_of("\\/") + 1); // Remove file name from path

	std::string srcEngine = "src\\engine";								// Remove "src/engine/"
	size_t pos = shaderDir.find(srcEngine);
	if (pos != std::string::npos) {
		shaderDir.erase(pos, srcEngine.length());
	}

	// shader for cube
	std::string vertexShaderPath = shaderDir + "res\\shaders\\basic.vert";
	std::string fragmentShaderPath = shaderDir + "res\\shaders\\basic.frag";

	Shader shader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

	VertexArray vertexArray1;
	vertexArray1.Bind();

	VertexBuffer vertexBuffer1(vertices, sizeof(vertices));
	IndexBuffer indexBuffer1(indices, sizeof(indices));

	vertexArray1.LinkAttrib(vertexBuffer1, 0, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)0);
	vertexArray1.LinkAttrib(vertexBuffer1, 1, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	vertexArray1.LinkAttrib(vertexBuffer1, 2, 2, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	vertexArray1.LinkAttrib(vertexBuffer1, 3, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(8 * sizeof(GLfloat)));
	vertexArray1.Unbind();
	vertexBuffer1.Unbind();
	indexBuffer1.Unbind();

	// shader for light
	std::string lightVertexShaderPath = shaderDir + "res\\shaders\\light.vert";
	std::string lightFragmentShaderPath = shaderDir + "res\\shaders\\light.frag";

	Shader lightShader(lightVertexShaderPath.c_str(), lightFragmentShaderPath.c_str());

	VertexArray lightVertexArray;
	lightVertexArray.Bind();

	VertexBuffer lightVertexBuffer(lightVertices, sizeof(lightVertices));
	IndexBuffer lightIndexBuffer(lightIndices, sizeof(lightIndices));

	lightVertexArray.LinkAttrib(lightVertexBuffer, 0, 3, GL_FLOAT, 3 * sizeof(GLfloat), (void*)0);

	lightVertexArray.Unbind();
	lightVertexBuffer.Unbind();
	lightIndexBuffer.Unbind();

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 0.25f);

	// model matrix
	glm::vec3 lightPos = glm::vec3(1.0f, 1.5f, 1.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	// cube model matrix
	glm::vec3 cubePos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 cubeModel = glm::mat4(1.0f);
	cubeModel = glm::translate(cubeModel, cubePos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.id, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.id, "model"), 1, GL_FALSE, glm::value_ptr(cubeModel));
	glUniform4f(glGetUniformLocation(shader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shader.id, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// Texture
	Texture asphalt((shaderDir + "res\\textures\\asphalt.jpg").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	asphalt.texUnit(shader, "tex0", 0);

	// enable depth buffer
	glEnable(GL_DEPTH_TEST);

	// Camera object
	Camera camera(windowAttrib.width, windowAttrib.height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);			// Specify the color of the background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the back buffer and assign the new color to it
		
		camera.Inputs(window);								// Poll input events

		camera.updateMatrix(								// update Camera
			45.0f, 											// FOV,
			0.1f, 											// nearPlane,
			100.0f  										// farPlane
		);

		shader.Activate();									// Use Basic shader

		glUniform3f(										// send camera position to vertex shader
			glGetUniformLocation(shader.id, "camPos"),		// GL get uniform call
			camera.Position.x, 								// Camera X-pos
			camera.Position.y, 								// Camera Y-pos
			camera.Position.z								// Camera Z-pos
		);

		camera.Matrix(										// Send camera matrix to vertex shader
			shader,											// shader source,
			"camMatrix"										// uniform
		);

		asphalt.Bind();										// Bind texture for OpenGL to use
		vertexArray1.Bind();								// Bind the VA for OpenGL to use
		
		glDrawElements(										// Draw 
			GL_TRIANGLES,									// primitives,  
			sizeof(indices) / sizeof(int), 					// number of indices,
			GL_UNSIGNED_INT, 								// datatype of indices,
			0												// index of indices
		);	

		lightShader.Activate();								// Use Light shader
		camera.Matrix(lightShader, "camMatrix");			// Export camera matrix to light shader
		lightVertexArray.Bind();							// Bind light VA for OpenGL to use
		glDrawElements(										// Draw ...
			GL_TRIANGLES, 
			sizeof(lightIndices) / sizeof(GLint), 
			GL_UNSIGNED_INT, 
			0
		);
		
		glfwSwapBuffers(window);							// Swap the back buffer with the front buffer
		
		glfwPollEvents();									// Take care of all GLFW events
	}



	// Delete all the objects we've created
	vertexArray1.Delete();
	vertexBuffer1.Delete();
	indexBuffer1.Delete();
	asphalt.Delete();
	shader.Delete();
	lightVertexArray.Delete();
	lightVertexBuffer.Delete();
	lightIndexBuffer.Delete();
	lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}