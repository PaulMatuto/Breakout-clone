#include <SDL2/SDL.h>

#include "Game.hpp"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(int argc, char* argv[])
{
    Game game = Game();
    game.init();

    while (game.isRunning())
    {
        game.run();
    }

    // Cleanup
    game.shutdown();

    return 0;
}