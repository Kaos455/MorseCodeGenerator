#include "gui/custom_components/MainComponent.h"

MainComponent::MainComponent(std::shared_ptr<Buffer<char>> inputBuffer, std::shared_ptr<Buffer<char>> outputBuffer)
	: io(ImGui::GetIO()), m_inputBuffer(inputBuffer), m_outputBuffer(outputBuffer) 
{
	std::cout << "Setup: Main Component created" << std::endl;
}

void MainComponent::render()
{
	ImGui::Dummy(ImVec2(0.0f, 10.0f));

	ImGui::Text("Enter Text to Translate into Morse Code:");
	ImGuiComponents::Textbox textbox("##Input", m_inputBuffer, ImVec2(ImGui::GetContentRegionAvail().x, 200.0f));
	textbox.render();

	ImGui::Spacing();

	// Render the text
	ImGui::Text("Generated Morse Code:");
	ImGui::SameLine(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize("Symbol -> '#' signifies cannot translate that character").x);
	ImGui::Text("Symbol -> '#' signifies cannot translate that character");
	ImGuiComponents::OutputBox outputBox("##Output", m_outputBuffer, ImVec2(ImGui::GetContentRegionAvail().x, 350.0f));
	outputBox.render();

	float buttonWidth = 165.0f;
	ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x - buttonWidth);
	// Render the button
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.2f, 0.7f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.15f, 0.5f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.15f, 0.45f, 1.0f));

	ImGui::PushFont(io.Fonts->Fonts[3]);
	if (ImGui::Button("Copy Output"))
	{
		copyToClipboard(m_outputBuffer->getData());
		std::cout << "Input: " << m_inputBuffer->getData() << std::endl;
		std::cout << "Output: " << m_outputBuffer->getData() << std::endl;
	}
	ImGui::PopStyleColor(3);
	ImGui::PopFont();
}

void MainComponent::copyToClipboard(const char* buffer) {
	ImGui::SetClipboardText(buffer);
}