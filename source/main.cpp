#include "game.hpp"
Game *game = NULL;

int main( int argc, char* args[] ){
	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	if(!game->init())
	{
		std::cout << "Failed to init window" << std::endl;
	}
	else
	{
		if(!game->loadMedia())
		{
			std::cout << "Failed to load Media" << std::endl;
		}
		else
		{
			while (game->getGameState())
			{
				frameStart = SDL_GetTicks();

				game->handleEvents();
				game->update();
				game->render();

				frameTime = SDL_GetTicks() - frameStart;

				if(frameDelay > frameTime){
					SDL_Delay(frameDelay - frameTime );
				}
			}
		}

	}
	game->close();
	return 0;
}