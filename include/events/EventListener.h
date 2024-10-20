#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

// Standard Library Includes
#include <queue> // std::queue
#include <stdexcept>

// Custom Library Includes
#include "events/EventTypes.h" // event::EventType

namespace event {
	class EventListener
	{
	public:
		// Constructor
		EventListener();

		// Destructor
		~EventListener();

		// Public Functions
		/*
		* @brief Add event to the Listener
		*
		* @param event::EventType event An event type to add to the queue
		*/
		void addEvent(EventType event);

		/*
		* @brief Get the first event from the Listener
		*
		* @return event::EventType The first event in the queue

		*/
		EventType getEvent();

		/*
		* @brief Check if the Listener has any events
		*
		* @return bool True if the Listener has events, False if the Listener has no events
		*/
		bool hasEvent();
	private:
		std::queue<EventType> events; // Events Queue
	};
}

#endif // EVENTLISTENER_H