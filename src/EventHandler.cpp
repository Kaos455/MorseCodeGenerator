#include "EventHandler.h"

event::EventHandler::EventHandler()
{
	eventMap[event::EventType::EVENT_BUTTON_CLICKED] = [this]() { buttonClicked(); };
}

event::EventHandler::~EventHandler() = default;

void event::EventHandler::handleEvent(event::EventType event)
{
	eventMap[event]();
}

void event::EventHandler::buttonClicked()
{
	std::cout << "Button Clicked WOOO!" << std::endl;
}