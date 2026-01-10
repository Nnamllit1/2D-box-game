#ifndef PIXEL_H
#define PIXEL_H

#include <SDL.h>
#include "utils/Vec2.h"

enum class PixelType
{
    Powder,
    Gas,
    Water
};

class Pixel
{
protected:
    PixelType type;
    SDL_Color color;
    Vec2 position;
    Vec2 velocity;

public:
    Pixel(PixelType type, SDL_Color color, int x, int y)
        : type(type), color(color), position(x, y), velocity(0.f, 0.f) {}

    virtual ~Pixel() = default;

    virtual void update(float dt) = 0;
    virtual void render(SDL_Renderer* r) const;

    PixelType getType() const { return type; }
    int getX() const { return position.x; }
    int getY() const { return position.y; }
};

#endif
