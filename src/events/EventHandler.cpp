#include "events/EventHandler.h"


namespace event {
	EventHandler::EventHandler(std::shared_ptr<event::EventListener> eventListener) : m_eventListener(eventListener)
	{
		eventMap[EventType::EVENT_BUTTON_CLICKED] = [this]() { buttonClicked(); };
		eventMap[EventType::EVENT_INCREMENT_BUTTON_CLICKED] = [this]() { incrementButtonClicked(); };
	}

	EventHandler::~EventHandler() = default;

	// Initial Implementation of waitEvent. Added checkMap to check if the event is in the map and then call the function as without checkMap, if 
	/*void EventHandler::waitEvent() 
	{
		if (m_eventListener->hasEvent())
			eventMap[m_eventListener->getEvent()]();
	}*/

	void EventHandler::waitEvent()
	{
		if (m_eventListener->hasEvent())
		{
			EventType currEvent = m_eventListener->getEvent();
			if (checkMap(currEvent))
				eventMap[currEvent]();
			else
				std::cout << "Event: Unknown Event" << std::endl;
		}
	}

	bool EventHandler::checkMap(EventType event)
	{
		return (eventMap.find(event) != eventMap.end());
	}

	void EventHandler::buttonClicked()
	{
		std::cout << "Event: Standard Button Clicked" << std::endl;
	}

	void EventHandler::incrementButtonClicked()
	{
		std::cout << "Event: Incremement Button Clicked" << std::endl;
	}
}