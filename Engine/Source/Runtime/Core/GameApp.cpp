#include "stdafx.h"
#include "GameApp.h"
#include "Renderer.h"
#include "GameObject/World.h"
#include "Resource/AssetManager.h"
#include "Resource/TextureAsset.h"

GameApp::GameApp()
{
	m_pWindow = nullptr;
	m_width = 0;
	m_height = 0;
	m_isRunning = true;
	m_windowMode = EWindowMode::EWindowed;
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

	uint32_t windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
	m_pWindow = SDL_CreateWindow(m_windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, windowFlags);
	if (m_pWindow == nullptr)
	{
		printf("Could not create window: %s", SDL_GetError());
	}

	switch (m_windowMode)
	{
	case EFullscreen:
		SDL_SetWindowFullscreen(m_pWindow, SDL_TRUE);
		break;
	case EWindowed:
		SDL_SetWindowFullscreen(m_pWindow, 0);
		SDL_SetWindowBordered(m_pWindow, SDL_TRUE);
		SDL_MaximizeWindow(m_pWindow);
		break;
	}

	m_pRenderer = std::make_unique<Renderer>();
	if (m_pRenderer)
	{
		m_pRenderer->Initialize(m_pWindow);
	}

	m_pWorld = std::make_unique<World>();
	if (m_pWorld)
	{
		m_pWorld->Initialize();
	}

	m_assetManager = std::make_unique<AssetManager<TextureAsset>>();
	if (m_assetManager)
	{
		m_assetManager->Initialize("Texture Manager");
	}
}

void GameApp::Shutdown()
{
	SDL_DestroyRenderer(m_pRenderer->GetSDLRenderer());
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

void GameApp::Update(float deltaTime)
{
	ProcessEvents();
	m_pWorld->Update(deltaTime);
	m_pRenderer->Clear();
	m_pWorld->Draw(m_pRenderer->GetSDLRenderer());
	m_pRenderer->SwapBuffers();
}

void GameApp::ProcessEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
		{

		}
		break;
		case SDL_QUIT:
			m_isRunning = false;
			Shutdown();
			break;
		}
	}
}
