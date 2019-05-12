#include "stdafx.h"
#include "SpriteComponent.h"
#include "Core/Renderer.h"
#include "Resource/AssetManager.h"
#include "Resource/TextureAsset.h"
#include "GameObject/Entity.h"

SpriteComponent::SpriteComponent(SDL_Renderer* renderer)
{
	m_texture = nullptr;
	m_renderer = renderer;
	m_spriteDrawOrder = 0;
	m_spriteWidth = 0;
	m_spriteHeight = 0;
}

SpriteComponent::~SpriteComponent()
{
	m_texture = nullptr;
}

void SpriteComponent::InitializeComponent()
{
	
}

void SpriteComponent::UpdateComponent(float deltaTime)
{

}

void SpriteComponent::SetFilename(const std::string& filepath)
{
	m_spriteName = filepath;
	CreateTexture(m_spriteName);
}

void SpriteComponent::CreateTexture(const std::string& texturePath)
{
	m_textureAsset = AssetManager<TextureAsset>::GetObject()->Load(texturePath);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_textureAsset->LoadTextureAsset());
	if (m_texture == nullptr)
	{
		printf("Failed to create texture for %s", texturePath.c_str());
	}
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (m_texture)
	{
		SDL_Rect rect;
		rect.w = static_cast<int32_t>(m_entityOwner->GetScale() * m_spriteWidth);
		rect.h = static_cast<int32_t>(m_entityOwner->GetScale() * m_spriteHeight);
		rect.x = static_cast<int32_t>(m_entityOwner->GetPosition().x - rect.w / 2);
		rect.y = static_cast<int32_t>(m_entityOwner->GetPosition().y - rect.h / 2);

		SDL_QueryTexture(m_texture, nullptr, nullptr, &m_spriteWidth, &m_spriteHeight);

		SDL_RenderCopyEx(
			m_renderer,
			m_texture,
			nullptr,
			&rect,
			m_entityOwner->GetRotation(),
			nullptr,
			SDL_FLIP_NONE);
	}
}
