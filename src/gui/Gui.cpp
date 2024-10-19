#include "gui/Gui.h"

// Constructor for GUI
Gui::Gui(std::shared_ptr<event::EventListener> eventListener) : m_eventListener(eventListener), m_width(1280), m_height(720)
{
	if (!initGLFW()) return; // Initialise GLFW

	// Initialise m_window
	m_window = glfwCreateWindow(1280, 720, "Morse Code Generator", NULL, NULL);
	if (!m_window)
	{
		std::cerr << "Failed to create GLFW m_window" << std::endl;
		glfwTerminate(); // Terminates GLFW
		return;
	}

	glfwMakeContextCurrent(m_window); // Tells OpenGL to make m_window the current context of OpenGL

	if (!initGLAD()) return; // Initialise GLAD
	if (!initImGui()) return; // Initialise ImGui

	changeVSync(1);
}

// Destructor for GUI
Gui::~Gui()
{
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown(); // Shutdown ImGui OpenGL3
	ImGui_ImplGlfw_Shutdown(); // Shutdown ImGui GLFW
	ImGui::DestroyContext(); // Destroy ImGui context

	glfwDestroyWindow(m_window); // Destroy GLFW m_window -> handles cleanup of pointer for m_window
	glfwTerminate(); // Terminate GLFW
}

// Initialisation functions for GUI
bool Gui::initGLFW()
{
	if (!glfwInit()) {
		std::cerr << "Failed to initialise GLFW" << std::endl;
		return false;
	}
	std::cout << "Setup: GLFW Initialised" << std::endl;
	return true;
}

bool Gui::initGLAD()
{
	if (!gladLoadGL()) {
		std::cerr << "Failed to initialise GLAD" << std::endl;
		return false;
	}
	std::cout << "Setup: GLAD initialised" << std::endl;
	return true;
}


bool Gui::initImGui()
{
	// Init ImGui
	IMGUI_CHECKVERSION(); // Check ImGui version to prevent version mismatch at compile time
	ImGui::CreateContext(); // Create ImGui context
	ImGuiIO& io = ImGui::GetIO(); // Create IO object Reference

	// Setup ImGui with GLFW and OpenGL3
	if (!ImGui_ImplGlfw_InitForOpenGL(m_window, true)) { // Initialise ImGui with GLFW and tell it to handle events
		std::cerr << "Failed to initialise ImGui with GLFW and OpenGL3" << std::endl;
		return false;
	}
	if (!ImGui_ImplOpenGL3_Init("#version 330")) { // Initialise ImGui with OpenGL3
		std::cerr << "Failed to initialise ImGui with OpenGL3" << std::endl;
		return false;
	}
	std::cout << "Setup: ImGui Initialised" << std::endl;
	return true;
}
// End of initialisation functions for GUI

// Useful functions for GUI
void Gui::changeVSync(bool trigger)
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

// Main functions for GUI Rendering
bool Gui::windowShouldClose()
{
	return glfwWindowShouldClose(m_window);
}

void Gui::render()
{
	if (!glfwWindowShouldClose(m_window)) {
		glfwWaitEvents();

		// Render ImGui
		m_guiImGui->imGuiRender();

		// Rendering
		ImGui::Render();
		glViewport(0, 0, m_width, m_height);
		glClearColor(0.45f, 0.55f, 0.60f, 0.00f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(m_window);
	}
}