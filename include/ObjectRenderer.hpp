#pragma once

#include <SDL2/SDL.h>

class ObjectRenderer{
  public:
    ObjectRenderer(SDL_Renderer* renderer);

    void begin();
    void end();
  
    void drawRect(SDL_FRect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  private:
    SDL_Renderer* renderer;
};