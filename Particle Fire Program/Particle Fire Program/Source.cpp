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

		// cycle thru color
		int elapsed = SDL_GetTicks(); // milliseconds since start of program from -.99 to .99
		unsigned char red = (1 + sin(elapsed * 0.000420)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.000525)) * 128;
		unsigned char blue = (1 + cos(elapsed * 0.000630)) * 128;

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}


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