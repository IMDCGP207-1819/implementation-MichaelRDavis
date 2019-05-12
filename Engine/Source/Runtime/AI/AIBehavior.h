#pragma once

#include "Math/Vec2.h"

class Entity;

/**
 * 
 */
class AIBehavior
{
public:
	/** Constructor. */
	AIBehavior(Entity* entity);

	/** Default destructor. */
	~AIBehavior();

	/** Seek AI behavior. */
	Vec2 Seek(Vec2 seekTarget);

	/** Wander AI behavior. */
	Vec2 Wander();

private:
	/** The entity that is controlled by this behavior. */
	Entity* m_owner;
};