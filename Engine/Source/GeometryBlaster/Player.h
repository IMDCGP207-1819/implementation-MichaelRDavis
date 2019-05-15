#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;
class CollisionComponent;
class InputComponent;
class Bullet;

class Player : public Entity
{
public:
	Player();
	~Player();

	void Initialize(SDL_Renderer* renderer) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

	void Fire();

	void Destroy();

	inline bool GetIsDead() const
	{
		if (m_lives == 0)
			return true;
		else
			return false;
	}

private:
	std::unique_ptr<SpriteComponent> m_sprite;
	std::unique_ptr<CollisionComponent> m_collision;
	std::unique_ptr<InputComponent> m_input;
	std::unique_ptr<Bullet> m_bullet;

	int32_t m_lives;
	int32_t m_maxLives;
	Vec2 m_rotation;
	float m_playerSpeed;
	float m_fireRate;
};