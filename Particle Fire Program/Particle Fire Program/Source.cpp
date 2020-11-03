#include <iostream>
#include <SDL.h>
#include <math.h>
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

	//bool quit = false;


	// Game (Event) loop
	while (true) {
		// Update particles


		// Draw particles
		// add block of color
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);

		// Draw screen
		screen.update();

		// Check for events
		// remains true until SDL_QuitEvent has been received
		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}