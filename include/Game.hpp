#pragma once

#include <SDL2/SDL.h>

#include "Ball.hpp"
#include "Player.hpp"
#include "ObjectRenderer.hpp"

class Game{
  public:
    Game();

    void init();
    void initObjects();
    void shutdown();

    bool isRunning();
    void run();

    void handleInput();
    void update(float dt);
    void render();
    
  private:
    // constants
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const float OBJ_SPEED = 100;

    SDL_Window* window;
    SDL_Renderer* renderer;

    ObjectRenderer* objectRenderer;

    bool running;

    Player* player;
    Ball* ball;

    Uint32 prevTick;
    Uint32 currentTick;

    float dt;

};