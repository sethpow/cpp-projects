#include <iostream>
#include <SDL.h>
#include "Screen.h"
using namespace std;
using namespace particlefire;

int main(int argc, char* args[]) {
	// setting individual pixels
	// buffer containing pixel data
	// buffer[30000] = 0xFFFFFFFF; // rgba packed into one Uint32

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	bool quit = false;


	// Game/Event loop
	while (true) {
		// Update particles
		// Draw particles
		// Check for events

		// remains true until SDL_QuitEvent has been received
		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}