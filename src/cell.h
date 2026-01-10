#ifndef CELL_H
#define CELL_H

#include <memory>
#include "pixel.h"

class Cell
{
private:
    std::unique_ptr<Pixel> pixel;  // nullptr == leer

public:
    Cell() = default;

    bool isEmpty() const
    {
        return pixel == nullptr;
    }

    Pixel* getPixel() const
    {
        return pixel.get();
    }

    void setPixel(std::unique_ptr<Pixel> p)
    {
        pixel = std::move(p);
    }

    std::unique_ptr<Pixel> takePixel()
    {
        return std::move(pixel);
    }

    void clear()
    {
        pixel.reset();
    }
};

#endif
