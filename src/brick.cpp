#include "brick.h"
#include "collision.h"
#include "engine.h"
#include <SDL/SDL.h>

void Brick::draw()
{
	if (!alive)
		return;

	RGBAcolor col;

	if (!invincible)
	{
		switch (health)
		{
		case 0:
			break;
		case 1:
			col = { 238, 0, 0, 0 };
			break;
		case 2:
			col = { 255, 135, 0, 0 };
			break;
		case 3:
			col = { 25, 255, 50, 50 };
			break;
		}
	}
	else
	{
		col = { 100, 100, 100, 100 };
	}
	
	SDL_SetRenderDrawColor(render, col.r, col.g, col.b, col.a);
	AABB box = AABB::make_from_position_size(x, y, w, h);
	draw_box(box);
}
