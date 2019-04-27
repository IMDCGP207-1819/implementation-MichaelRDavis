#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
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
