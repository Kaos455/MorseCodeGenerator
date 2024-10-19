#include "gui/GuiImGui.h"

// Constructor for ImGui Gui
GuiImGui::GuiImGui(std::shared_ptr<event::EventListener> eventListener) : m_eventListener(eventListener)
{
	std::cout << "Setup: ImGui Gui Initialised" << std::endl;
}

void GuiImGui::imGuiRender()
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
	{
		m_eventListener->addEvent(event::EventType::EVENT_INCREMENT_BUTTON_CLICKED);
		counter += incAmount;
	}
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