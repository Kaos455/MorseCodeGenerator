#include "gui/custom_components/MediaPlayer.h"

using namespace ImGuiComponents;

MediaPlayer::MediaPlayer(const char* label, const ImVec2& size)
    : isPlaying(false), progress(0.0f), volume(75),
    label(label), size(size) {}

void MediaPlayer::render()
{
    ImGui::BeginChild(label, size, true, ImGuiWindowFlags_None);

    ImGui::Text("Media Player");
    ImGui::Separator();

    renderPlaybackControls();
    renderVolumeControl();
    renderProgressBar();

    ImGui::EndChild();
}

void MediaPlayer::renderPlaybackControls()
{
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
}

void MediaPlayer::renderVolumeControl()
{
    float availableWidth = ImGui::GetContentRegionAvail().x;
    float sliderWidth = 870.0f; // Hardcoded style as not allowing content resize regardless
    ImGui::SameLine(availableWidth - sliderWidth);

    ImGui::Text("Volume");
    ImGui::SameLine();
    ImGui::SliderInt("##VolumeSlider", &volume, 0, 100);
}

void MediaPlayer::renderProgressBar()
{
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
}