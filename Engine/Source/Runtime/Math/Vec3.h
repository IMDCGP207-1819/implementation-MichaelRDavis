#pragma once

struct Vec3
{
	Vec3();
	Vec3(float inX, float inY, float inZ);
	Vec3(const Vec3& vec);

	float x;
	float y;
	float z;
};