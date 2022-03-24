#pragma once

struct Circle
{
	float x;
	float y;
	float radius;
};

// feedback: these global functions as well as similar ones below don't really fit into object-oriented approach needed for this assignemnt.
// I'd suggest to place them in a class where they belong to, like CollisionManager or something like that.
void draw_circle(const Circle& circle);
bool circle_intersect(const Circle& a, const Circle& b);

struct AABB
{
	static AABB make_from_position_size(float x, float y, float w, float h);

	float x_min;
	float y_min;

	float x_max;
	float y_max;
};

void draw_box(const AABB& box);
bool aabb_intersect(const AABB& a, const AABB& b);

bool aabb_circle_intersect(const AABB& a, const Circle& b);
