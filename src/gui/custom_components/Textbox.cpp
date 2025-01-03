#include "gui/custom_components/Textbox.h"

using namespace ImGuiComponents; 

// Constructor
Textbox::Textbox(const char* label, std::shared_ptr<Buffer<char>> buffer, const ImVec2& size)
    : ImGuiComponent(size), label(label), buffer(buffer)
{
}

// Destructor
Textbox::~Textbox()
{
    if (label)
    {
        label = nullptr;
    }
}

// Render method for the Textbox
void Textbox::render() 
{
    applyStyle();
    ImGui::InputTextMultiline(label, buffer->getData(), buffer->getCapacity(), getSize());
    popStyle();
}

void Textbox::applyStyle()
{
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5.0f, 5.0f));
}

void Textbox::popStyle()
{
    ImGui::PopStyleVar(2);
    ImGui::PopStyleColor(3);
}