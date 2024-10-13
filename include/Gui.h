#ifndef GUI_H
#define GUI_H

// Includes for Dear ImGui
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

// Includes for Standard Library
#include <iostream>
#include <functional> // std::function

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
	Gui(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	// Destructor
	~Gui();

	void render();
	bool windowShouldClose();
	void setPlaySoundCallback(std::function<void()> callback);

private:
	// Member Functions
	bool initGLFW();
	bool initGLAD();
	bool initImGui();
	void changeVSync(bool trigger);
	void imGuiRender(); // Render ImGui Elements cleans the "startRender" function

	// Private Callback Functions
	std::function<void()> playSoundCallback;

	// Member Variables
	GLFWwindow* m_window = nullptr;
	int m_width;
	int m_height;
};

#endif