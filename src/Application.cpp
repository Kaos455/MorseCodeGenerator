#include "Application.h"

// Constructor
Application::Application() : // Current the Screen is 1280x720 and defaulted within the Constructor
	m_inputBuffer(std::make_shared<Buffer>(256)),
	m_inputBufferCopy(std::make_shared<Buffer>(256)),
	m_outputBuffer(std::make_shared<Buffer>(1024)), 
	m_gui(std::make_unique<Gui>(m_inputBuffer, m_outputBuffer)),
	m_generator(std::make_unique<MorseCodeGenerator>(m_inputBuffer, m_outputBuffer)) {}

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
		if (strcmp(m_inputBuffer->getData(), m_inputBufferCopy->getData()) != 0)
		{
			strcpy(m_inputBufferCopy->getData(), m_inputBuffer->getData()); // Copy the Buffer to keep up to date
			m_generator->generate(); // Generate the Morse Code
		}
		m_gui->render(); // Render the Frame after the Generation of the Morse Code
	}
}