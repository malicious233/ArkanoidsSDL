#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "engine.h"
#include "player.h"
#include "game.h"
#include "collision.h"
#include "leveleditor.h"


const char* LEVEL =
"..............."
"..............."
"..............."
".###..........."
"..............."
"....###........"
"..............."
".........###..."
"........##....."
".......##......"
"......##......."
".....##........"
"..............."
"###############"
"..............."
;

int main()
{
	LevelEditor level;

	SDL_Init(SDL_INIT_EVERYTHING); 
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600,0); 
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 
	bool running = true;
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	/*
	for(int i=0; i<BRICK_MAX; ++i)
	{
		bricks[i].y = 120 * i;
	}
	*/

	//level.SaveLevel();
	std::string lvlStr = level.LoadLevelString("levels/levelEditor.txt");
	std::cout << lvlStr << std::endl;
	LevelEditor::GenerateLevel(lvlStr.c_str(), MAP_ROWS, MAP_COLS);
 
	while (running)
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks; 
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency(); 
 
		

		SDL_Event event;
		while(SDL_PollEvent(&event)) 
		{
			switch(event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
 
			case SDL_KEYDOWN:
			{
				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

				keys[scancode] = true;
 
				break;
			}
 
			case SDL_KEYUP:
			{
				int scancode = event.key.keysym.scancode;
				keys[scancode] = false;
 
				break;
			}
			}
		}
 
		SDL_SetRenderDrawColor(render, 25, 25, 40, 255); 
		SDL_RenderClear(render);

		player.update();
		player.draw();

		for(int i=0; i<PROJECTILE_MAX; ++i)
		{
			projectiles[i].update();
			projectiles[i].draw();
		}

		for(int i=0; i<NUM_BLOCKS; ++i)
		{
			if (bricks[i] != nullptr)
				bricks[i]->draw();
			
		}

		SDL_RenderPresent(render);
 
	}
}
