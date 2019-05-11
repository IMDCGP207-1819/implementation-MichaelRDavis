#pragma once

#include "Math/Vec2.h"

class Entity;

/**
 * 
 */
class AIBehvaior
{
public:
	/** Default constructor. */
	AIBehvaior();

	/** Default destructor. */
	~AIBehvaior();

	/** Set the owner for this AI behavior. */
	void SetOwner(Entity* newOwner);

	/** Returns the owner of this behavior.*/
	inline Entity* GetOwner() const
	{
		return m_owner;
	}

private:
	/** Entity that owns this AI behavior. */
	Entity* m_owner;
};