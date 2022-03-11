#pragma once

struct Projectile
{
	bool alive = false;
	float x;
	float y;

	float velX;
	float velY;

	void update();
	void draw();
	bool step(float dx, float dy);
};
