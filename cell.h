#ifndef CELL_H
#define CELL_H

#include "pch.h"

typedef unsigned short ushort;

namespace gameSnake
{
    class Cell
    {
    private:
        ushort px, py;
        typeOfCell type;
        Cell();
    public:
        Cell(unsigned x, unsigned y, typeOfCell type) : px(x), py(y), type(type) {}

        unsigned getX() const { return px; }
        unsigned getY() const { return py;}

        typeOfCell getType() const { return type; }
        void setType(typeOfCell type) { Cell::type = type; }
    };
}

#endif // CELL_H
