#include "stdafx.h"
#include "Bullet.h"
#include "GameObject/Components/SpriteComponent.h"
#include "GameObject/Components/CollisionComponent.h"

Bullet::Bullet()
{
	m_collision = std::make_unique<CollisionComponent>();
	AddComponent(typeid(m_collision), m_collision.get());
	m_collision->SetOwner(this);
	m_collision->SetRadius(5.0f);
}

Bullet::~Bullet()
{

}

void Bullet::Initialize(SDL_Renderer* renderer)
{
	Entity::Initialize(renderer);

	m_sprite = std::make_unique<SpriteComponent>(renderer);
	AddComponent(typeid(m_sprite), m_sprite.get());
	m_sprite->SetOwner(this);
	m_sprite->CreateTexture("Content/Textures/Bullet.png");
}

void Bullet::Update(float deltaTime)
{
	Entity::Update(deltaTime);
}

void Bullet::Draw(SDL_Renderer* renderer)
{
	Entity::Draw(renderer);
}

void Bullet::SetOwner(Entity* newOwner)
{
	m_owner = newOwner;
}
