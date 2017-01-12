#include "game.h"
#include "gamestate.h"

using namespace gameSnake;

Game::Game()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    screen = SDL_GetWindowSurface(window);

    mRunning = true;
}

Game::~Game()
{
    SDL_FreeSurface(screen);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);

    window = nullptr;
    render = nullptr;

    SDL_Quit();
}

void Game::pushState(gameState& newState)
{
    if(!states.empty())
    {
        states.back().get().Pause();
    }

    states.push_back(newState);//cкорее всего не так
}

void Game::changeState(gameState& newState)
{
    if(!states.empty()) states.pop_back();

    states.push_back(newState);
}

void Game::popState()
{
    if(!states.empty()) states.pop_back();
    if(!states.empty()) states.back().get().Resume();
}

void Game::HandleEvents()
{
    states.back().get().HandleEvents(this);
}

void Game::Update()
{
    states.back().get().Update(this);
}

void Game::Draw()
{
    states.back().get().Draw(this);
}
