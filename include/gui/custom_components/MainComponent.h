#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

#include "imgui.h"
#include <memory>

#include "gui/custom_components/Textbox.h"
#include "gui/custom_components/OutputBox.h"
#include "buffer/Buffer.h"

class MainComponent
{
public:
	MainComponent(std::shared_ptr<Buffer> inputBuffer, std::shared_ptr<Buffer> outputBuffer);

	void render(); // Render Method

private: 
	void copyToClipboard(const char* buffer);

	ImGuiIO& io;

	std::shared_ptr<Buffer> m_inputBuffer;
	std::shared_ptr<Buffer> m_outputBuffer;
};

#endif // MAINCOMPONENT_H