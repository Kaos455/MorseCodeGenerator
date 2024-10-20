#include "gui/GuiImGui.h"

// Constructor for ImGui Gui
GuiImGui::GuiImGui(GLFWwindow* window, std::shared_ptr<event::EventListener> eventListener) :
	m_window(window), m_eventListener(eventListener)
{
	if (!initImGui()) {
		std::cerr << "Setup: Failed to initialise ImGui" << std::endl;
	}
}

GuiImGui::~GuiImGui()
{
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown(); // Shutdown ImGui OpenGL3
	ImGui_ImplGlfw_Shutdown(); // Shutdown ImGui GLFW
	ImGui::DestroyContext(); // Destroy ImGui context
}

void GuiImGui::renderWindow()
{
	// Start ImGui Frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// This block took from https://github.com/ocornut/imgui/issues/3541
	// This block is used to make the ImGui m_window fullscreen and Resize with the GLFW m_window
	ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
	ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize));
	ImGui::Begin("Input Test", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
	ImGui::End();
}

bool GuiImGui::initImGui()
{
	// Code took from looking at the ImGui examples 
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

// Render Functions
void GuiImGui::preRender()
{
	renderWindow(); // Add all window components to renderer
}

void GuiImGui::render()
{
	ImGui::Render(); // Render ImGui
}

void GuiImGui::postRender()
{
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Render ImGui Draw Data
}