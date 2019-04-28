#include "stdafx.h"
#include "TextureAsset.h"

TextureAsset::TextureAsset(const std::string textureAssetName)
	: Asset(textureAssetName)
{

}

TextureAsset::~TextureAsset()
{

}

SDL_Surface* TextureAsset::LoadTextureAsset()
{
	SDL_Surface* texSurface = IMG_Load(m_assetName.c_str());
	if (!texSurface)
	{
		printf("Unable to load texture asset: %s", m_assetName.c_str());
	}

	return texSurface;
}
