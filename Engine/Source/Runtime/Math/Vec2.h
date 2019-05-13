#pragma once

struct Vec2
{
	Vec2();
	Vec2(float inX, float inY);

	void Normalize();
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

	Vec2& operator*(float scale);
	Vec2& operator*=(float scale);

	static const Vec2 zero;
	static const Vec2 unit;

	float x;
	float y;
};