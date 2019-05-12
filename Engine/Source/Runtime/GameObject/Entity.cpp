#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{
	m_position = Vec2(0.0f, 0.0f);
	m_scale  = 1.0f;
	m_isActive = true;
}

Entity::~Entity()
{

}

void Entity::Initialize(SDL_Renderer* renderer)
{
	m_renderer = renderer;

#ifdef _DEBUG
	LogComponents();
#endif 
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

void Entity::SetScale(float newScale)
{
	m_scale = newScale;
}

void Entity::SetRotation(float newRotation)
{
	m_rotation = newRotation;
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
