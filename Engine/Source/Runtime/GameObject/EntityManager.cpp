#include "stdafx.h"
#include "EntityManager.h"
#include "Entity.h"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{

}

void EntityManager::AddEntity(Entity* entity)
{
	m_entityList.push_back(entity);
}

void EntityManager::Initialize(SDL_Renderer* renderer)
{
	for (auto entity : m_entityList)
	{
		entity->Initialize(renderer);
	}
}

void EntityManager::Update(float deltaTime)
{
	for (auto entity : m_entityList)
	{
		entity->Update(deltaTime);
	}
}

void EntityManager::Draw(SDL_Renderer* renderer)
{
	for (auto entity : m_entityList)
	{
		entity->Draw(renderer);
	}
}
