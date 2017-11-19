// SimpleRaytracer.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <vector>
#include "iostream"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "vec3.h"
#include <fstream>
#include "ray.h"
#include "hitable.h"
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"
#include "camera.h"


vec3 color(const ray& r, hitable *world)
{
	hit_record rec;
	if (world->hit(r, 0.0, FLT_MAX, rec))
	{
		return 0.5*vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}

	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5f*(unit_direction.y() + 1.0f);
	return (1.0f - t)*vec3(1.0f, 1.0f, 1.0f) + t*vec3(0.5f, 0.7f, 1.0f);
}

#ifdef _WIN32
float drand48()
{
	return rand() / (RAND_MAX + 1.0f);
}
#endif


int main()
{
	int width = 200;
	int height = 100;
	int samples = 32;


	std::vector<uint8_t> image;
	hitable *list[2];

	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitable *world = new hitable_list(list, 2);

	camera cam;

	for (int row = 0; row < height; row++)
	{
		for (int column = 0;column < width; column++)
		{
			vec3 col = vec3(0, 0, 0);
			for (int sample = 0;sample<samples;sample++)
			{
				float u = float(column + drand48()) / float(width);
				float v = float((height - row) + drand48()) / float(height);
				ray r = cam.get_ray(u, v);
				col += color(r, world);
			}

			col /= float(samples);
			

			uint8_t ir = static_cast<uint8_t>(255.99f * col.r());
			uint8_t ig = static_cast<uint8_t>(255.99f * col.g());
			uint8_t ib = static_cast<uint8_t>(255.99f * col.b());
			image.push_back(ir);
			image.push_back(ig);
			image.push_back(ib);


			
		}
	}

	stbi_write_jpg("test.jpg", width, height, 3, image.data(), 100);

	return 0;
}

