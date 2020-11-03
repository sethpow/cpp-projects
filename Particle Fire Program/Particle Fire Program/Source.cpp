#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace particlefire;

int main(int argc, char* args[]) {
	// setting individual pixels
	// buffer containing pixel data
	// buffer[30000] = 0xFFFFFFFF; // rgba packed into one Uint32

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	Swarm swarm;

	//bool quit = false;


	// Game (Event) loop
	while (true) {
		// Update particles
		// cycle thru color
		int elapsed = SDL_GetTicks(); // milliseconds since start of program from -.99 to .99
		

		// update positions and color
		swarm.update();

		unsigned char red = (1 + sin(elapsed * 0.000420)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.000525)) * 128;
		unsigned char blue = (1 + cos(elapsed * 0.000630)) * 128;


		// Draw particles
		const Particle* const pParticles = swarm.getParticles();
		// getting particles 1 by 1
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			
			// drawing particles on screen
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		// blurring
		screen.boxBlur();


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