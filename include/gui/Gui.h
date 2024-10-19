#ifndef GUI_H
#define GUI_H

// Includes for Dear ImGui
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "gui/GuiImGui.h"

// Include for EventListener#
#include "events/EventListener.h"

// Includes for Standard Library
#include <iostream>
#include <functional> // std::function
#include <memory>

/**
  * @brief The GUI class is a class that represents the GUI of the application.
  *
  * The GUI class is a class which seperates the GUI from the rest of the application, allowing for easier maintenance and modification of the GUI.
  * The GUI uses the Dear ImGui library to create the GUI with OpenGL its backend. Additionally, GLFW and GLAD are used to create the window and handle OpenGL easier.
  */
class Gui
{
public:
	// Constructor
	Gui(std::shared_ptr<event::EventListener> eventListener);
	// Destructor
	~Gui();

	void render();
	bool windowShouldClose();

private:
	// Member Functions
	bool initGLFW();
	bool initGLAD();
	bool initImGui();
	void changeVSync(bool trigger);

	// Member Variables
	GLFWwindow* m_window = nullptr;
	int m_width;
	int m_height;
	std::shared_ptr<event::EventListener> m_eventListener;
	std::unique_ptr<GuiImGui> m_guiImGui = std::make_unique<GuiImGui>(m_eventListener);
};

#endif