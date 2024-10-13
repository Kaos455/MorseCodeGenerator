#ifndef APP_H
#define APP_H

#include "Gui.h"
#include "SoundController.h"

class App
{
public:
	// Constructor
	App();
	// Destructor
	~App();

	// Public Functions
	void run();

private:
	// Member Functions
	void setupGui(Gui& gui);

	// Member Variables#
	Gui m_gui;
	SoundController m_soundController;
	bool m_running;
};

#endif // APP_H