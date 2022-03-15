#include "player.h"
#include "engine.h"
#include "game.h"

void Player::update()
{
	// move
	if (GetKey(SDL_SCANCODE_W))
		y -= 300 * delta_time;
	if (GetKey(SDL_SCANCODE_S))
		y += 300 * delta_time;


	// shoot! pew pew
	shoot_timer -= delta_time;
	if (GetKeyPressed(SDL_SCANCODE_SPACE))
	{
		Projectile& proj = projectiles[next_projectile_index];
		proj.alive = true;
		proj.x = x;
		proj.y = y;
		proj.velX = 200.f;
		proj.velY = -200.f;

		shoot_timer = 0.2f;

		next_projectile_index++;
		next_projectile_index = next_projectile_index % PROJECTILE_MAX;
	}
}

void Player::draw()
{
	SDL_SetRenderDrawColor(render, 150, 25, 40, 255);
	SDL_Rect rect = { (int)x - 16, (int)y - 16, 32, 96 };
	SDL_RenderFillRect(render, &rect);
}
