#include "Brick.hpp"

Brick::Brick(float x, float y, float w, float h)
    : Entity(x, y, w,  h),
      brickRect({x, y, w, h}),
      isAlive(true)
{

}

void Brick::update(float dt)
{
    // remove bricks if not 'alive'
    if (!isAlive)
    {
        brickRect = {};
    }
}

void Brick::render(ObjectRenderer& objRenderer)
{
    if (isAlive)
    {
        objRenderer.drawRect(brickRect, 0xF0, 0x0, 0x0, 0xFF);
    }
}

SDL_FRect Brick::getRect()
{
    return brickRect;
}

void Brick::isHit()
{
    isAlive = false;
}