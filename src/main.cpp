#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "engine.h"
#include "player.h"
#include "game.h"
#include "collision.h"
#include "leveleditor.h"
#include "spritesheet.h"


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
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600,0); 
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 
	//Text
	TTF_Font* font = TTF_OpenFont("res/roboto.ttf", 14);
	SDL_Surface* text_surf = TTF_RenderText_Solid(font, "but did you know, in 15 to 20 years all helium on earth will have run out ? ", { 255,0,255,255 });
	SDL_Texture* text_tex = SDL_CreateTextureFromSurface(render, text_surf);

	//A sprite
	/*
	int sprite_w, sprite_h;
	SDL_Texture* sprite = IMG_LoadTexture(render, "res/sprite.png");
	SDL_QueryTexture(sprite, NULL, NULL, &sprite_w, &sprite_h);
	*/

	player_sprite.load("res/paddle.png");

	Sprite_Sheet cowGif;
	cowGif.load("res/stupididle.png", 32, 32);
	
	float animTime = 0;
	

	/*
	//Call this when youre done with a texture
	SDL_FreeSurface(text_surf);
	SDL_DestroyTexture(text_tex);
	*/
	

	bool running = true;
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	/*
	for(int i=0; i<BRICK_MAX; ++i)
	{
		bricks[i].y = 120 * i;
	}
	*/

	//level.SaveLevel();
	//std::string lvlStr = level.LoadLevelString("levels/levelEditor.txt");
	//std::cout << lvlStr << std::endl;
	Level newLevel;
	newLevel = level.LoadLevel("levels/leveleditor.txt");

	LevelEditor::GenerateLevel(newLevel.levelString.c_str(), newLevel.columns, newLevel.rows);
 
	while (running)
	{
		frameNumber++;

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
				if (event.key.repeat)
					break;

				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

				keys[scancode].state = true;
				keys[scancode].changeFrame = frameNumber;
 
				break;
			}
 
			case SDL_KEYUP:
			{
				int scancode = event.key.keysym.scancode;
				keys[scancode].state = false;
				keys[scancode].changeFrame = frameNumber;
 
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

		//Draw text
		SDL_Rect text_dst = { 30, 30, text_surf->w, text_surf->h };
		SDL_RenderCopy(render, text_tex, NULL, &text_dst);

		//SDL_Rect sprite_dst = { projectiles[0].x, projectiles[0].y, sprite_w, sprite_h };
		//SDL_RenderCopy(render, sprite, NULL, &sprite_dst);

		animTime += delta_time;

		cowGif.draw((int)(animTime * 5 ) % 4, 100, 100);

		SDL_RenderPresent(render);
 
	}
}
