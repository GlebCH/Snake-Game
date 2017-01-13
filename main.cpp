#include "pch.h"
#include "game.h"

#include "menustate.h"

using namespace std;
using namespace gameSnake;

int main ()
{
    Game game;

    game.changeState(menuState::Instance());

    // main loop
    while (game.Running())
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    return 0;
}
