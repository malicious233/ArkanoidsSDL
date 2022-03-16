#pragma once
#include <SDL/SDL_image.h>


struct Sprite_Sheet
{
	void load(const char* path, int sprite_wI, int sprite_hI);
	void draw(int sprite_index, int x, int y);

	SDL_Texture* texture;
	int sprite_w;
	int sprite_h;

};