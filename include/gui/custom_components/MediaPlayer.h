#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "imgui.h"

namespace ImGuiComponents {
	class MediaPlayer
	{
	public:
		MediaPlayer(const char* label, const ImVec2& size);
		~MediaPlayer();

		void render();
	private:
		void renderPlaybackControls();
		void renderVolumeControl();
		void renderProgressBar();

		void applyBGStyle();
		void popBGStyle();

		bool isPlaying;
		float progress;
		int volume;

		const char* label;
		ImVec2 size;

		ImGuiIO& io;
	};
}

#endif // MEDIAPLAYER_H