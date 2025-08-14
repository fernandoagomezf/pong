#include "main.h"

using std::cout;
using std::cerr;
using std::endl;

int SDL_main(int argc, char* argv[]) {
    cout << "SDL2 Initializing..." << endl;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    return 0;
}
