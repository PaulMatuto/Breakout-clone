#pragma once

#include <SDL2/SDL.h>

#include "Ball.hpp"
#include "Brick.hpp"
#include "Player.hpp"
#include "ObjectRenderer.hpp"

#include <vector>

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
    const float OBJ_SPEED = 250.0f;

    SDL_Window* window;
    SDL_Renderer* renderer;

    ObjectRenderer* objectRenderer;

    bool running;

    Player* player;
    Ball* ball;

    int noOfRows;
    int noOfColumns;
    std::vector<Brick*> bricks;

    Uint32 prevTick;
    Uint32 currentTick;

    float dt;

};