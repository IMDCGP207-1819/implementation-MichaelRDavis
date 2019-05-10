#pragma once

#include "GameObject/Entity.h"

class SpriteComponent;
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

private:
	std::unique_ptr<SpriteComponent> m_sprite;
	std::unique_ptr<InputComponent> m_input;
	std::unique_ptr<Bullet> m_bullet;
	float m_playerSpeed;
	float m_fireRate;
};