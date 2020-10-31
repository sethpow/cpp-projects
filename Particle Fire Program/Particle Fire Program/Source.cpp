#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char* args[]) {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init Video failure." << endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle Fire",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		SDL_Quit();
		cout << SDL_GetError() << endl;
		return 2;
	}

	bool quit = false;
	SDL_Event event; // needs address so SDL can fill in info for events that occur since previous call
	// Game/Event loop
	while (!quit) {
		// Update particles
		// Draw particles
		// Check for events

		// Process event queues
		// While there is a new event is waiting to be processed, will remain True
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}


	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}