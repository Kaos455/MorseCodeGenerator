#include "events/EventHandler.h"


namespace event {

	// Constructor for EventHandler
	// Not the best option, however it works in the use of the project as there wont be too many events.
	// Could be improved to use Generic events with some data inside the event to determine what to do.
	// This way the event could be handled gracefully, with minimal code repetition.
	EventHandler::EventHandler(std::shared_ptr<event::EventListener> eventListener) : m_eventListener(eventListener)
	{
		eventMap[EventType::EVENT_BUTTON_CLICKED] = [this]() { buttonClicked(); };
		eventMap[EventType::EVENT_INCREMENT_BUTTON_CLICKED] = [this]() { incrementButtonClicked(); };
	}

	// Default Destructor
	EventHandler::~EventHandler() = default;

	// Initial Implementation of waitEvent. Added checkMap to check if the event is in the map and then call the function as without checkMap, if 
	/*void EventHandler::waitEvent() 
	{
		if (m_eventListener->hasEvent())
			eventMap[m_eventListener->getEvent()]();
	}*/

	// Waits for event to be triggered and then calls the appropriate function
	void EventHandler::waitEvent()
	{
		if (m_eventListener->hasEvent())
		{
			EventType currEvent = m_eventListener->getEvent();
			if (checkMap(currEvent))
				eventMap[currEvent]();
			else
				std::cerr << "Event: Unknown Event" << std::endl;
		}
	}

	// Checks if map contains the event
	bool EventHandler::checkMap(EventType event)
	{
		return (eventMap.find(event) != eventMap.end());
	}

	// Event Map Functions
	void EventHandler::buttonClicked()
	{
		std::cout << "Event: Standard Button Clicked" << std::endl;
	}

	void EventHandler::incrementButtonClicked()
	{
		std::cout << "Event: Incremement Button Clicked" << std::endl;
	}
}