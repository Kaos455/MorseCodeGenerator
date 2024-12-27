#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "imgui.h"

namespace ImGuiComponents {
	class MediaPlayer
	{
	public:
		MediaPlayer(const char* label, const ImVec2& size);
		~MediaPlayer() = default;

		void render();
	private:
		void renderPlaybackControls();
		void renderVolumeControl();
		void renderProgressBar();

		bool isPlaying;
		float progress;
		int volume;

		const char* label;
		ImVec2 size;
	};
}

#endif // MEDIAPLAYER_H