#include "App.h"

// Constructor
App::App() : m_gui(Gui(1280, 720, "Morse Code Generator", NULL, NULL)), m_running(true) // Current the Screen is 1280x720 and defaulted within the Constructor
{

}

// Destructor
App::~App() = default;


// Setup the GUI Callbacks for the App. (This is where you would add more callbacks for the GUI Buttons and such)
void App::setupGui(Gui& gui)
{
	gui.setPlaySoundCallback([this]() { this->m_soundController.playSound(); });
}

// Main loop for the App. This is where the GUI is rendered and the App logic is placed
void App::run()
{
	setupGui(m_gui); // Setup all the GUI callbacks
	while (!m_gui.windowShouldClose())
	{
		m_gui.render();
	}
}