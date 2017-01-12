#ifndef MAP_H
#define MAP_H

#include "pch.h"
#include "cell.h"

typedef unsigned short ushort;

namespace gameSnake
{
    class Map
    {
    private:
        const unsigned WIDTH = 30, HEIGHT = 30;
        std::vector<Cell> field;

        Map();
        Map(const Map&);
        Map& operator = (const Map&);
    public:
        static Map& Instance(void);

        unsigned getWidth() const { return WIDTH; }
        unsigned getHeight() const { return HEIGHT; }

        typeOfCell getCellType(unsigned, unsigned);
        void setCellType(unsigned, unsigned, typeOfCell);

        Cell& getCell(unsigned, unsigned);

    };
}

#endif // MAP_H
