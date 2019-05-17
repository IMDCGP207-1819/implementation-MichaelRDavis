#pragma once

#include "GameObject/Component.h"

/**
 * A circle based collision component used for collision detection.
 */
class CollisionComponent : public Component
{
public:
	/** Default constructor. */
	CollisionComponent();

	/** Default destructor. */
	~CollisionComponent();

	/**  */
	bool Intersect(const CollisionComponent& otherComp);

	/** Set the radius of this collision component. */
	void SetRadius(float radius);

	/** Returns the radius of the collision component. */
	inline float GetRadius() const
	{
		return m_radius;
	}

private:
	/** Collision radius. */
	float m_radius;
};