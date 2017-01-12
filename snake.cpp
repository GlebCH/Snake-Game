#include "snake.h"

using namespace gameSnake;

Snake::Snake() : size(3)
{
    srand(time(NULL));
    for(unsigned i = 0; i < size; ++i) snake.push_back(Cell(i + 1, 1, SNAKE));
}

void Snake::addFood()
{
    unsigned x, y;
    bool isFree;

    do
    {
        isFree = 1;
        x = rand() % (map.getWidth() - 4) + 2;
        y = rand() % (map.getHeight() - 4) + 2;

        for(Cell& i: snake)
        {
            if(i.getX() == x && i.getY() == y)
            {
                isFree = 0;
                break;
            }
        }
    } while(!isFree);

    map.setCellType(x, y, FOOD);
}

void Snake::toMap()
{
    for (Cell& i: snake) map.setCellType(i.getX(), i.getY(), SNAKE);
}

void Snake::next(unsigned x, unsigned y)
{
    Cell& cell = map.getCell(x,y);
    cell.setType(SNAKE);

    snake.push_back(cell);
    map.setCellType(snake.front().getX(), snake.front().getY(), EMPTY);
    snake.pop_front();

    SDL_Delay(100);
}

void Snake::goUp(unsigned x, unsigned y)
{
    Cell& cell = map.getCell(x,y);
    cell.setType(SNAKE);

    snake.push_back(cell);

    addFood();

    SDL_Delay(100);
}
