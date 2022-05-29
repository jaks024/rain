#pragma once
#include <rain/utilities/Vector2.hpp>

template <class T>
struct Area
{
	Vector2<T> start;
	Vector2<T> end;

	Area(Vector2<T> start, Vector2<T> end)
		: start{ start }, end{ end } {}
};

