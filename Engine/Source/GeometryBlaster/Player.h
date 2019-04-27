#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;

class Player : public Entity
{
public:
	Player();
	~Player();

	void Update(float deltaTime) override;

private:
	std::unique_ptr<SpriteComponent> m_sprite;
	float m_playerSpeed;
};