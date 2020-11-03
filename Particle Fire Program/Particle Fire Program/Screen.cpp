#include "Screen.h"

namespace particlefire {

	Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
		
	}

	// setup
	bool Screen::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		m_window = SDL_CreateWindow("Particle Fire",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}

		// set equal to return value of createRenderer function
		// args: window, initialize first rendering drive available, ensures rendering is in sync with vertical refresh of screen
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		// what renderer will render; what you write pixel info to
		// args: renderer, 4 bytes/32 bits for ea pixel, texture - way to write to texture/take memory load of pixels and write directly to texture on every loop, width, height
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		// allocate enough memory for all the pixels on screen
		Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		// write pixel info into buffer
		// memset - allows you to set a block of memory with a particular value
		// args: buffer, value that we are going to write into every byte of memory (255 / 0xFF is the max), # of bytes we want to set
		SDL_memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		// set whole screen to specific color
		for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
			buffer[i] = 0x0080FFFF;
		}

		// update texture with info from buffer ^^
		// args: texture, NULL - to update entire texture, buffer - raw pixel data, pitch - memory allocated to one row of pixels / # of bytes per row of pixels
		SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));

		// clear the renderer
		SDL_RenderClear(m_renderer);

		// copy texture to the renderer
		// first NULL - use for entire texture, second NULL - use for entire rendering target
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

		// present renderer to window / rendering to window
		SDL_RenderPresent(m_renderer);

		return true;
	}


	bool Screen::processEvents() {
		SDL_Event event; // needs address so SDL can fill in info for events that occur since previous call

		// Process event queues
		// While there is a new event is waiting to be processed, will remain True

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}


	// tear down
	void Screen::close() {
		// deallocate/free resources
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
} /* namespace particlefire */