#include "stdafx.h"
#include "TextureAsset.h"

TextureAsset::TextureAsset(const std::string textureAssetName)
	: Asset(textureAssetName)
{

}

TextureAsset::~TextureAsset()
{
	SDL_FreeSurface(m_texSurface);
}

SDL_Surface* TextureAsset::LoadTextureAsset()
{
	m_texSurface = IMG_Load(m_assetName.c_str());
	if (!m_texSurface)
	{
		printf("Unable to load texture asset: %s", m_assetName.c_str());
	}

	return m_texSurface;
}
