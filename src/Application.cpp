#include "Application.h"

// Constructor
Application::Application() : // Current the Screen is 1280x720 and defaulted within the Constructor
	m_inputBuffer(std::make_shared<Buffer<char>>(256)),
	m_inputBufferCopy(std::make_shared<Buffer<char>>(256)),
	m_outputBuffer(std::make_shared<Buffer<char>>(1536)),
	m_morseGenerator(std::make_unique<MorseCodeGenerator>(m_inputBuffer, m_outputBuffer)) 
{
	try // Try to do these 2 folder checks
	{
		checkResourcesFolder();
		std::cout << "Setup: 'Resources' folder found. Proceeding" << std::endl;

		checkFontsFolder();
		std::cout << "Setup: 'Fonts' folder found. Proceeding" << std::endl;

		// Only create GUI if these are successful (GUI uses the fonts thus cannot be initalised in the Init list)
		m_gui = std::make_unique<Gui>(m_inputBuffer, m_outputBuffer);
	}
	catch (const std::runtime_error& e) // If runtime_error is thrown
	{
		// State the Error caught
		std::cerr << "Error: " << e.what() << std::endl;

		// Keep the console up so the user can see what went wrong
		std::cout << "Press Enter to close" << std::endl;
		std::cin.get();
	}
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
		if (strcmp(m_inputBuffer->getData(), m_inputBufferCopy->getData()) != 0)
		{
			strcpy(m_inputBufferCopy->getData(), m_inputBuffer->getData()); // Copy the Buffer to keep up to date
			m_outputBuffer->clear(); // Clear the Output Buffer so i can see the most recent morse code translation
			m_morseGenerator->generate(); // Generate the Morse Code
		}
		m_gui->render(); // Render the Frame after the Generation of the Morse Code
	}
}

// Resource Check -> Check if resources are actually within the folder
void Application::checkResourcesFolder() {
	std::cout << "Setup: Checking resources folder at: " << std::filesystem::current_path() << "/resources" << std::endl;

	// Check if Resources folder exists 
	if (!std::filesystem::exists("resources") || !std::filesystem::is_directory("resources")) {
		// Throw Runtime Error if not
		throw std::runtime_error("Missing 'Resources' folder. Please add it to the directory.");
	}
	std::cout << "Setup: Found resources folder at: " << std::filesystem::current_path() << "/resources" << std::endl;
}

void Application::checkFontsFolder() {
	// Create Vector of Font names used in app
	std::vector<std::string> fontNames = {"Poppins-Bold", "Poppins-Regular", "Roboto-Regular"};
	std::cout << "Setup: Checking fonts folder at: " << std::filesystem::current_path() << "/resources/fonts" << std::endl;

	// Check if fonts folder exists within resources
	if (!std::filesystem::exists("resources/fonts") || !std::filesystem::is_directory("resources/fonts")) {
		throw std::runtime_error("Missing 'Fonts' folder. Please add it to the resources directory.");
	}

	// Check if each of the fonts within the Vector is within the fonts folder
	for (size_t i = 0; i < fontNames.size(); i++)
	{
		std::string fontPath = "resources/fonts/" + fontNames[i] + ".ttf";
		std::cout << "Setup: Checking font file: " << fontPath << std::endl;
		if (!std::filesystem::exists(fontPath))
		{
			throw std::runtime_error("Missing font file: " + fontPath + ". Please add it to the directory.");
		}
		std::cout << "Setup: Found font file: " << fontPath << std::endl;
	}
}