#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>

#include "leveleditor.h"
#include "brick.h"
#include "game.h"

//Generates level with given pointer of the first pointer of a char array
void LevelEditor::GenerateLevel(const char* lvl, int rows, int cols)
{
	const char* ptr = lvl;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++, ++ptr)
		{
			if (*ptr != '#')
				continue;

			Brick* brick = new Brick(); // feedback: doesn't seem like memory allocated here is deleted anywhere
			float wdth = 800 / cols;
			float hgth = 600 / rows;
			

			brick->alive = true;
			brick->x = x * wdth;
			brick->y = y * hgth;
			brick->w = wdth;
			brick->h = hgth;

			bricks[y * cols + x] = brick;
		}
	}
}

void LevelEditor::GenerateLevel(Level level)
{
	const char* ptr = level.levelString.c_str();
	for (int y = 0; y < level.rows; y++)
	{
		for (int x = 0; x < level.columns; x++, ++ptr)
		{
			if (*ptr == '0')
				continue;


			Brick* brick = new Brick(); // feedback: doesn't seem like memory allocated here is deleted anywhere
			float wdth = 800 / level.columns;
			float hgth = 600 / level.rows;

			switch (*ptr)
			{
			case '1':
				brick->health = 1;
				break;
			case '2':
				brick->health = 2;
				break;
			case '3':
				brick->health = 3;
				break;
			case '#':
				brick->invincible = true;
				break;



			}

			brick->alive = true;
			brick->x = x * wdth;
			brick->y = y * hgth;
			brick->w = wdth;
			brick->h = hgth;

			bricks[y * level.columns + x] = brick;
		}
	}
}



//Saves an empty file 
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

//Returns a Level struct with data for generating a level from a given file datapath
Level LevelEditor::LoadLevel(std::string str)
{
	Level newLevel;

	std::ifstream load(str, std::ifstream::in); 

	std::string newStr;
	std::string tmpStr;

	//Parse first 2 lines to define width and height of level
	std::getline(load, tmpStr);
	newLevel.columns = std::stoi(tmpStr);
	std::cout << newLevel.columns << std::endl;
	
	std::getline(load, tmpStr);
	newLevel.rows = std::stoi(tmpStr);
	std::cout << newLevel.rows << std::endl;

	//Loop through all the lines after the width and height definition and make it into a string
	for (int i = 0; i < newLevel.columns; i++)
	{
		std::getline(load, tmpStr);
		newStr.append(tmpStr);
	}
	newLevel.levelString = newStr;

	return newLevel;

}

//Returns the entire string from a given file directory. Outdated now, use LoadLevel instead 
std::string LevelEditor::LoadLevelString(const std::string str)
{
	std::ifstream load(str, std::ifstream::in); //Open file for reading
	
	std::string newStr;
	std::string tmpStr;

	for (int i = 0; i < MAP_COLS; i++)
	{
		std::getline(load, tmpStr);
		newStr.append(tmpStr);
	}

	
	
	return newStr;
	
	
}