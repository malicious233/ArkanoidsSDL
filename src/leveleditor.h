#pragma once
#define MAP_COLS 15
#define MAP_ROWS 15
#define NUM_BLOCKS (MAP_COLS * MAP_ROWS)
#include <string>

static struct LevelEditor
{
	void SaveLevel();
	std::string LoadLevelString(const std::string str);
	static void GenerateLevel(const char* lvl, int rows, int cols);

};