
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

        Direction dir = RIGHT;

        playState();
        ~playState();

        playState(const playState&) = delete;
        playState& operator = (const playState&) = delete;
    public:
        static playState& Instance()
        {
            static playState ps;\
            return ps;
        }

        void Pause();
        void Resume();

        void HandleEvents(Game*);
        void Update(Game*);
        void Draw(Game*);
    };

}

#endif
