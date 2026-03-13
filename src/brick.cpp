#include "Brick.hpp"

Brick::Brick(float x, float y, float w, float h)
    : Entity(x, y, w,  h),
      brickRect({x, y, w, h})
{

}

void Brick::update(float dt)
{

}

void Brick::render(ObjectRenderer& objRenderer)
{
    objRenderer.drawRect(brickRect, 0xF0, 0x0, 0x0, 0xFF);
}