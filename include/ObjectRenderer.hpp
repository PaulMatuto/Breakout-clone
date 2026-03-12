#pragma once

#include <SDL2/SDL.h>

class ObjectRenderer{
  public:
    ObjectRenderer(SDL_Renderer* renderer);

    void begin();
    void end();

    void drawRect(SDL_FRect rect);

  private:
    SDL_Renderer* renderer;
};