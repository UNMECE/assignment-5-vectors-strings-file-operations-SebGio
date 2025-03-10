#include "pixel.h"
#include <iostream>
#include <fstream>
#include <string>

void average_colors(std::vector<Pixel>& pixel_list)
{
	float rAverage = 0;
	float gAverage = 0;
	float bAverage = 0;

	for (int i = 0; i < pixel_list.size(); ++i)
	{
		rAverage += pixel_list.at(i).r;
		gAverage += pixel_list.at(i).g;
		bAverage += pixel_list.at(i).b;
	}
	rAverage = rAverage / pixel_list.size();
	gAverage = gAverage / pixel_list.size();
	bAverage = bAverage / pixel_list.size();
	std::cout << "Average Color: R: " << rAverage << " G: " << gAverage << " B: " << bAverage << std::endl;
}

void flip_vertically(std::vector<Pixel>& pixel_list)
{
	//open file
	std::ofstream out;
	out.open("flipped.dat", std::ios::out);

	//make sure file is correctly opened
	if (!out.is_open())
	{
		std::cout << "Error saving to" << "flipped.dat" << std::endl;
		return;
	}
	
	//write to file
	else
	{
		int size = pixel_list.size();
		for (int i = 0; i < size; ++i)
		{
			out << pixel_list.at(i).x << "," << pixel_list.at(size - (i + 1)).y << "," << pixel_list.at(i).r << "," << pixel_list.at(i).g << "," << pixel_list.at(i).b << std::endl;
		}
	}
	out.close();
}

