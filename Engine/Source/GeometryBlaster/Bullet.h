#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;
class CollisionComponent;

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet();

	void Initialize(SDL_Renderer* renderer) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

private:
	std::unique_ptr<SpriteComponent> m_sprite;
	std::unique_ptr<CollisionComponent> m_collision;
	int32_t m_damage;
};