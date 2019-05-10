#pragma once

#include "Asset.h"

/**
 * Asset object for loading texture assets.
 */
class TextureAsset : public Asset
{
public:
	/** Constructor. */
	TextureAsset(const std::string textureAssetName);

	/** Default destructor. */
	~TextureAsset();

	/** Loads a texture object. */
	SDL_Surface* LoadTextureAsset();

private:
	/** The texture surface. */
	SDL_Surface* m_texSurface;
};