#include "spritesheet.h"
#include "engine.h"

void Sprite_Sheet::load(const char* path, int sprite_wI, int sprite_hI)
{
	texture = IMG_LoadTexture(render, path);
	sprite_w = sprite_wI;
	sprite_h = sprite_hI;
}

void Sprite_Sheet::draw(int sprite_index, int x, int y)
{
	SDL_Rect source = { sprite_index * sprite_w, 0, sprite_w, sprite_h};
	SDL_Rect dest = { x, y, sprite_w, sprite_h };

	SDL_RenderCopy(render, texture, &source, &dest);
}

void Sprite_Sheet::draw_centered(int sprite_index, int x, int y)
{
	SDL_Rect source = { sprite_index * sprite_w, 0, sprite_w, sprite_h };
	SDL_Rect dest = { x - sprite_w / 2, y - sprite_h / 2, sprite_w , sprite_h };

	SDL_RenderCopy(render, texture, &source, &dest);
}