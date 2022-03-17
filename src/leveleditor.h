#pragma once
#define MAP_COLS 15
#define MAP_ROWS 15
#define NUM_BLOCKS (MAP_COLS * MAP_ROWS)
#include <string>
#include "level.h"

static struct LevelEditor
{
	void SaveLevel();
	std::string LoadLevelString(const std::string str);
	Level LoadLevel(const std::string str);
	static void GenerateLevel(const char* lvl, int rows, int cols);
	static void GenerateLevel(Level level);

};