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

void ObjectRenderer::drawRect(SDL_FRect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRectF(renderer, &rect);
}