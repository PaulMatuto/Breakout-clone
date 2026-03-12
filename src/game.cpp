#include "Game.hpp"

#include "Ball.hpp"
#include "Player.hpp"

#include <iostream>

Game::Game()
    :window(nullptr),
     renderer(nullptr)
{
    
}

// Initialize everything
void Game::init()
{
    // Initialize SDL
    SDL_Log("Initializing SDL...");
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Could not initialize SDL. Error: " << SDL_GetError() << std::endl;
        return;
    }
    
    SDL_Log("Creating a window...");
    window = SDL_CreateWindow("Breakout Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Could not create a window. Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    SDL_Log("Creating a renderer...");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Could not create a renderer. Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Initialize object renderer
    objectRenderer = new ObjectRenderer(renderer);

    running = true;

    prevTick = SDL_GetTicks();
    currentTick = 0;

    initObjects();
}

void Game::initObjects()
{
    float playerWidth = 10.0f;
    float playerHeight = 10.0f;
    player = new Player((SCREEN_WIDTH - playerWidth) / 2.0f, (SCREEN_HEIGHT - playerHeight) / 2.0f, 
                            playerWidth, playerHeight, OBJ_SPEED);

    float ballWidth = 10.0f;
    float ballHeight = 10.0f;
    ball = new Ball(100.0f, 100.0f, ballWidth, ballHeight, OBJ_SPEED);
}

bool Game::isRunning()
{
    return running;
}

void Game::run()
{    
    handleInput();
    update(dt);
    render();

    // Delta time
    currentTick = SDL_GetTicks();
    dt = (currentTick - prevTick) / 1000.0f;
    prevTick = currentTick;
}

void Game::handleInput()
{
    // handles input events
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // Allows quitting through the window X button
        switch (event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_A:
                    case SDL_SCANCODE_LEFT:
                        player->setMoveLeft(true);
                        break;
                    case SDL_SCANCODE_D:
                    case SDL_SCANCODE_RIGHT:
                        player->setMoveRight(true);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_A:
                    case SDL_SCANCODE_LEFT:
                        player->setMoveLeft(false);
                        break;
                    case SDL_SCANCODE_D:
                    case SDL_SCANCODE_RIGHT:
                        player->setMoveRight(false);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }

        
    }
}

void Game::update(float dt)
{
    player->update(dt);
}

void Game::render()
{
    objectRenderer->begin();

    player->render(*objectRenderer);

    objectRenderer->end();
}

void Game::shutdown()
{
    // Clean up game objects
    player = nullptr;
    ball = nullptr;

    // Clean up SDL
    SDL_Log("Cleaning up...");
    SDL_DestroyRenderer(renderer);
    SDL_Log("Renderer Destroyed");
    SDL_DestroyWindow(window);
    SDL_Log("Window Destroyed");
    SDL_Quit();
    SDL_Log("SDL Quit");
}