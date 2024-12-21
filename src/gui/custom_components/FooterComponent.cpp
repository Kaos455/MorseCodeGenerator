#include "gui/custom_components/FooterComponent.h"

FooterComponent::FooterComponent() : io(ImGui::GetIO()) {}

void FooterComponent::render()
{
	ImGui::Text("This is the Footer");
}