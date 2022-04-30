#include <rain/utilities/Vector2.hpp>
#include <format>
Vector2 Vector2::operator+(const Vector2& b)
{
	Vector2 vec2;
	vec2.x = this->x + b.x;
	vec2.y = this->y + b.y;
	return vec2;
}

Vector2 Vector2::operator-(const Vector2& b)
{
	Vector2 vec2;
	vec2.x = this->x - b.x;
	vec2.y = this->y - b.y;
	return vec2;
}

Vector2 Vector2::operator*(const Vector2& b)
{
	Vector2 vec2;
	vec2.x = this->x * b.x;
	vec2.y = this->y * b.y;
	return vec2;
}

Vector2 Vector2::operator/(const Vector2& b)
{
	Vector2 vec2;
	vec2.x = this->x / b.x;
	vec2.y = this->y / b.y;
	return vec2;
}

Vector2 Vector2::Normalize()
{
	Vector2 vec2;
	float length = sqrt(x * x + y * y);
	vec2.x = x / length;
	vec2.y = y / length;
	return vec2;
}

Vector2 Vector2::Zero(void)
{
	Vector2 vec2;
	vec2.x = 0;
	vec2.y = 0;
	return vec2;
}

const Vector2 Vector2::One(void)
{
	Vector2 vec2;
	vec2.x = 1;
	vec2.y = 1;
	return vec2;
}

std::string Vector2::ToString()
{
	return std::format("({}, {})", x, y);
}
