#include "stdafx.h"
#include "Player.h"
#include "GameObject/Components/SpriteComponent.h"
#include "Bullet.h"

Player::Player()
{
	m_sprite = std::make_unique<SpriteComponent>(m_renderer);
	m_sprite->CreateTexture("Content/Textures/Player.png");
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	//m_velocity = m_playerSpeed * // Get movement direction from gamepad
	m_position += m_velocity;
	// Clamp the player position to the game viewport
}
