#include "ObjectRenderer.hpp"

ObjectRenderer::ObjectRenderer(SDL_Renderer* renderer)
    : renderer(renderer)
{}

void ObjectRenderer::begin()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

void ObjectRenderer::end()
{
    SDL_RenderPresent(renderer);
}

void ObjectRenderer::drawRect(SDL_FRect rect)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRectF(renderer, &rect);
}