#include "Application.h"

// Constructor
Application::Application() : // Current the Screen is 1280x720 and defaulted within the Constructor
	m_gui(std::make_shared<Gui>())
{

}

// Destructor
Application::~Application() = default;

// Main loop for the App. This is where the GUI is rendered and the App logic is placed
void Application::run()
{
	while (!m_gui->windowShouldClose())
	{
		m_gui->render(); // Render the frame after event Handled
	}
}