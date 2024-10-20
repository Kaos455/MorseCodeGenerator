#ifndef GUI_H
#define GUI_H
// Standard Library Includes
#include <iostream>
#include <functional> // std::function
#include <memory>

#define IMGUI_IMPL_OPENGL_LOADER_GLAD

// Custom Library Includes
#include "gui/GuiOpenGL.h"
#include "gui/GuiImGui.h"

/**
 * @brief The GUI class is a class that represents the GUI of the application.
 * 
 * The GUI class is a class which seperates the GUI from the rest of the application, allowing for easier maintenance and modification of the GUI.
 * The GUI uses the Dear ImGui library to create the GUI with OpenGL its backend. Additionally, GLFW and GLAD are used to create the window and handle OpenGL easier.
 */
class Gui
{
	// Member Pointers
	std::shared_ptr<event::EventListener> m_eventListener;
	std::unique_ptr<GuiOpenGL> m_guiOpenGL;
	std::unique_ptr<GuiImGui> m_guiImGui;
public:
	/*
	* @brief Constructor for GUI
	 *
	 * This consturctor will call the initialisation functions for the OpenGL backend, such as GLFW and GLAD
	 * This constructor does not start the main rendering loop of the application.
	 *
	 * @param eventListener The event listener to be passed to the GuiImGui class
	*/
	Gui(std::shared_ptr<event::EventListener> eventListener);
	
	/*
	 * @brief Destructor for GUI
	 *
	 * This destructor handles the cleanup for the OpenGL backend
	*/
	~Gui() = default;

	/* 
	* @brief Function to check if the m_window should close
	* 
	* This function will return a boolean value of whether the m_window should close or not
	* Incredibly important for the Application Loop
	* 
	* @return bool True (if yes) or False (if no)
	*/
	bool windowShouldClose() const;

	/*
	* @brief render function for the Gui
	* 
	* This function will complete the process the necessary functions within OpenGL and ImGui to render the Gui
	* 
	* @return void
	*/
	void render();

private:
};

#endif