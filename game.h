#ifndef GAME_H
#define GAME_H

#include "pch.h"
#include "SDL.h"

namespace gameSnake
{
    class gameState;

    class Game
    {
    private:
        std::vector<std::reference_wrapper<gameState>> states;

        bool mRunning;
    public:
        Game();
        ~Game();

        void pushState(gameState&);
        void changeState(gameState&);
        void popState();

        void HandleEvents();
        void Update();
        void Draw();

        void Quit() { mRunning = false; }
        bool Running() { return mRunning; }

        SDL_Window* window;
        SDL_Renderer* render;
        SDL_Surface* screen;
    };

}

#endif // GAME_H
