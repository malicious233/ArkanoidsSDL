#pragma once
#include <SDL/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* render;

struct KeyState
{
	bool state = false;
	int changeFrame = 0;
};

extern KeyState keys[SDL_NUM_SCANCODES];
bool GetKey(SDL_Scancode key);
bool GetKeyPressed(SDL_Scancode key);
bool GetKeyReleased(SDL_Scancode key);

extern float delta_time;
extern int frameNumber;
