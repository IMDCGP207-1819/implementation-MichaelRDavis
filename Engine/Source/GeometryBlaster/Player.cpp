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
