#include <iostream>
#include <fstream>

#include "leveleditor.h"

void LevelEditor::GenerateLevel()
{

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