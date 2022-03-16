#pragma once
#include <SDL/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* render;

struct KeyState
{
	bool state = false;
	int changeFrame = 0;
};

extern struct RGBAcolor
{
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 0;

	RGBAcolor (int rC, int gC, int bC, int aC) : r(rC), g(gC), b(bC), a(aC)
	{

	}

	RGBAcolor()
	{

	}

};

extern KeyState keys[SDL_NUM_SCANCODES];
bool GetKey(SDL_Scancode key);
bool GetKeyPressed(SDL_Scancode key);
bool GetKeyReleased(SDL_Scancode key);

extern float delta_time;
extern int frameNumber;
