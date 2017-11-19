#include "stdafx.h"
#include "camera.h"

camera::camera()
{
	lower_left_corner = vec3(-2.0f, -1.0f, -1.0f);
	horizontal = vec3(4.0f, 0.0f, 0.0f);
	vertical = vec3(0.0f, 2.0f, 0.0f);
	origin = vec3(0.0f, 0.0f, 0.0f);
}

ray camera::get_ray(float u, float v)
{
	return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
}
