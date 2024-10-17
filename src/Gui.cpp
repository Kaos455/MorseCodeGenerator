#include "Gui.h"

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
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return false;
	}
	std::cout << "Setup: GLFW Initialized" << std::endl;
	return true;
}

bool Gui::initGLAD()
{
	if (!gladLoadGL()) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return false;
	}
	std::cout << "Setup: GLAD Initialized" << std::endl;
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
		std::cerr << "Failed to initialize ImGui with GLFW and OpenGL3" << std::endl;
		return false;
	}
	if (!ImGui_ImplOpenGL3_Init("#version 330")) { // Initialise ImGui with OpenGL3
		std::cerr << "Failed to initialize ImGui with OpenGL3" << std::endl;
		return false;
	}
	std::cout << "Setup: ImGui Initialized" << std::endl;
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
		imGuiRender();

		// Rendering
		ImGui::Render();
		glViewport(0, 0, m_width, m_height);
		glClearColor(0.45f, 0.55f, 0.60f, 0.00f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(m_window);
	}
}

void Gui::imGuiRender()
{
	static int incAmount = 1;
	static int counter = 0;
	// Start ImGui Frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// This block took from https://github.com/ocornut/imgui/issues/3541
	// This block is used to make the ImGui m_window fullscreen and Resize with the GLFW m_window
	ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
	ImGui::SetNextWindowSize(ImVec2(640.0f, 720.0f));
	ImGui::Begin("Input Test", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);
	// 
	if (ImGui::Button("Increment"))
		counter += incAmount;
	ImGui::SliderInt("Volume", &incAmount, 0., 100);
	if (ImGui::Button("Play Sound"))
		m_eventListener->addEvent(event::EventType::EVENT_BUTTON_CLICKED);
	ImGui::End();

	ImGui::SetNextWindowPos(ImVec2(640.0f, 0.0f));
	ImGui::SetNextWindowSize(ImVec2(640.0f, 720.0f));
	ImGui::Begin("Output Test", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);
	ImGui::Text("Counter: %d", counter);
	ImGui::Text("Increment Amount: %d", incAmount);
}