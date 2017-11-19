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

bool hit_sphere(const vec3& center, float radius, const ray& r)
{
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0f * dot(oc, r.direction());
	float c = dot(oc, oc) - radius*radius;
	float discriminant = b*b - 4 * a*c;
	return (discriminant > 0);
}

vec3 color(const ray& r)
{
	if (hit_sphere(vec3(0,0,-1), 0.5f, r))
	{
		return vec3(1, 0, 0);
	}
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5f*(unit_direction.y() + 1.0f);
	return (1.0f - t)*vec3(1.0f, 1.0f, 1.0f) + t*vec3(0.5f, 0.7f, 1.0f);
}

int main()
{
	int width = 200;
	int height = 100;


	std::vector<uint8_t> image;

	vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
	vec3 horizontal(4.0f, 0.0f, 0.0f);
	vec3 vertical(0.0f, 2.0f, 0.0f);
	vec3 origin(0.0f, 0.0f, 0.0f);



	for (int row = 0; row < height; row++)
	{
		for (int column = 0;column < width; column++)
		{

			float u = float(column) / float(width);
			float v = float(height - row) / float(height);

			ray r(origin, lower_left_corner + u*horizontal + v*vertical);

			vec3 col = color(r);

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

