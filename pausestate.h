#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "SDL.h"
#include "gamestate.h"
#include "playstate.h"
#include "menustate.h"

namespace gameSnake
{
    class pauseState : public gameState
    {
        SDL_Surface* bg;

        pauseState();
        ~pauseState();

        pauseState(const pauseState&) = delete;
        pauseState& operator = (const pauseState&) = delete;
    public:
        static pauseState& Instance()
        {
            static pauseState ps;
            return ps;
        }

        void Pause();
        void Resume();

        void HandleEvents(Game*);
        void Update(Game*);
        void Draw(Game*);
    };

}

#endif // PAUSESTATE_H
