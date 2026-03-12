#include "ObjectRenderer.hpp"

ObjectRenderer::ObjectRenderer(SDL_Renderer* renderer)
    : renderer(renderer)
{}

void ObjectRenderer::begin()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void ObjectRenderer::end()
{
    SDL_RenderPresent(renderer);
}

void ObjectRenderer::drawRect(SDL_FRect rect)
{
    SDL_RenderFillRectF(renderer, &rect);
}