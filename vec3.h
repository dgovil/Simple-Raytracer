#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3
{
public:
	vec3();
	vec3(float e0, float e1, float e2);
	
	float x() const;
	float y() const;
	float z() const;

	float r() const;
	float g() const;
	float b() const;

	const vec3& operator+() const;
	vec3 operator-() const;
	float operator[](int i) const;
	float& operator[](int i);

	vec3& operator+=(const vec3 &v2);
	vec3& operator-=(const vec3 &v2);
	vec3& operator*=(const vec3 &v2);
	vec3& operator*=(const float t);
	vec3& operator/=(const vec3 &v2);
	vec3& operator/=(const float t);

	float length() const;
	float squared_length() const;
	void make_unit_vector();

	float e[3];

};


std::istream& operator>>(std::istream &is, vec3 &t);
std::ostream& operator<<(std::ostream &os, const vec3 &t);
vec3 operator+(const vec3 &v1, const vec3 &v2);
vec3 operator-(const vec3 &v1, const vec3 &v2);
vec3 operator*(const vec3 &v1, const vec3 &v2);
vec3 operator*(float t, const vec3 &v);
vec3 operator*(const vec3 &v, float t);
vec3 operator/(const vec3 &v1, const vec3 &v2);
vec3 operator/(const vec3 &v, float t);

float dot(const vec3 &v1, const vec3 &v2);
vec3 cross(const vec3 &v1, const vec3 &v2);
vec3 unit_vector(vec3  v);