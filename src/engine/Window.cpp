#include "Window.h"

//LightCube
Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
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
	glfwDestroyWindow(window);
}

/* Create GL context and link with GLEW             */
/* Creates a window and outputs working GL version  */
int Window::CreateWindow() {

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
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	/* Check if GL init -> GL init, display current version */
	if (glewInit() != GLEW_OK)
		std::cout << "Error glewInit" << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;

	// set window viewport
	glViewport(0, 0, windowAttrib.width, windowAttrib.height);

	// find path to shaders
	std::string shaderDir = std::string(__FILE__);
	shaderDir = shaderDir.substr(0, shaderDir.find_last_of("\\/") + 1); // Remove file name from path

	std::string srcEngine = "src\\engine";								// Remove "src/engine/"
	size_t pos = shaderDir.find(srcEngine);
	if (pos != std::string::npos) {
		shaderDir.erase(pos, srcEngine.length());
	}

	Texture textures[]{
		Texture((shaderDir + "res\\textures\\asphalt.jpg").c_str(), "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		Texture((shaderDir + "res\\textures\\planksSpec.png").c_str(), "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	// shader for cube
	std::string vertexShaderPath = shaderDir + "res\\shaders\\basic.vert";
	std::string fragmentShaderPath = shaderDir + "res\\shaders\\basic.frag";
	Shader shader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

	// creat cube object
	std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	ChunkField terrain = ChunkField();

	// shader for light
	std::string lightVertexShaderPath = shaderDir + "res\\shaders\\light.vert";
	std::string lightFragmentShaderPath = shaderDir + "res\\shaders\\light.frag";
	Shader lightShader(lightVertexShaderPath.c_str(), lightFragmentShaderPath.c_str());

	std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	Mesh light(lightVerts, lightInd, tex);

	// object models
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);	// light
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.id, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	// enable depth buffer
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Camera object
	Camera camera(windowAttrib.width, windowAttrib.height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.1f, 0.09f, 0.24f, 1.0f);			// Specify the color of the background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the back buffer and assign the new color to it
		
		camera.Inputs(window);								// Poll input events

		camera.updateMatrix(								// update Camera
			45.0f, 											// FOV,
			0.1f, 											// nearPlane,
			100.0f  										// farPlane
		);

		terrain.Draw(shader, camera, lightColor, lightPos);	// draw objects
		light.Draw(lightShader, camera);
		
		glfwSwapBuffers(window);							// Swap the back buffer with the front buffer
		
		glfwPollEvents();									// Take care of all GLFW events
	}



	// Delete all the objects we've created
	shader.Delete();
	lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}