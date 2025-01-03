#include "gui/custom_components/HeaderComponent.h"


HeaderComponent::HeaderComponent() 
    : io(ImGui::GetIO()), isSettingModalOpen(false), isExportModalOpen(false) 
{
    std::cout << "Setup: Header Component created" << std::endl;
}

void HeaderComponent::render() 
{
    settingButton();

    ImGui::SameLine(ImGui::GetContentRegionAvail().x / 2.0f - 185.0f); // Placing the Cursor (around) the Center of the Screen (with an Offset for the Text to look centered-ish) 
    titleText();

    ImGui::SameLine(ImGui::GetContentRegionAvail().x - 90.0f);
    exportButton();
}

// Reasoning for copy/paste is due to maybe changing the colour later down the line between the buttons

void HeaderComponent::settingButton()
{
    // Setting Button Colour
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.2f, 0.7f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.15f, 0.5f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.15f, 0.45f, 1.0f));

    if (io.Fonts->Fonts.size() > 3) {
        ImGui::PushFont(io.Fonts->Fonts[3]);
    }
    else {
        std::cerr << "Font index out of bounds!" << std::endl;
    }

    // Button that opens the modal
    if (ImGui::Button("Settings")) {
        isSettingModalOpen = true; 
    }

    // Open the modal only once
    if (isSettingModalOpen && !ImGui::IsPopupOpen("Settings")) {
        ImGui::OpenPopup("Settings");
    }

    // Begin the modal and resize it
    if (ImGui::BeginPopupModal("Settings", nullptr, ImGuiWindowFlags_NoMove)) {
        ImGui::SetWindowSize(ImVec2(800, 600));

        ImVec2 windowPos = ImVec2(
            (ImGui::GetIO().DisplaySize.x - 800) / 2.0f, // X position (centered)
            (ImGui::GetIO().DisplaySize.y - 600) / 2.0f  // Y position (centered)
        );
        ImGui::SetWindowPos(windowPos); // Set the modal position

        ImGui::Text("Settings! Not Yet Implemented");

        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
            isSettingModalOpen = false;
        }

        ImGui::EndPopup();
    }

    ImGui::PopFont();
    ImGui::PopStyleColor(3);
}

void HeaderComponent::titleText()
{
    ImGui::PushFont(io.Fonts->Fonts[1]);
    ImGui::Text("Morse Code Generator");
    ImGui::PopFont();
}

void HeaderComponent::exportButton()
{
    // Export Button Colour
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.2f, 0.7f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.15f, 0.5f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.15f, 0.45f, 1.0f));

    if (io.Fonts->Fonts.size() > 3) {
        ImGui::PushFont(io.Fonts->Fonts[3]);
    }
    else {
        std::cerr << "Font index out of bounds!" << std::endl;
    }

    // Button that opens the modal
    if (ImGui::Button("Export")) {
        isExportModalOpen = true;
    }

    // Open the modal only once
    if (isExportModalOpen && !ImGui::IsPopupOpen("Export")) {
        ImGui::OpenPopup("Export");
    }

    // Begin the modal and resize it
    if (ImGui::BeginPopupModal("Export", nullptr)) {
        ImGui::SetWindowSize(ImVec2(800, 600));

        ImVec2 windowPos = ImVec2(
            (ImGui::GetIO().DisplaySize.x - 800) / 2.0f, // X position (centered)
            (ImGui::GetIO().DisplaySize.y - 600) / 2.0f  // Y position (centered)
        );
        ImGui::SetWindowPos(windowPos); // Set the modal position

        ImGui::Text("Export! Not yet Implemented");

        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
            isExportModalOpen = false;
        }

        ImGui::EndPopup();
    }

    ImGui::PopFont();
    ImGui::PopStyleColor(3);
}