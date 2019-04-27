#pragma once

struct Vec2
{
	Vec2();
	Vec2(float inX, float inY);
	Vec2(const Vec2& vec);

	float Size() const;
	float SizeSquared() const;

	Vec2 operator+(const Vec2& vec);
	Vec2 operator-(const Vec2& vec);
	Vec2 operator/(const Vec2& vec);
	Vec2 operator*(const Vec2& vec);

	Vec2 operator+=(const Vec2& vec);
	Vec2 operator-=(const Vec2& vec);
	Vec2 operator/=(const Vec2& vec);
	Vec2 operator*=(const Vec2& vec);

	float x;
	float y;
};