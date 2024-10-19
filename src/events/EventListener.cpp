#include "events/EventListener.h"

namespace event {
	EventListener::EventListener() = default;
	EventListener::~EventListener() = default;

	void EventListener::addEvent(EventType event)
	{
		events.push(event);
	}

	EventType EventListener::getEvent()
	{
		if (events.empty())
			throw std::runtime_error("No events in the queue");

		EventType event = events.front();
		events.pop();
		return event;
	}

	bool EventListener::hasEvent()
	{
		return !events.empty();
	}
}