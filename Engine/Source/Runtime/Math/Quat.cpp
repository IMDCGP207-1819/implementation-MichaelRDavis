#include "stdafx.h"
#include "Quat.h"

Quat::Quat()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Quat::Quat(float inX, float inY, float inZ, float inW)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}

Quat::Quat(Quat& quat)
{
	x = quat.x;
	y = quat.y;
	z = quat.z;
	w = quat.w;
}
