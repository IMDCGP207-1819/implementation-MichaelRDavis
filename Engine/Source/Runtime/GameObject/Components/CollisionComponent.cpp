#include "stdafx.h"
#include "CollisionComponent.h"

CollisionComponent::CollisionComponent()
	: m_radius(0.0f)
{

}

CollisionComponent::~CollisionComponent()
{

}

bool CollisionComponent::Intersect(const CollisionComponent& otherComp)
{
	return true;
}

void CollisionComponent::SetRadius(float radius)
{
	m_radius = radius;
}

