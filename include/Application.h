#ifndef APPLICATION_H
#define APPLICATION_H

// Standard Library Includes
#include <memory>
#include <iostream> 

// Custom Library Includes
#include "gui/Gui.h"
#include "buffer/Buffer.h" // Buffer objects for use as inputBuffer and outputBuffer

class Application
{
public:
	/*
	* @brief Constructor for Application
	* 
	* This constructor will create the Application object and initialise all the necessary components for the application to run
	*/
	Application();
	
	/*
	* @brief Destructor for Application
	* 
	* Handles the cleanup for the Application object
	*/
	~Application();

	// Public Functions
	/*
	* @brief Runs main loop of the application
	* 
	* @params none
	* @return void
	*/
	void run();

private:
	// Shared Pointers
	std::shared_ptr<Buffer> m_inputBuffer;  // At the root of the application to allow access
	std::shared_ptr<Buffer> m_outputBuffer; // throughout the application without use of globals

	std::shared_ptr<Gui> m_gui;
};

#endif // APPLICATION_H