#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

// Standard Library Imports
#include <iostream>
#include <unordered_map> // std::unordered_map
#include <functional> // std::function

// Custom Library Imports
#include "events/EventTypes.h" // event::EventType
#include "events/EventListener.h" // event::EventListener
#include "gui/Gui.h" // Gui

namespace event {
	class EventHandler
	{
		std::unordered_map<event::EventType, std::function<void()>> eventMap;

		// Pointer List
		std::shared_ptr<event::EventListener> m_eventListener; // Event Listener Pointer
		std::shared_ptr<Gui> m_gui; // GUI Pointer
	public:
		/*
		* @brief Event handler Constructor
		*
		* The Event Handler Constructor takes in pointers to different parts of the application to properly handle events, would also have a pointer to the event listener. Sets up the Map for the event types and functions as well
		* @param args
		*
		* @return void
		*/
		EventHandler(std::shared_ptr<event::EventListener> eventListener);

		/*
		* @brief Event handler Destructor
		*
		* The Event Handler Destructor would handle any memory such as clearing the map of event types and functions
		*/
		~EventHandler();

		bool checkMap(EventType event);
		void waitEvent();
	private:
		// Functions for the Map
		void buttonClicked();
		void incrementButtonClicked();
	};
}

#endif // EVENTHANDLER_H