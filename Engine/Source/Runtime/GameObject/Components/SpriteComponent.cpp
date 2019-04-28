#include "stdafx.h"
#include "SpriteComponent.h"
#include "Core/Renderer.h"
#include "Resource/AssetManager.h"
#include "Resource/TextureAsset.h"

SpriteComponent::SpriteComponent()
{
	m_texture = nullptr;
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
	
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (m_texture)
	{

	}
}
