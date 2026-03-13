#pragma once

#include "Entity.hpp"

class Brick : Entity {
  public:
    Brick(float x, float y, float w, float h);

    void update(float dt) override;
    void render(ObjectRenderer& objRenderer) override;

  private:
    SDL_FRect brickRect;
};