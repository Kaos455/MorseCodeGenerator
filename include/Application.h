#ifndef APPLICATION_H
#define APPLICATION_H

// Standard Library Imports
#include <memory>
#include <iostream> 

// Custom Library Imports
#include "EventHandler.h"
#include "EventListener.h"
#include "Gui.h"

class Application
{
public:
	// Constructor
	Application();
	// Destructor
	~Application();

	// Public Functions
	void run();

private:
	// Member Functions

	// Member Variables
	std::shared_ptr<event::EventListener> m_eventListener = std::make_shared<event::EventListener>();
	std::shared_ptr<Gui> m_gui = std::make_shared<Gui>(m_eventListener);

	std::unique_ptr<event::EventHandler> m_eventHandler = std::make_unique<event::EventHandler>();
};

#endif // APPLICATION_H