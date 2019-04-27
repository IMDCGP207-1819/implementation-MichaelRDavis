#include "stdafx.h"
#include "Player.h"
#include "GameObject/Components/SpriteComponent.h"

Player::Player()
{
	m_sprite = std::make_unique<SpriteComponent>();
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
