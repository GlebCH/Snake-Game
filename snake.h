#ifndef SNAKE_H
#define SNAKE_H

#include "pch.h"
#include "map.h"
#include "cell.h"
#include "SDL.h"

namespace gameSnake
{
    class Snake//не синглтон
    {
    private:
        const unsigned size;
        std::list<Cell> snake;
        Map& map = Map::Instance();
    public:
        Snake();

        void addFood();
        unsigned getX() { return snake.back().getX(); }
        unsigned getY() { return snake.back().getY(); }

        void toMap();
        void next(unsigned, unsigned);//идем дальше
        void goUp(unsigned, unsigned);//увеличиваемся
    };
}

#endif // SNAKE_H
