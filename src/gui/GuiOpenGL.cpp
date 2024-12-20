#include "gui/GuiOpenGL.h"

// Constructor for OpenGL
GuiOpenGL::GuiOpenGL()
{
	if (!initOpenGL()) // Initialise OpenGL
		std::cerr << "Failed to initialise OpenGL" << std::endl;
	changeVSync(1); // Enable VSync
}

GuiOpenGL::~GuiOpenGL()
{
	glfwDestroyWindow(m_window); // Destroy GLFW m_window -> handles cleanup of pointer for m_window
	glfwTerminate(); // Terminate GLFW
}

// Initialise OpenGL 
bool GuiOpenGL::initOpenGL()
{
	if (!initGLFW()) // Initialise GLFW
		return false; 
	if (!initWindow()) // Initialise GLFW m_window
		return false;
	glfwMakeContextCurrent(m_window); // Tells OpenGL to make m_window the current context of OpenGL
	if (!initGLAD()) // Initialise GLAD
		return false;
	return true;
}

// Initialise GLFW
bool GuiOpenGL::initGLFW()
{
	if (!glfwInit()) {
		std::cerr << "Failed to initialise GLFW" << std::endl;
		return false;
	}
	std::cout << "Setup: GLFW Initialised" << std::endl;
	return true;
}

// Initialise GLAD
bool GuiOpenGL::initGLAD()
{
	if (!gladLoadGL()) {
		std::cerr << "Failed to initialise GLAD" << std::endl;
		return false;
	}
	std::cout << "Setup: GLAD initialised" << std::endl;
	return true;
}

bool GuiOpenGL::initWindow()
{
	m_window = glfwCreateWindow(1280, 720, "Morse Code Generator", NULL, NULL); // Create GLFW m_window
	if (!m_window) // Window Checker
	{
		std::cerr << "Failed to create GLFW m_window" << std::endl;
		glfwTerminate(); // Terminates GLFW
		return false;
	}
	return true;
}

// Change VSync setting
void GuiOpenGL::changeVSync(bool trigger)
{
	if (trigger) {
		glfwSwapInterval(1); // Enable vsync
		std::cout << "Setting: VSync Enabled" << std::endl;
	}
	else {
		glfwSwapInterval(0); // Disable vsync
		std::cout << "Setting: VSync Disabled" << std::endl;
	}
}

// Get the GLFWwindow pointer
GLFWwindow* GuiOpenGL::getWindow()
{
	return m_window;
}

// Render Functions
void GuiOpenGL::preRender()
{
	glfwWaitEvents(); // Only OpenGL thing that needs to happen before rendering
}

void GuiOpenGL::render()
{
	glViewport(0, 0, 1280, 720);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GuiOpenGL::postRender()
{
	glfwSwapBuffers(m_window);
}