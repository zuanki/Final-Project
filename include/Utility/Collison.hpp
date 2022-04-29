#pragma once
#include <SDL.h>
class Collision
{
public:
    static bool checkCollision(SDL_Rect a, SDL_Rect b)
    {
        bool xCollision = (a.x < b.x + b.w) && (a.x + a.w > b.x);
        bool yCollision = (a.y < b.y + b.h) && (a.y + a.h > b.y);

        return xCollision && yCollision;
    }
};