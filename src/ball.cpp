#include "Ball.hpp"
#include <iostream>
Ball::Ball(float x, float y, float w, float h, float speed)
    : Entity(x, y, w, h),
      speed(speed),
      ballRect({x, y, w, h})
{

}

void Ball::update(float dt)
{
    x += speed * dt;
    y += speed * dt;

    ballRect.x = x;
    ballRect.y = y;
}

void Ball::render(ObjectRenderer& objRenderer)
{
    objRenderer.drawRect(ballRect, 0x0, 0xFF, 0x0, 0xFF);
}