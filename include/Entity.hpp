#pragma once

#include "ObjectRenderer.hpp"

class Entity{
  public:
    Entity(float x, float y, float w, float h);

    virtual void update(float dt);
    virtual void render(ObjectRenderer& objRenderer);

  protected:
    float x, y;
    float w, h;

};