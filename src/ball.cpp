#include "Ball.hpp"

Ball::Ball(float x, float y, float w, float h, float speed)
    : Entity(x, y, w, h),
      speed(speed),
      ballRect({x, y, w, h})
{

}

void Ball::update(float dt)
{
    
}

void Ball::render(ObjectRenderer& objRenderer)
{

}