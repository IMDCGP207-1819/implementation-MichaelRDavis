#include "stdafx.h"
#include "Vec2.h"

Vec2::Vec2()
{
	x = 0.0f;
	y = 0.0f;
}

Vec2::Vec2(float inX, float inY)
{
	x = inX;
	y = inY;
}

float Vec2::Size() const
{
	return sqrt(SizeSquared());
}

float Vec2::SizeSquared() const
{
	return (x * x + y * y);
}

Vec2 Vec2::operator+(const Vec2& vec)
{
	return Vec2(x + vec.x, y + vec.y);
}

Vec2 Vec2::operator-(const Vec2& vec)
{
	return Vec2(x - vec.x, y - vec.y);
}

Vec2 Vec2::operator/(const Vec2& vec)
{
	return Vec2(x / vec.x, y / vec.y);
}

Vec2 Vec2::operator*(const Vec2& vec)
{
	return Vec2(x * vec.x, y * vec.y);
}

Vec2 Vec2::operator*=(const Vec2& vec)
{
	x *= vec.x;
	y *= vec.y;
	return *this;
}

Vec2 Vec2::operator/=(const Vec2& vec)
{
	x /= vec.x;
	y /= vec.y;
	return *this;
}

Vec2 Vec2::operator-=(const Vec2& vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

Vec2 Vec2::operator+=(const Vec2& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}
