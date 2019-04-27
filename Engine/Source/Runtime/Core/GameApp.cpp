#include "stdafx.h"
#include "GameApp.h"

GameApp::GameApp()
{
	m_pWindow = nullptr;
	m_width = 0;
	m_height = 0;
	m_isRunning = true;
}

GameApp::~GameApp()
{
	m_pWindow = nullptr;
}

void GameApp::Startup()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Unable to initialize SDL: %s", SDL_GetError());
		return;
	}

	SDL_DisplayMode displayMode;
	for (int32_t i = 0; i < SDL_GetNumVideoDisplays(); i++)
	{
		int32_t display = SDL_GetCurrentDisplayMode(i, &displayMode);
		if (display != 0)
		{
			printf("Could not get display mode for video display #%d: %s", i, SDL_GetError());
			return;
		}

		m_width = displayMode.w;
		m_height = displayMode.h;
	}

	uint32_t windowFlags = SDL_WINDOW_SHOWN;
	m_pWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, windowFlags);
	if (m_pWindow == nullptr)
	{
		printf("Could not create window: %s", SDL_GetError());
	}
}

void GameApp::Shutdown()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

void GameApp::Update(float deltaTime)
{

}
