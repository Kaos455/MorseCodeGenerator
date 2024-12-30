#ifndef GUIIMGUI_H
#define GUIIMGUI_H

// Custom Components
#include "gui/custom_components/HeaderComponent.h"
#include "gui/custom_components/MainComponent.h"
#include "gui/custom_components/FooterComponent.h"
#include "buffer/Buffer.h"

// Standard Library Includes
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

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
	*/
	GuiImGui(GLFWwindow* window, std::shared_ptr<Buffer> inputBuffer, std::shared_ptr<Buffer> outputBuffer);

	/*
	* @brief Destructor for GuiImGui
	* 
	* This destructor will handle the cleanup for the ImGui front end
	*/
	~GuiImGui();
	 
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
	* @brief Handles post-rendering for ImGui
	* 
	* @param none
	* @return void
	*/
	void postRender();

	// ImGui setup -> ApplyTheme, Setup Fonts etc
	void applyTheme();
	void setupImGuiFonts(ImGuiIO& io);

private:
	GLFWwindow* m_window = nullptr;

	std::shared_ptr<Buffer> m_inputBuffer;
	std::shared_ptr<Buffer> m_outputBuffer;
};


#endif // GUIIMGUI_H