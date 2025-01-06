#ifndef APPLICATION_H
#define APPLICATION_H

// Standard Library Includes
#include <memory>
#include <iostream>
#include <stdexcept>
#include <filesystem>
#include <vector>

// Custom Library Includes
#include "gui/Gui.h"
#include "buffer/Buffer.h" // Buffer objects for use as inputBuffer and outputBuffer
#include "generator/MorseCodeGenerator.h"

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

	void checkResourcesFolder();
	void checkFontsFolder();

	// Smart Pointers
	std::shared_ptr<Buffer<char>> m_inputBuffer;  // Input buffer with a copy to be used with Event Dispatcher later
	std::shared_ptr<Buffer<char>> m_inputBufferCopy;
	std::shared_ptr<Buffer<char>> m_outputBuffer; // Output Buffer used for Output Text

	std::unique_ptr<Gui> m_gui; // Gui
	std::unique_ptr<MorseCodeGenerator> m_morseGenerator; // Morse Code Generator
};

#endif // APPLICATION_H