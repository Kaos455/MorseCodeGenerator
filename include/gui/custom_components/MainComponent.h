#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

// Standard Library Includes
#include <memory>
#include <iostream>

// Dear ImGui Includes
#include "imgui.h"

// Custom Library Includes
#include "gui/custom_components/Textbox.h"
#include "gui/custom_components/OutputBox.h"
#include "buffer/Buffer.h"

/*
 * @brief Main Component class to generate the Main of the GUI
 *
 * Simple Main integration, abstracted from the Main ImGui render function
 * Takes no parameters
*/
class MainComponent
{
public:
	MainComponent(std::shared_ptr<Buffer<char>> inputBuffer, std::shared_ptr<Buffer<char>> outputBuffer);

	void render(); // Render Method

private: 
	void copyToClipboard(const char* buffer); // Uses ImGui built in Clipboard functionality

	ImGuiIO& io;

	std::shared_ptr<Buffer<char>> m_inputBuffer;
	std::shared_ptr<Buffer<char>> m_outputBuffer;
};

#endif // MAINCOMPONENT_H