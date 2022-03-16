#include "brick.h"
#include "collision.h"
#include "engine.h"
#include <SDL/SDL.h>

void Brick::draw()
{
	if (!alive)
		return;

	RGBAcolor col;
	switch (health)
	{
	case 0:
		break;
	case 1:
		col = { 200, 200, 50, 255 };
		break;
	case 2: 
		col = { 250, 200, 50, 255 };
		break;
	case 3:
		col = { 320, 159, 50, 200 };
		break;
	}
	SDL_SetRenderDrawColor(render, col.r, col.g, col.b, col.a);
	AABB box = AABB::make_from_position_size(x, y, w, h);
	draw_box(box);
}
