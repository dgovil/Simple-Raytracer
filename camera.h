#pragma once
#include "ray.h"

class camera
{
public:
	camera();
	ray get_ray(float y, float v);

	vec3 origin;
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
};
