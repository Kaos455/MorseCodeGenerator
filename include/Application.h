#ifndef APPLICATION_H
#define APPLICATION_H

// Standard Library Includes
#include <memory>
#include <iostream> 

// Custom Library Includes
#include "events/EventHandler.h"
#include "events/EventListener.h"
#include "gui/Gui.h"

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
	std::shared_ptr<event::EventListener> m_eventListener;
	std::shared_ptr<Gui> m_gui;

	// Unique Pointers
	std::unique_ptr<event::EventHandler> m_eventHandler;
};

#endif // APPLICATION_H