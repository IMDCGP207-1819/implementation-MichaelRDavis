#include "stdafx.h"
#include "Core/GameApp.h"

int main()
{
	std::unique_ptr<GameApp> game = std::make_unique<GameApp>();
	try
	{
		game->Startup();
		while (game->GetIsRunning())
		{
			float deltaTime = static_cast<float>(SDL_GetTicks());
			game->Update(deltaTime);
		}
		game->Shutdown();
	}
	catch (const std::exception& exception)
	{
		printf("%s", exception.what());
		game->Shutdown();
	}

	return 0;
}