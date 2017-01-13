#include "pausestate.h"

using namespace gameSnake;

pauseState::pauseState()
{
    bg = SDL_LoadBMP("/home/gleb/stateMenedger/pause.bmp");
}

pauseState::~pauseState()
{
    SDL_FreeSurface(bg);
}

void pauseState::Pause()
{
}

void pauseState::Resume()
{
}

void pauseState::HandleEvents(Game* game)
{
    SDL_Event event;

    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            game->Quit();
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    game->changeState(playState::Instance());
                break;
                case SDLK_SPACE:
                    game->changeState(menuState::Instance());
                break;
            }
            break;
        }
    }
}

void pauseState::Update(Game*)
{
    //
}

void pauseState::Draw(Game* game)
{
    SDL_BlitSurface(bg, NULL, game->screen, NULL);
    SDL_UpdateWindowSurface(game->window);
}
