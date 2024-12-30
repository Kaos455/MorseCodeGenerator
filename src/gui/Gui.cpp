#include "gui/Gui.h"

// Constructor for GUI
Gui::Gui(std::shared_ptr<Buffer> inputBuffer, std::shared_ptr<Buffer> outputBuffer) 
	: m_guiOpenGL(std::make_unique<GuiOpenGL>()),
	m_guiImGui(std::make_unique<GuiImGui>(m_guiOpenGL->getWindow(), inputBuffer, outputBuffer)) {}

// Main functions for GUI Rendering
bool Gui::windowShouldClose() const
{
	return glfwWindowShouldClose(m_guiOpenGL->getWindow());
}

void Gui::render()
{
	if (!windowShouldClose()) {
		// Pre-Render Functions
		m_guiOpenGL->preRender();
		m_guiImGui->preRender();

		// Render Functions
		m_guiOpenGL->render();
		m_guiImGui->render();

		// Post Render functions
		m_guiImGui->postRender();
		m_guiOpenGL->postRender();
	}
}