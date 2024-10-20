#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

// Standard Library Includes
#include <iostream>
#include <unordered_map> // std::unordered_map
#include <functional> // std::function

// Custom Library Includes
#include "events/EventTypes.h" // event::EventType
#include "events/EventListener.h" // event::EventListener
#include "gui/Gui.h" // Gui

namespace event {
	class EventHandler
	{
	public:
		/*
		* @brief Event handler Constructor
		*
		* The Event Handler Constructor takes in pointers to different parts of the application to properly handle events, would also have a pointer to the event listener. Sets up the Map for the event types and functions as well
		* @param args
		*
		* @param std::shared_ptr<event::EventListener> eventListener A pointer to the Event Listener
		* @return void
		*/
		EventHandler(std::shared_ptr<event::EventListener> eventListener);

		/*
		* @brief Event handler Destructor
		*
		* The Event Handler Destructor would handle any memory such as clearing the map of event types and functions
		*
		*/
		~EventHandler();

		/*
		* @brief Checks if an event exists in the map
		* 
		* @param EventType event
		* @return bool True (if event exists in map) or False (if event does not exist in map)
		*/
		bool checkMap(EventType event);

		/*
		* @brief Wait Event Function 
		* 
		* The Wait Event Function waits for an event to occur by calling upon the EventListener hasEvent() function
		* If hasEvent() returns true, then the function will get the event and call the function associated with the event type
		* 
		* @param none
		* @return void
		*/
		void waitEvent();
	private:
		// Map for the Event Types and Functions
		std::unordered_map<event::EventType, std::function<void()>> eventMap;

		// Pointers
		std::shared_ptr<event::EventListener> m_eventListener; // Event Listener Pointer

		/*
		* @brief Button Clicked Function
		* 
		* Triggered when EVENT_BUTTON_CLICKED is received
		*/
		void buttonClicked();

		/*
		* @brief Increment Button Clicked Function
		* 
		* Triggered when EVENT_INCREMENT_BUTTON_CLICKED is received
		*/
		void incrementButtonClicked();
	};
}

#endif // EVENTHANDLER_H