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

	// set equal to return value of createRenderer function
	// args: window, initialize first rendering drive available, ensures rendering is in sync with vertical refresh of screen
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	// what renderer will render; what you write pixel info to
	// args: renderer, 4 bytes/32 bits for ea pixel, texture - way to write to texture/take memory load of pixels and write directly to texture on every loop, width, height
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if (texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	// allocate enough memory for all the pixels on screen
	Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// write pixel info into buffer
	// memset - allows you to set a block of memory with a particular value
	// args: buffer, value that we are going to write into every byte of memory (255 / 0xFF is the max), # of bytes we want to set
	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	// set whole screen to specific color
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = 0x0080FFFF;
	}

	// setting individual pixels
	// buffer containing pixel data
	buffer[30000] = 0xFFFFFFFF; // rgba packed into one Uint32

	// update texture with info from buffer ^^
	// args: texture, NULL - to update entire texture, buffer - raw pixel data, pitch - memory allocated to one row of pixels / # of bytes per row of pixels
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));

	// clear the renderer
	SDL_RenderClear(renderer);

	// copy texture to the renderer
	// first NULL - use for entire texture, second NULL - use for entire rendering target
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	// present renderer to window / rendering to window
	SDL_RenderPresent(renderer);

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

	// deallocate/free resources
	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}