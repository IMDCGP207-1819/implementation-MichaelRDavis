#include "stdafx.h"
#include "World.h"
#include "EntityManager.h"
#include "../GeometryBlaster/Player.h"

World::World()
{
	m_player = std::make_unique<Player>();
	m_entityManager = std::make_unique<EntityManager>();
}

World::~World()
{

}

void World::Initialize()
{
	m_entityManager->AddEntity(m_player.get());
	m_entityManager->Initialize();
#ifdef _DEBUG
	m_entityManager->LogEntity();
#endif // _DEBUG
}

void World::Update(float deltaTime)
{
	m_entityManager->Update(deltaTime);
}

void World::Draw(SDL_Renderer* renderer)
{
	m_entityManager->Draw(renderer);
}
