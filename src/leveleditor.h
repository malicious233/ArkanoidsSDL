#pragma once
#define MAP_COLS 15
#define MAP_ROWS 15
#define NUM_BLOCKS (MAP_COLS * MAP_ROWS)

static struct LevelEditor
{
	void SaveLevel();
	static void GenerateLevel(const char* lvl, int rows, int cols);

};