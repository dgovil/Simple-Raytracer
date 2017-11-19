#include "stdafx.h"
#include "ray.h"

ray::ray(){}

ray::ray(const vec3& a, const vec3& b)
{
	A = a;
	B = b;
}

vec3 ray::origin() const
{
	return A;
}

vec3 ray::direction() const
{
	return B;
}

vec3 ray::point_at_parameter(float t) const
{
	return A + t*B;
}
