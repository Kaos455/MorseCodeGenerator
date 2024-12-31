#include "gui/custom_components/FooterComponent.h"

FooterComponent::FooterComponent() : io(ImGui::GetIO()) {}

void FooterComponent::render()
{
	ImGui::Dummy(ImVec2(0, 20.0f));

	static ImGuiComponents::MediaPlayer mediaPlayer("##Volume", ImVec2(ImGui::GetContentRegionAvail().x, 125.0f));
	mediaPlayer.render();
}