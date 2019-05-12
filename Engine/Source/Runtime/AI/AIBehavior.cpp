#include "stdafx.h"
#include "AIBehavior.h"
#include "GameObject/Entity.h"

AIBehavior::AIBehavior(Entity* entity)
	: m_owner(entity)
{

}

AIBehavior::~AIBehavior()
{

}

Vec2 AIBehavior::Seek(Vec2 seekTarget)
{
	Vec2 velocity = seekTarget - m_owner->GetPosition();
	velocity.Normalize();

	return Vec2::zero;
}

Vec2 AIBehavior::Wander()
{
	return Vec2::zero;
}
