#pragma once

#include <SDL2/SDL.h>

#include "Entity.hpp"

class Player : Entity {
  public:
    Player(float x, float y, float w, float h, float speed);

    void update(float dt) override;
    void render(ObjectRenderer& objRenderer) override;

    void setMoveLeft(bool shouldMove);
    void setMoveRight(bool shouldMove);

    SDL_FRect getRect();

  private:
    bool moveLeft;
    bool moveRight;

    float speed;

    SDL_FRect playerRect;
};