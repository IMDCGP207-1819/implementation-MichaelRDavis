#include "stdafx.h"
#include "Vec3.h"

Vec3::Vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vec3::Vec3(float inX, float inY, float inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

Vec3::Vec3(const Vec3& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}
