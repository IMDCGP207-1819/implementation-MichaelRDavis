#pragma once

#include "GameObject/Component.h"

class TextureAsset;

/**
 * 
 */
class SpriteComponent : public Component
{
public:
	/** Constructor. */
	SpriteComponent(SDL_Renderer* renderer);

	/** Default destructor. */
	~SpriteComponent();

	/** Initialize this component. */
	void InitializeComponent() override;

	/** Update this component, called once per frame. */
	void UpdateComponent(float deltaTime) override;

	/**  */
	void SetFilename(const std::string& filepath);

	/**  */
	void CreateTexture(const std::string& texturePath);

	/**  */
	void Draw(SDL_Renderer* renderer);

	/**  */
	inline int32_t GetSpriteDrawOrder() const
	{
		return m_spriteDrawOrder;
	}

	/**  */
	inline int32_t GetSpriteWidth() const
	{
		return m_spriteWidth;
	}

	/**  */
	inline int32_t GetSpriteHeight() const
	{
		return m_spriteHeight;
	}

	/**  */
	inline std::string GetSpriteName() const
	{
		return m_spriteName;
	}

private:
	/** Pointer to the texture asset for this sprite. */
	std::shared_ptr<TextureAsset> m_textureAsset;

	/** Sprite texture. */
	SDL_Texture* m_texture;

	/** Cached pointer to the renderer object. */
	SDL_Renderer* m_renderer;

	/** Color of the sprite. */
	SDL_Color m_color;

	/** Sprite draw order. */
	int32_t m_spriteDrawOrder;

	/** Width of the sprite. */
	int32_t m_spriteWidth;

	/** Height of the sprite. */
	int32_t m_spriteHeight;

	/** The sprites name. */
	std::string m_spriteName;
};