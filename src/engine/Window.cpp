#include "Window.h"

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

	app = Application(window);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.1f, 0.09f, 0.24f, 1.0f);			// Specify the color of the background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the back buffer and assign the new color to it
		
		app.Update(window);
		app.Draw();
		
		
		glfwSwapBuffers(window);							// Swap the back buffer with the front buffer
		
		glfwPollEvents();									// Take care of all GLFW events
	}

	// Destroy application
	app.~Application();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}