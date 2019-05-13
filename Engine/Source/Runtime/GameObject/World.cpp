#include "stdafx.h"
#include "World.h"
#include "EntityManager.h"
#include "ComponentManager.h"
#include "../GeometryBlaster/Player.h"

World::World()
{
	m_player = std::make_unique<Player>();
	m_entityManager = std::make_unique<EntityManager>();
	m_componentManager = std::make_unique<ComponentManager>();
}

World::~World()
{

}

void World::Initialize(SDL_Renderer* renderer)
{
	m_entityManager->AddEntity(m_player.get());
	m_entityManager->Initialize(renderer);
#ifdef _DEBUG
	m_entityManager->LogEntity();
#endif
}

void World::Update(float deltaTime)
{
	m_entityManager->Update(deltaTime);
}

void World::Draw(SDL_Renderer* renderer)
{
	m_entityManager->Draw(renderer);
}
