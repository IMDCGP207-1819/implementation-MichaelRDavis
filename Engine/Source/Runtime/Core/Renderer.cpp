#include "stdafx.h"
#include "Renderer.h"

Renderer *Renderer::m_gRenderer = nullptr;

Renderer::Renderer()
{
	m_pRenderer = nullptr;
}

Renderer::~Renderer()
{
	m_pRenderer = nullptr;
}

void Renderer::Initialize(SDL_Window* window)
{
	m_pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Renderer::Clear()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 191, 255, 255);
	SDL_RenderClear(m_pRenderer);
}

void Renderer::SwapBuffers()
{
	SDL_RenderPresent(m_pRenderer);
}
