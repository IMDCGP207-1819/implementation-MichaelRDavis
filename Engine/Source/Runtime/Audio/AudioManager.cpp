#include "stdafx.h"
#include "AudioManager.h"

AudioManager::AudioManager(World* world)
	: m_world(world)
{

}

AudioManager::~AudioManager()
{

}

void AudioManager::Initilaize()
{
	FMOD::Debug_Initialize(FMOD_DEBUG_LEVEL_ERROR, FMOD_DEBUG_MODE_TTY);
}

void AudioManager::Shutdown()
{

}

void AudioManager::Update()
{

}
