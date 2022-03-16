#include "projectile.h"
#include "engine.h"
#include "collision.h"
#include "game.h"

float sign(float a) { return a > 0.f ? 1.f : -1.f; }

void Projectile::update()
{
	if (!alive)
		return;

	// Collision check with brick!
	Circle circle = { x, y, 4 };
	draw_circle(circle);

	/*
	for(int i=0; i<BRICK_MAX; ++i)
	{
		Brick& brick = bricks[i];
		if (!brick.alive)
			continue;

		AABB box = AABB::make_from_position_size(brick.x, brick.y, brick.w, brick.h);

		if (aabb_circle_intersect(box, circle))
		{
			//alive = false;
			brick.alive = false;
			return;
		}
	}
	*/
	if (!step(0.f, velY * delta_time))
	{
		velY = -velY + sign(-velY) * 5;
	}
	if (!step(velX * delta_time, 0.f))
	{
		velX = -velX + sign(-velX) * 5;
	}
	
	//x += velX * delta_time;
	//y += velY * delta_time;
}

void Projectile::draw()
{
	if (!alive)
		return;

	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_Rect rect = { (int)x - 4, (int)y - 4, 8, 8 };

	SDL_RenderFillRect(render, &rect);
}

bool Projectile::step(float dx, float dy)
{

	Circle circle = { x + dx, y + dy , 4 };
	for (Brick* b : bricks)
	{
		if (b == nullptr)
			continue;
		if (b->alive == false) //this bit could be more elegant 
			continue;
		AABB box = AABB::make_from_position_size(b->x, b->y, b->w, b->h);
		if (aabb_circle_intersect(box, circle))
		{
			//b->alive = false; //I should do that the brick is dynamically deallocated instead of just made invisible and ignored by collision
			b->health--;
			if (b->health <= 0)
			{
				b->alive = false;
			}
			
			return false;
		}
			
	}

	//Player collisions
	if (dx < 0.f)
	{
		AABB box = AABB::make_from_position_size(player.x, player.y + 32 , 32, 96); //ugly magic numbers
		if (aabb_circle_intersect(box, circle))
		{
			return false;
		}
	}



	if (x + dx > 800)
	{
		return false;
	}

	if (y + dy > 600 || y + dy < 0)
	{
		return false;

	}
	x += dx;
	y += dy;
	

	return true;
};

