#include <Game.hpp>
#include <MenuState.hpp>
#include <GameState.hpp>
SDL_Renderer* Game::renderer = NULL;
TTF_Font* Game::font = NULL;
Game::Game(int width, int height, std::string title){
	// Init SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		std::cout<<"SDL could not initialize! SDL Error:"<<SDL_GetError()<<std::endl;
        this->data->isRunning = false;
	}
    else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) )
		{
			std::cout<<"Warning: Linear texture filtering not enabled!"<<std::endl;
            this->data->isRunning = false;
		}
		//Create window
		this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
		if( this->window == NULL )
		{
			std::cout<<"Window could not be created!"<<SDL_GetError()<<std::endl;
			this->data->isRunning = false;
		}
		else
		{
			//Create renderer for window
			this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( this->renderer == NULL )
			{
				std::cout<<"Renderer could not be created! SDL Error:"<<SDL_GetError()<<std::endl;
                this->data->isRunning = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					std::cout<<"SDL_image could not initialize! SDL_image Error:"<<IMG_GetError()<<std::endl;
                    this->data->isRunning = false;
				}
			}
		}
		if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            this->data->isRunning = false;
        }
		if (TTF_Init() == -1){
			printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
			this->data->isRunning = false;
		}
		else {
			this->font = TTF_OpenFont(FONT_PATH, FONT_SIZE);
		}
    }

	//**************************************************//
	this->data->machine.addState(StateRef(std::make_unique<MenuState>(this->data)));
	this->run();
}  
Game::~Game(){
	TTF_CloseFont(this->font);
	this->font = NULL;
	Mix_Quit();
	TTF_Quit();
    SDL_DestroyRenderer(this->renderer);
    this->renderer = NULL;
    SDL_DestroyWindow(this->window);
    this->window = NULL;
    SDL_Quit();
    std::cout<<"ShinoAki"<<std::endl;
}

void Game::run(){
	while (this->data->isRunning)
	{
		SDL_RenderClear(this->renderer);
		this->data->machine.processStateChanges();
		this->data->machine.getActiveState()->handleInput();
		this->data->machine.getActiveState()->update();
		this->data->machine.getActiveState()->draw();
		SDL_RenderPresent(this->renderer);
	}
}