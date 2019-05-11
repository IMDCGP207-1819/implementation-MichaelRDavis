#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet();

	void Update(float deltaTime) override;

private:
	std::unique_ptr<SpriteComponent> m_sprite;
	int32_t m_damage;
};