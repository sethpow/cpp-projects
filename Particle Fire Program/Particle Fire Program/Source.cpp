#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init Video failure." << endl;
		return 1;
	}

	cout << "SDL Init Video Running." << endl;

	return 0;
}