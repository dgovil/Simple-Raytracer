// SimpleRaytracer.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <vector>
#include "iostream"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "vec3.h"
#include <fstream>

int main()
{
	int width = 640;
	int height = 480;


	std::vector<uint8_t> image;


	for (int row = 0; row < height; row++)
	{
		for (int col = 0;col < width; col++)
		{

			vec3 color(
				float(col) / float(width),
				float(height - row) / float(height),
				0.2f

			);

			uint8_t ir = static_cast<uint8_t>(255.99 * color.r());
			uint8_t ig = static_cast<uint8_t>(255.99 * color.g());
			uint8_t ib = static_cast<uint8_t>(255.99 * color.b());
			image.push_back(ir);
			image.push_back(ig);
			image.push_back(ib);


			
		}
	}

	stbi_write_jpg("test.jpg", width, height, 3, image.data(), 100);

	return 0;
}

