#include "Application.h"
/*
 * This file is part of {{ MorseCodeGenerator }}.
 * Description: This project is a very simple MorseCodeGenerator created for University to be adapted as a portfolio project.
 * 
 * Developed for a University project.
 * Developed by Mark Canty
 * 
 * This project is licensed under the MIT License.
 * 
 * Libraries used:
 *  - Dear ImGui library, licensed under the MIT License.
 *  - GLFW library, licensed under the zlib/libpng License.
 *  - GLAD library, licensed under the MIT License.
 *  - PortAudio library, licensed under the MIT License.
 *  - Mp3Lame library, licensed under the LGPL License. (https://lame.sourceforge.io)
 */

int main()
{
	// Using heap allocation for the Application because its size may exceed the stack allocation limit.
	// Using unique_ptr to manage the memory of the Application automatically.
	std::unique_ptr<Application> app = std::make_unique<Application>();
	app->run();

	return 0;
}