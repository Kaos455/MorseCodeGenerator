#include "gui/custom_components/MainComponent.h"

MainComponent::MainComponent(std::shared_ptr<Buffer> inputBuffer, std::shared_ptr<Buffer> outputBuffer)
	: io(ImGui::GetIO()), m_inputBuffer(inputBuffer), m_outputBuffer(outputBuffer) {}

void MainComponent::render()
{
	ImGui::Dummy(ImVec2(0.0f, 10.0f));

	ImGui::Text("Enter Text to Translate into Morse Code:");
	ImGuiComponents::Textbox textbox("##Input", m_inputBuffer, ImVec2(ImGui::GetContentRegionAvail().x, 200.0f));
	textbox.render();

	ImGui::Spacing();

	ImGui::Text("Generated Morse Code:");
	ImGuiComponents::OutputBox outputBox("##Output", m_inputBuffer, ImVec2(ImGui::GetContentRegionAvail().x, 200.0f));
	outputBox.render();

	ImGui::Dummy(ImVec2(0.0f, 10.0f));
}