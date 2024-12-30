#include "Application.h"

// Constructor
Application::Application() : // Current the Screen is 1280x720 and defaulted within the Constructor
	m_inputBuffer(std::make_shared<Buffer>(256)), 
	m_outputBuffer(std::make_shared<Buffer>(1024)), 
	m_gui(std::make_shared<Gui>(m_inputBuffer, m_outputBuffer))
{

}

// Destructor
Application::~Application()
{
	std::cout << "Closing: Application Shutdown" << std::endl;
}

// Main loop for the App. This is where the GUI is rendered and the App logic is placed
void Application::run()
{
	while (!m_gui->windowShouldClose())
	{
		m_gui->render(); // Render the frame after event Handled
	}
}