
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "pch.h"
#include "SDL.h"
#include "gamestate.h"
#include "map.h"
#include "snake.h"

namespace gameSnake
{
    class playState : public gameState
    {
    private:
        unsigned M_HEIGHT, M_WIDTH;

        Map& map = Map::Instance();
        Snake snake;

        static playState _playState;
        Direction dir = RIGHT;

        playState();
    public:
        ~playState();

        void Pause();
        void Resume();

        void HandleEvents(Game*);
        void Update(Game*);
        void Draw(Game*);

        static playState& Instance() { return _playState; }
    };

}

#endif
