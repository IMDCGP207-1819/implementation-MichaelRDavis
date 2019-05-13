#include "stdafx.h"
#include "Vec2.h"

Vec2& Vec2::operator*=(float scale)
{
	x *= scale;
	y *= scale;
	return *this;
}

const Vec2 Vec2::zero(0.0f, 0.0f);
const Vec2 Vec2::unit(1.0f, 1.0f);

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

void Vec2::Normalize()
{
	float vecSize = Size();
	if (vecSize > std::numeric_limits<float>::epsilon())
	{
		x /= vecSize;
		y /= vecSize;
	}
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
