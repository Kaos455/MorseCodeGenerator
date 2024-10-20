#ifndef GUIIMGUI_H
#define GUIIMGUI_H

// Standard Library Includes
#include <iostream>
#include <memory>

// Custom Library Includes
#include "events/EventListener.h"

// Dear ImGui Includes
#include "imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"


class GuiImGui
{
public:
	/*
	* @brief Constructor for GuiImGui
	* 
	* This constructor will call the initialisation functions for the ImGui front end
	* 
	* @param GLFWwindow* window The window to be passed to ImGui
	* @param std::shared_ptr<event::EventListener> eventListener The event listener to be passed to ImGui
	*/
	GuiImGui(GLFWwindow* window, std::shared_ptr<event::EventListener> eventListener);

	/*
	* @brief Destructor for GuiImGui
	* 
	* This destructor will handle the cleanup for the ImGui front end
	*/
	~GuiImGui();


	void renderWindow(); // Temp func
	 
	/*
	* @brief Function to initialise ImGui
	* 
	* @return bool True (if successfully initialised) or False (if not successfully initialised)
	*/
	bool initImGui(); 

	/*
	* @brief Handles pre-rendering for ImGui
	* 
	* @param none
	* @return void
	*/
	void preRender();

	/*
	* @brief Handles rendering for ImGui
	* 
	* @param none
	* @return void
	*/
	void render();

	/*
	* @breif Handles post-rendering for ImGui
	* 
	* @param none
	* @return void
	*/
	void postRender();

private:
	GLFWwindow* m_window = nullptr;
	std::shared_ptr<event::EventListener> m_eventListener;
};


#endif // GUIIMGUI_H