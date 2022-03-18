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




//Text
TTF_Font* font;
SDL_Surface* text_surf;
SDL_Texture* text_tex;

void Update_ProjectileCountHUD()
{
	SDL_FreeSurface(text_surf);
	SDL_DestroyTexture(text_tex); //This alleviates a memoryleak I think

	font = TTF_OpenFont("res/roboto.ttf", 25);
	text_surf = TTF_RenderText_Solid(font, std::to_string(projectileCount).c_str(), { 255,255,255,255 });
	text_tex = SDL_CreateTextureFromSurface(render, text_surf);
}

int main()
{
	float animTime = 0;
	
	bool running = true;

	LevelEditor level;

	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	//Initialization
	SDL_Init(SDL_INIT_EVERYTHING); 
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);

	

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600,0); 
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 

	//Load sprites
	Update_ProjectileCountHUD();

	player_sprite.load("res/paddle.png");

	Sprite_Sheet ballCountHUD;
	ballCountHUD.load("res/ballcountHUDspritesheet.png", 75, 75);
	
	
	


	//Load and generate level
	Level newLevel;
	newLevel = level.LoadLevel("levels/level1.txt");

	LevelEditor::GenerateLevel(newLevel);
 
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

		if (GetKeyPressed(SDL_SCANCODE_SPACE))
		{
			projectileCount--;
			Update_ProjectileCountHUD();
		}

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

		

		//SDL_Rect sprite_dst = { projectiles[0].x, projectiles[0].y, sprite_w, sprite_h };
		//SDL_RenderCopy(render, sprite, NULL, &sprite_dst);

		//Draw ballcount hud
		animTime += delta_time;
		ballCountHUD.draw((int)(animTime * 5 ) % 4, 35, 20);

		//Draw text
		SDL_Rect text_dst = { 55, 45, text_surf->w, text_surf->h };
		SDL_RenderCopy(render, text_tex, NULL, &text_dst);

		SDL_RenderPresent(render);
 
	}
}
