#pragma once

#include "GameObject/Component.h"

/**
 * 
 */
class CollisionComponent : public Component
{
public:
	/**  */
	CollisionComponent();

	/**  */
	~CollisionComponent();

	/**  */
	bool Intersect(const CollisionComponent& otherComp);

	/**  */
	void SetRadius(float radius);

	/**  */
	inline float GetRadius() const
	{
		return m_radius;
	}

private:
	/**  */
	float m_radius;
};