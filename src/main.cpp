#include <SDL2/SDL.h>
#include "common.h"
#include "gameapp.h"

using std::cout;
using std::cerr;
using std::endl;
using std::runtime_error;
using std::shared_ptr;
using std::make_shared;
using game::GameApp;

int SDL_main(int argc, char* argv[]) {
    GameApp* app;

    try {
        app = new GameApp();        
        app->run();
    } catch (const runtime_error& err) {
        cout << "Error in application, could not recover." << endl;
        cout << err.what() << endl;
    }

    delete app;

    return 0;
}
