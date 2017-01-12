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
        static menuState _menuState;

        SDL_Surface* bg;
        menuState();
    public:
        ~menuState();

        void Pause();
        void Resume();

        void HandleEvents(Game*);
        void Update(Game*);
        void Draw(Game*);

        static menuState& Instance() { return _menuState; }
    };

}

#endif

