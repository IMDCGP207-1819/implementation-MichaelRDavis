#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;

class Player : public Entity
{
public:
	Player();
	~Player();

private:
	std::unique_ptr<SpriteComponent> m_sprite;
};