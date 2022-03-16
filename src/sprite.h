#pragma once
#include <SDL/SDL_image.h>

struct Sprite
{
	void load(const char* path);
	void draw(int x, int y);
	void draw_centered(int x, int y);

	SDL_Texture* texture;
	int width;
	int height;
};