#include "Player.hpp"

#include "ObjectRenderer.hpp"

Player::Player(float x, float y, float w, float h, float speed)
    : Entity(x, y, w, h), speed(speed),
      playerRect({x, y, w, h})
{
    moveLeft = false;
    moveRight = false;
}

void Player::update(float dt)
{
    if (moveLeft)
    {
        x -= speed * dt;
    }
    if (moveRight)
    {
        x += speed * dt;
    }
    playerRect.x = x;
    playerRect.y = y;
}

void Player::setMoveLeft(bool shouldMove)
{
    moveLeft = shouldMove;
}
void Player::setMoveRight(bool shouldMove)
{
    moveRight = shouldMove;
}

void Player::render(ObjectRenderer& objRenderer)
{
    objRenderer.drawRect(playerRect);
}