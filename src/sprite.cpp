#include "sprite.h"
#include "engine.h"

void Sprite::load(const char* path)
{
	texture = IMG_LoadTexture(render, path);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Sprite::draw(int x, int y)
{
	SDL_Rect dest = { x, y, width, height };
	SDL_RenderCopy(render, texture, NULL, &dest);
}

void Sprite::draw_centered(int x, int y)
{
	SDL_Rect dest = { x - width / 2, y - height / 2, width, height };
	SDL_RenderCopy(render, texture, NULL, &dest);
}