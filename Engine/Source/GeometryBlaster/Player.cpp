#include "stdafx.h"
#include "Player.h"
#include "GameObject/Components/SpriteComponent.h"
#include "GameObject/Components/CollisionComponent.h"
#include "GameObject/Components/InputComponent.h"
#include "Bullet.h"

Player::Player()
{
	m_input = std::make_unique<InputComponent>();
	AddComponent(typeid(m_input), m_input.get());
	m_input->SetOwner(this);

	m_collision = std::make_unique<CollisionComponent>();
	AddComponent(typeid(m_collision), m_collision.get());
	m_collision->SetOwner(this);
	m_collision->SetRadius(5.0f);
}

Player::~Player()
{

}

void Player::Initialize(SDL_Renderer* renderer)
{
	Entity::Initialize(renderer);

	m_sprite = std::make_unique<SpriteComponent>(m_renderer);
	AddComponent(typeid(m_sprite), m_sprite.get());
	m_sprite->SetOwner(this);
	m_sprite->CreateTexture("Content/Textures/Player.png");
}

void Player::Update(float deltaTime)
{
	Entity::Update(deltaTime);

	//m_velocity = m_playerSpeed * // Get movement direction from gamepad
	m_position += m_velocity;
	// Clamp the player position to the game viewport
}

void Player::Draw(SDL_Renderer* renderer)
{
	Entity::Draw(renderer);

	if (m_sprite)
	{
		m_sprite->Draw(renderer);
	}
}
