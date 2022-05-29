#pragma once
#include <string>
#include <format>

template <class T>
struct Vector2
{
	T x;
	T y;

	Vector2<T> operator+(const Vector2<T>& b)
	{
		Vector2 vec2;
		vec2.x = this->x + b.x;
		vec2.y = this->y + b.y;
		return vec2;
	}

	Vector2<T> operator-(const Vector2<T>& b)
	{
		Vector2 vec2;
		vec2.x = this->x - b.x;
		vec2.y = this->y - b.y;
		return vec2;
	}

	Vector2<T> operator*(const Vector2<T>& b)
	{
		Vector2 vec2;
		vec2.x = this->x * b.x;
		vec2.y = this->y * b.y;
		return vec2;
	}

	Vector2<T> operator/(const Vector2<T>& b)
	{
		Vector2<T> vec2;
		vec2.x = this->x / b.x;
		vec2.y = this->y / b.y;
		return vec2;
	}

	Vector2<T> Normalize()
	{
		Vector2<T> vec2;
		T length = sqrt(x * x + y * y);
		vec2.x = x / length;
		vec2.y = y / length;
		return vec2;
	}

	void Set(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	static const Vector2<T> Zero(void)
	{
		Vector2<T> vec2;
		vec2.x = 0;
		vec2.y = 0;
		return vec2;
	}

	static const Vector2<T> One(void)
	{
		Vector2<T> vec2;
		vec2.x = 1;
		vec2.y = 1;
		return vec2;
	}

	std::string ToString()
	{
		return std::format("({}, {})", x, y);
	}

};

