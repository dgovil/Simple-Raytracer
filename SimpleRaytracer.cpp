// SimpleRaytracer.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <vector>
#include "iostream"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <fstream>

int main()
{
	int width = 640;
	int height = 480;

	std::ofstream ppm;
	ppm.open("test.ppm");
	std::vector<int> image;

	ppm << "P3\n" << width << " " << height << "\n255\n";

	for (int row = 0; row < height; row++)
	{
		for (int col = 0;col < width; col++)
		{

			float r = float(col) / float(width);
			float g = float(height - row) / float(height);
			float b = 0.2;

			int ir = int(255.99 * r);
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);

			image.push_back(ir);
			image.push_back(ig);
			image.push_back(ib);


			ppm << ir << " " << ig << " " << ib << "\n";
			
		}
	}

	stbi_write_jpg("test.jpg", width, height, 3, image.data(), 100);
	ppm.close();

	return 0;
}

