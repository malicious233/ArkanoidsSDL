#include <iostream>
#include <fstream>

#include "leveleditor.h"
#include "brick.h"
#include "game.h"

void LevelEditor::GenerateLevel(const char* lvl, int rows, int cols)
{
	const char* ptr = lvl;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++, ++ptr)
		{
			if (*ptr != '#')
				continue;

			Brick* brick = new Brick();
			printf("brick");
			brick->alive = true;
			brick->x = x * 32;
			brick->y = y * 32;

			bricks[y * cols + x] = brick;
		}
	}
}

void LevelEditor::SaveLevel()
{
	std::string level;

	for (size_t i = 0; i < 256; i++)
	{
		char c = '0';
		level.push_back(c);
	}

	std::ofstream myfile;
	myfile.open("levels/levelEditor.txt", std::ofstream::out | std::ofstream::trunc);

	myfile << level;
	myfile.close();
}