#include "stdafx.h"
#include "Player.h"
#include "GameObject/Components/SpriteComponent.h"
#include "GameObject/Components/CollisionComponent.h"
#include "GameObject/Components/InputComponent.h"
#include "Input/Gamepad.h"
#include "Bullet.h"
#include "Math/Math.h"

Player::Player()
{
	m_input = std::make_unique<InputComponent>();
	AddComponent(typeid(m_input), m_input.get());
	m_input->SetOwner(this);
	m_input->InitializeComponent();

	m_collision = std::make_unique<CollisionComponent>();
	AddComponent(typeid(m_collision), m_collision.get());
	m_collision->SetOwner(this);
	m_collision->SetRadius(5.0f);

	m_playerSpeed = 3000.0f;
	m_maxLives = 3;
	m_lives = m_maxLives;
}

Player::~Player()
{

}

void Player::Initialize(SDL_Renderer* renderer)
{
	Entity::Initialize(renderer);

	m_sprite = std::make_unique<SpriteComponent>(m_renderer);
	AddComponent(typeid(m_sprite), m_sprite.get());
	m_sprite->SetOwner(this);
	m_sprite->CreateTexture("Content/Textures/Player.png");

	m_position = Vec2(950.0f, 500.0f);
}

void Player::Update(float deltaTime)
{
	Entity::Update(deltaTime);

	m_input->UpdateComponent(deltaTime);
	if (m_input->m_gamepad->GetIsConnected())
	{
		m_velocity = m_input->m_gamepad->GetLeftThumbStick();
		//if (!Math::IsNearZero(m_input->m_gamepad->GetLeftThumbStick().Size()))
		{
			//m_rotation = m_input->m_gamepad->GetLeftThumbStick();
		}
	}

	Vec2 position = GetPosition();
	position += m_velocity * m_playerSpeed * deltaTime;
	SetPosition(position);
	if (m_velocity.Size() > 0)
	{
		m_rotation = m_velocity;
		float angle = atan2f(m_rotation.y, m_rotation.x);
		SetRotation(angle);
	}
}

void Player::Draw(SDL_Renderer* renderer)
{
	Entity::Draw(renderer);

	if (m_sprite)
	{
		m_sprite->Draw(renderer);
	}
}

void Player::Fire()
{
	if (!GetIsDead())
	{
		m_bullet = std::make_unique<Bullet>();
		// TODO: Fire bullets.
		// TODO: Play fire sound.
	}
}

void Player::Destroy()
{
	if (GetIsDead())
	{
		Disable();
	}
}
