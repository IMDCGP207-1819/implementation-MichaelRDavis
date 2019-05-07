#include "stdafx.h"
#include "SpriteComponent.h"
#include "Core/Renderer.h"
#include "Resource/AssetManager.h"
#include "Resource/TextureAsset.h"

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

void SpriteComponent::CreateTexture(const std::string& texturePath)
{
	m_textureAsset = AssetManager<TextureAsset>::GetObject()->Load(texturePath);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_textureAsset->LoadTextureAsset());
	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_spriteWidth, &m_spriteHeight);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (m_texture)
	{
		SDL_Rect rect;
		rect.w = m_spriteWidth;
		rect.h = m_spriteHeight;
		rect.x = rect.w / 2;
		rect.y = rect.h / 2;

		SDL_RenderCopyEx(
			m_renderer,
			m_texture,
			nullptr,
			&rect,
			0.0f,
			nullptr,
			SDL_FLIP_NONE);
	}
}
