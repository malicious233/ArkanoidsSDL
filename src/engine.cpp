#include "engine.h"

SDL_Window* window;
SDL_Renderer* render;

KeyState keys[SDL_NUM_SCANCODES];

bool GetKey(SDL_Scancode key)
{
	return keys[key].state;
}
bool GetKeyPressed(SDL_Scancode key)
{
	return keys[key].state && keys[key].changeFrame == frameNumber;
}
bool GetKeyReleased(SDL_Scancode key)
{
	return !keys[key].state && keys[key].changeFrame == frameNumber;
}

float delta_time = 0.f;
int frameNumber = 0;