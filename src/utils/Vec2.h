#ifndef VEC2_H
#define VEC2_H

struct Vec2
{
    float x;
    float y;

    Vec2() : x(0.f), y(0.f) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}

    Vec2 operator+(const Vec2& rhs) const
    {
        return { x + rhs.x, y + rhs.y };
    }

    Vec2 operator*(float s) const
    {
        return { x * s, y * s };
    }

    Vec2& operator+=(const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};

#endif // VEC2_H