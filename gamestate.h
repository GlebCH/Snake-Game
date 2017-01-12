#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "game.h"

namespace gameSnake
{
    class gameState
    {
    public:
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents(Game*) = 0;
        virtual void Update(Game*) = 0;
        virtual void Draw(Game*) = 0;

        void changeState(Game* game, gameState& state) { game->changeState(state); }
    };
}


#endif

