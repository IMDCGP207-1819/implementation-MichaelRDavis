#pragma once

#include "GameObject/Component.h"

class TextureAsset;

/**
 * 
 */
class SpriteComponent : public Component
{
public:
	/**  */
	SpriteComponent(SDL_Renderer* renderer);

	/**  */
	~SpriteComponent();

	/**  */
	void InitializeComponent() override;

	/**  */
	void UpdateComponent(float deltaTime) override;

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

private:
	/**  */
	std::shared_ptr<TextureAsset> m_textureAsset;

	/**  */
	SDL_Texture* m_texture;

	/**  */
	SDL_Renderer* m_renderer;

	/**  */
	SDL_Color m_color;

	/**  */
	int32_t m_spriteDrawOrder;

	/**  */
	int32_t m_spriteWidth;

	/**  */
	int32_t m_spriteHeight;
};