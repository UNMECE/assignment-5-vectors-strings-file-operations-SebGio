#include "pixel.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{

	std::vector<Pixel> pixel_list;
	
	if(argc < 2)
	{
		std::cout << "Program requires an argument to specify a file." << std::endl;
		return 1;
	}
	//open file
	std::string file = argv[1];
	std::ifstream in;
	in.open(file, std::ios::in);
	
	//make sure file is correctly opened
	if (!in.is_open())
	{
	std::cout << "File " << file << " could not be opened. Please make sure the full file name is use and that it is spelled correctly." << std::endl;
	return 1;
	}

	////create pixel vector
	Pixel pic;
	std::string line;
	while (!in.eof())
	{
		std::getline(in, line);
		int prevFind = 0;
		int lastFind = line.find(",");
		//get x and y values
		pic.x = std::stoi(line.substr(prevFind, lastFind - prevFind));
		prevFind = lastFind + 1;
		lastFind = line.find(",", prevFind);
		pic.y = std::stoi(line.substr(prevFind, lastFind - prevFind));
		prevFind = lastFind + 1;
		lastFind = line.find(",", prevFind);
		//get rgb values
		pic.r = std::stof(line.substr(prevFind, lastFind - prevFind));
		prevFind = lastFind + 1;
		lastFind = line.find(",", prevFind);
		pic.g = std::stof(line.substr(prevFind, lastFind - prevFind));
		prevFind = lastFind + 1;
		lastFind = line.find(",", prevFind);
		pic.b = std::stof(line.substr(prevFind, lastFind - prevFind));
		//add to list
		pixel_list.push_back(pic);
	}
	in.close();

	average_colors(pixel_list);
	flip_vertically(pixel_list);
	return 0;
}
