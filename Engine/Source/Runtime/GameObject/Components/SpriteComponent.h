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
	SpriteComponent();

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

private:
	std::shared_ptr<TextureAsset> m_textureAsset;
	SDL_Texture* m_texture;
	SDL_Color m_color;
};