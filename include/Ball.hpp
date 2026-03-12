#pragma once

#include <SDL2/SDL.h>

#include "Entity.hpp"

class Ball : Entity {
  public:
    Ball(float x, float y, float w, float h, float speed);

    void update(float dt) override;
    void render(ObjectRenderer& objRenderer) override;

  private:
    float speed;

    SDL_FRect ballRect;
};