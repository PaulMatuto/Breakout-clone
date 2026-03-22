#pragma once

#include "Entity.hpp"

class Brick : Entity {
  public:
    Brick(float x, float y, float w, float h);

    void update(float dt) override;
    void render(ObjectRenderer& objRenderer) override;

    void isHit();

    SDL_FRect getRect();

  private:
    SDL_FRect brickRect;

    bool isAlive;
};