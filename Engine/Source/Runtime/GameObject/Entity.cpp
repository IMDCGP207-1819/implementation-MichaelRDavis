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

}

void Entity::Draw(SDL_Renderer* renderer)
{

}

void Entity::AddComponent(std::type_index type, Component* comp)
{
	m_componentList[type] = comp;
}

void Entity::SetType(const std::string& type)
{
	m_type = type;
}
