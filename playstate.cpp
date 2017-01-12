#include "playstate.h"
#include "gamestate.h"
#include "menustate.h"
#include "game.h"

using namespace gameSnake;

playState playState::_playState;


playState::playState()
{
    M_HEIGHT = map.getHeight(), M_WIDTH = map.getWidth();

    snake.addFood();
}

playState::~playState() {}

void playState::Pause()
{
    printf("CPlayState Pause\n");
}

void playState::Resume()
{
    printf("CPlayState Resume\n");
}

void playState::HandleEvents(Game* game)
{
    SDL_Event event;

    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT) game->Quit();
    else if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                if(dir != DOWN) dir = UP;
                break;
            case SDLK_DOWN:
                if(dir != UP) dir = DOWN;
                break;
            case SDLK_LEFT:
                if(dir != RIGHT) dir = LEFT;
                break;
            case SDLK_RIGHT:
                if(dir != LEFT) dir = RIGHT;
                break;
            default:
                break;
        }
    }
}

void playState::Update(Game* game)
{
    unsigned x = snake.getX();
    unsigned y = snake.getY();

    switch(dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    }

    switch(map.getCellType(x, y))
    {
            case EMPTY:
                snake.next(x,y);
                break;
            case FOOD:
                snake.goUp(x,y);
                break;
            case WALL:
                //game->Quit();
                break;
            case SNAKE:
                //game->Quit();
                break;
            default:
                break;
    }
}

void playState::Draw(Game* game)
{
    snake.toMap();

    SDL_Rect cells[M_HEIGHT][M_WIDTH];
    for(unsigned i = 0;i < M_HEIGHT;++i)
    {
        for(unsigned j = 0;j < M_WIDTH;++j)
        {
            cells[i][j] = {i * 20, j * 20, 20, 20};
        }
    }

    for(unsigned i = 0;i < M_HEIGHT;++i)
    {
        for(unsigned j = 0;j < M_WIDTH;++j)
        {
            switch(map.getCellType(i,j))
            {
            case EMPTY:
                SDL_SetRenderDrawColor(game->render, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderFillRect(game->render, &cells[i][j]);
                break;
            case FOOD:
                SDL_SetRenderDrawColor(game->render, 0xFF, 0x00, 0x00, 0xFF );
                SDL_RenderFillRect(game->render, &cells[i][j]);
                break;
            case WALL:
                SDL_SetRenderDrawColor(game->render, 0x00, 0x66, 0xFF, 0xFF );
                SDL_RenderFillRect(game->render, &cells[i][j]);
                break;
            case SNAKE:
                SDL_SetRenderDrawColor(game->render, 0xA1, 0x60, 0x00, 0xFF );
                SDL_RenderFillRect(game->render, &cells[i][j]);
                break;

            }
        }
    }
    SDL_RenderPresent(game->render);
}

