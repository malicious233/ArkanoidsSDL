#pragma once

struct Brick
{
	bool alive = true;

	int health = 3;

	float x = 600;
	float y = 200;

	float w = 40.f;
	float h = 100.f;

	void draw();
};
