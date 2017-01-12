#include "map.h"

using namespace gameSnake;

Map::Map()
{
    for(unsigned i = 0;i < WIDTH;++i)
    {
        field.push_back(Cell(i, 0, WALL));
        field.push_back(Cell(i, HEIGHT - 1, WALL));
    }
    for(unsigned j = 1;j < HEIGHT - 1;++j)
    {
        field.push_back(Cell(0, j, WALL));
        field.push_back(Cell(WIDTH - 1, j, WALL));
    }
    for(unsigned i = 1; i < WIDTH - 1;++i)
    {
        for(unsigned j = 1;j < HEIGHT - 1;++j) field.push_back(Cell(i, j, EMPTY));
    }
}

Map& Map::Instance()
{
    static Map map;
    return map;
}

typeOfCell Map::getCellType(unsigned x, unsigned y)
{
    for (Cell& i: field)
    {
        if(i.getX() == x && i.getY() == y)
        {
            return i.getType();
        }
    }
    return OUT;
}

void Map::setCellType(unsigned x, unsigned y, typeOfCell type)
{
    for (Cell& i: field)
    {
        if(i.getX() == x && i.getY() == y)
        {
            i.setType(type);
            break;
        }
    }
}

Cell& Map::getCell(unsigned x, unsigned y)
{
    for (Cell& i: field)
    {
        if(i.getX() == x && i.getY() == y) return i;
    }
    //need return
}
