#include <Game.hpp>
#include <defs.hpp>
#include <Map.hpp>
#include <Player.hpp>
SDL_Renderer* Game::gRenderer = NULL;
Map m;
Player p;
Game::Game(){}
Game::~Game(){}

bool Game::init(){
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				//Initialize SDL_Mixer

				//Initialize SDL_ttf
				// if( TTF_Init() == -1)
				// {
				// 	printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				// }
			}
		}
	}
	return success;
}

bool Game::loadMedia(){

	bool success = true;
	SDL_Color textColor = {0, 0, 0, 255};
	if (!m.loadMap()){
		success = false;
	}
	if(!p.loadPlayer()){
		success = false;
	}
	return success;

}

void Game::handleEvents(){

    //Event handler
    SDL_Event e;
	//Handle events on queue


	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			isRunning = false;
		}
		else
		{
			p.handleInput(e);
		}
	}
}
void Game::update(){
	m.update();
	p.update();
}

void Game::render(){
	//Clear screen
	SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255 );
	SDL_RenderClear( gRenderer );
	//Update Screen
	m.draw();
	p.draw();
	SDL_RenderPresent( gRenderer );
	//Update frames

}

void Game::close(){

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	SDL_Quit();
	std::cout << "Game clear"<<std::endl;
}