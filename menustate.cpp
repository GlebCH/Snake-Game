#include "menustate.h"

using namespace gameSnake;

menuState::menuState()
{
    bg = SDL_LoadBMP("/home/gleb/stateMenedger/menu.bmp");
}

menuState::~menuState()
{
    SDL_FreeSurface(bg);
}

void menuState::Pause()
{
}

void menuState::Resume()
{
}

void menuState::HandleEvents(Game* game)
{
    SDL_Event event;

    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                game->Quit();
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        game->Quit();
                        break;
                    case SDLK_SPACE:
                        game->changeState(playState::Instance());
                        break;
                }
                break;
        }
    }
}

void menuState::Update(Game*)
{
//
}

void menuState::Draw(Game* game)
{
    SDL_BlitSurface(bg, NULL, game->screen, NULL);
    SDL_UpdateWindowSurface(game->window);
}
