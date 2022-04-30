#pragma once
#include <string>
struct Vector2
{
	float x;
	float y;

	Vector2 operator+(const Vector2&);
	Vector2 operator-(const Vector2&);
	Vector2 operator*(const Vector2&);
	Vector2 operator/(const Vector2&);
	Vector2 Normalize(void);
	std::string ToString(void);

	static Vector2 Zero(void);
	static const Vector2 One(void);
};

