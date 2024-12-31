#include "gui/custom_components/OutputBox.h"

using namespace ImGuiComponents;

OutputBox::OutputBox(const char* label, std::shared_ptr<Buffer> buffer, const ImVec2& size)
	: ImGuiComponent(size), label(label), io(ImGui::GetIO()), buffer(buffer) {}


OutputBox::~OutputBox()
{
    if (label)
    {
        label = nullptr;
    }
}

void OutputBox::render()
{
    applyStyle();

    ImGui::BeginChild(label, getSize(), true, ImGuiWindowFlags_None);

    ImGui::TextWrapped(buffer->getData()); 
    ImGui::EndChild();

    popStyle();
}

void OutputBox::applyStyle()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 10.0f);

    if (ImGui::GetIO().Fonts->Fonts.size() > 1) {
        ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[3]);
    }
    else {
        std::cerr << "Font index out of bounds!" << std::endl;
    }

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.8f, 0.8f, 0.8f, 1.0f));
}

void OutputBox::popStyle()
{
    ImGui::PopStyleColor();
    ImGui::PopFont();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
}