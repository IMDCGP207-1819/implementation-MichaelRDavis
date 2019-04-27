#pragma once

#include "GameObject/Component.h"

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
	void LoadTexture(const std::string& filePath);

	/**  */
	void InitializeComponent();

	/**  */
	void UpdateComponent();

	/**  */
	void Draw(SDL_Renderer* renderer);

private:
	SDL_Texture* m_texture;
	SDL_Color m_color;
};