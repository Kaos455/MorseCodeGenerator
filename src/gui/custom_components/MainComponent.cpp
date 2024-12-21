#include "gui/custom_components/MainComponent.h"

MainComponent::MainComponent() : io(ImGui::GetIO()) {}

void MainComponent::render()
{
	ImGui::Dummy(ImVec2(0.0f, 10.0f));

	ImGui::Text("Enter Text to Translate into Morse Code:");
	static ImGuiComponents::Textbox textbox("##Input", 256, ImVec2(ImGui::GetContentRegionAvail().x, 200.0f));
	textbox.render();

	ImGui::Spacing();

	ImGui::Text("Generated Morse Code:");
	static ImGuiComponents::Textbox textbox2("##Output", 1024, ImVec2(ImGui::GetContentRegionAvail().x, 200.0f));
	textbox2.render();

	ImGui::Dummy(ImVec2(0.0f, 10.0f));
}