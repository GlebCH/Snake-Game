#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "SDL.h"
#include "gamestate.h"
#include "playstate.h"

namespace gameSnake
{
    class menuState : public gameState
    {
    private:
        SDL_Surface* bg;

        menuState();
        ~menuState();

        menuState(const menuState&) = delete;
        menuState& operator = (const menuState&) = delete;
    public:
        static menuState& Instance()
        {
            static menuState ms;
            return ms;
        }

        void Pause();
        void Resume();

        void HandleEvents(Game*);
        void Update(Game*);
        void Draw(Game*);
    };

}

#endif

