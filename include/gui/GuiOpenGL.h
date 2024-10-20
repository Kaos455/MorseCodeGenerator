#ifndef GUIOPENGL_H
#define GUIOPENGL_H

// Standard Library Includes
#include <iostream>

// OpenGL Library Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GuiOpenGL
{
public:
	/*
	* @brief Constructor for OpenGL Gui
	* 
	* This constructor will intialise OpenGL and GLFW
	*/
	GuiOpenGL();

	/*
	* @brief Destructor for OpenGL Gui
	* 
	* This destructor will handle the cleanup of OpenGL and GLFW 
	*/
	~GuiOpenGL();

	GLFWwindow* getWindow();

	/*
	* @brief Change whether VSync is enabled or not
	*
	* @param trigger bool true (to enable VSync) or false (to disable VSync)
	* @return none
	*/
	void changeVSync(bool trigger);

	/*
	* @brief Handles pre-rendering for OpenGL
	* 
	* @param none
	* @return void
	*/
	void preRender();

	/*
	* @brief Handles rendering for OpenGL
	*
	* @param none
	* @return void
	*/
	void render();

	/*
	* @brief Handles post-rendering for OpenGL
	*
	* @param none
	* @return void
	*/
	void postRender();

private:
	GLFWwindow* m_window = nullptr;

	/*
	* @brief Initialisation function for OpenGL
	* 
	* @return bool true (if successfully initialised) or false (if failed to initialise)
	*/
	bool initOpenGL();

	/*
	* @brief Initialisation function for GLFW
	*
	* @return bool true (if successfully initialised) or false (if failed to initialise)
	*/
	bool initGLFW();

	/*
	* @brief Initialisation function for GLAD
	*
	* @return bool true (if successfully initialised) or false (if failed to initialise)
	*/
	bool initGLAD();

	bool initWindow();
};

#endif // GUIOPENGL_H