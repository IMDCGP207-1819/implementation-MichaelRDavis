#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Initialize()
{

}

void Entity::Update(float deltaTime)
{
	if (m_isActive)
	{

	}
}

void Entity::Draw(SDL_Renderer* renderer)
{

}

void Entity::AddComponent(std::type_index type, Component* comp)
{
	m_componentList[type] = comp;
}

void Entity::SetPosition(Vec2 newPosition)
{
	m_position = newPosition;
}

void Entity::SetVelcity(Vec2 newVelocity)
{
	m_velocity = newVelocity;
}

void Entity::SetType(const std::string& type)
{
	m_type = type;
}

void Entity::Enable()
{
	m_isActive = true;
}

void Entity::Disable()
{
	m_isActive = false;
}
