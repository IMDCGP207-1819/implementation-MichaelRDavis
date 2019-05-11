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

	void SetOwner(Entity* newOwner);

	inline Entity* GetOwner() const
	{
		return m_owner;
	}

private:
	std::unique_ptr<SpriteComponent> m_sprite;
	std::unique_ptr<CollisionComponent> m_collision;
	Entity* m_owner;
	int32_t m_damage;
};