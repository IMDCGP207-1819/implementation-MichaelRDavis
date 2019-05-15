#include "stdafx.h"
#include "Math.h"

bool Math::IsNearZero(float value, float epsilon /*= 0.001f*/)
{
	if (fabs(value) <= epsilon)
	{
		return true;
	}
	else
	{
		return false;
	}
}
