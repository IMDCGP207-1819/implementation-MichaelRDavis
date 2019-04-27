#pragma once

struct Quat
{
public:
	/** Default constructor. */
	Quat();

	/** Default copy constructor. */
	Quat(Quat& quat);

	/** Constructor. */
	Quat(float inX, float inY, float inZ, float inW);

	float x;
	float y;
	float z;
	float w;
};