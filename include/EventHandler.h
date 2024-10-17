#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

// Standard Library Imports
#include <iostream>
#include <unordered_map> // std::unordered_map
#include <functional> // std::function

// Custom Library Imports
#include "EventTypes.h" // event::EventType

namespace event {
	class EventHandler
	{
		std::unordered_map<event::EventType, std::function<void()>> eventMap;
	public:
		/*
		* @brief Event handler Constructor
		*
		* The Event Handler Constructor takes in pointers to different parts of the application to properly handle events, would also have a pointer to the event listener. Sets up the Map for the event types and functions as well
		* @param args
		*
		* @return void
		*/
		EventHandler();

		/*
		* @brief Event handler Destructor
		*
		* The Event Handler Destructor would handle any memory such as clearing the map of event types and functions
		*/
		~EventHandler();

		void handleEvent(event::EventType event);
	private:
		// Functions for the Map
		void buttonClicked();
	};
}

#endif // EVENTHANDLER_H