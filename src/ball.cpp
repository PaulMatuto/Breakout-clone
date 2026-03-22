#include "Ball.hpp"
#include <iostream>
Ball::Ball(float x, float y, float w, float h, float speed)
    : Entity(x, y, w, h),
      xSpeed(speed),
      ySpeed(speed),
      ballRect({x, y, w, h})
{

}

void Ball::update(float dt)
{
    x += xSpeed * dt;
    y += -ySpeed * dt; // make sure ball starts to go upward

    ballRect.x = x;
    ballRect.y = y;
}

void Ball::render(ObjectRenderer& objRenderer)
{
    objRenderer.drawRect(ballRect, 0x0, 0xFF, 0x0, 0xFF);
}

SDL_FRect Ball::getRect()
{
    return ballRect;
}

void Ball::invertYSpeed()
{
    ySpeed *= -1;
}

void Ball::invertXSpeed()
{
    xSpeed *= -1;
}