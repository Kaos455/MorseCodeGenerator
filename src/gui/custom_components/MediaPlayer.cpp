#include "gui/custom_components/MediaPlayer.h"

using namespace ImGuiComponents;

// Reasing for not having individual Style Apply and Pop functions like BGStyle -> "I got lazy"

MediaPlayer::MediaPlayer(const char* label, const ImVec2& size)
    : io(ImGui::GetIO()), isPlaying(false), progress(0.0f), volume(75),
    label(label), size(size) {}


MediaPlayer::~MediaPlayer()
{
    if (label)
    {
        label = nullptr;
    }
}

void MediaPlayer::render()
{
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 10.0f);
    ImGui::BeginChild(label, size, true, ImGuiWindowFlags_None);

    ImGui::Text("Media Player - Media Playback not Yet Implemented");
    ImGui::Separator();

    renderPlaybackControls();

    float availableWidth = ImGui::GetContentRegionAvail().x;
    float sliderWidth = 870.0f;
    ImGui::SameLine(availableWidth - sliderWidth);

    renderVolumeControl();
    renderProgressBar();

    ImGui::EndChild();
    ImGui::PopStyleVar();
}

void MediaPlayer::renderPlaybackControls()
{
    // Playback Button Styling
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.2f, 0.7f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.15f, 0.5f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.15f, 0.45f, 1.0f));

    if (ImGui::Button(isPlaying ? "Pause" : "Play"))
    {
        isPlaying = !isPlaying;
    }

    ImGui::SameLine();

    if (ImGui::Button("Stop"))
    {
        isPlaying = false;
        progress = 0.0f;
    }

    ImGui::PopStyleColor(3); // Pop the Button Styling from the Stack
}

void MediaPlayer::renderVolumeControl()
{
    ImGui::PushFont(io.Fonts->Fonts[0]);
    ImGui::Text("Volume:");
    ImGui::PopFont();

    ImGui::SameLine();

    // Volume Slider Styling 
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 5.0f);

    applyBGStyle();
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.4f, 0.2f, 0.7f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.3f, 0.15f, 0.5f, 1.0f));

    // Volume Slider
    ImGui::SliderInt("##VolumeSlider", &volume, 0, 100);

    // Pop the Style of the Style Stacks
    ImGui::PopStyleVar(2); 
    ImGui::PopStyleColor(2);
    popBGStyle();
}

void MediaPlayer::renderProgressBar()
{
    // Progress Bar Styling
    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.4f, 0.2f, 0.7f, 1.0f));
    applyBGStyle();

    ImGui::ProgressBar(progress, ImVec2(-1, 0));

    if (isPlaying && progress < 1.0f)
    {
        progress += 0.001f; // Generic example to the Progression. Adjust to proper implementation when created!
    }

    if (progress > 1.0f)
    {
        progress = 0.0f;
        isPlaying = false;
    }

    ImGui::PopStyleColor(1); // Pop the 4 style colours off the Style Stack
    popBGStyle();
}


void MediaPlayer::applyBGStyle()
{
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
}

void MediaPlayer::popBGStyle()
{
    ImGui::PopStyleColor(3);
}