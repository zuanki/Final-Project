#pragma once
#include <Render/Sprite.hpp>
class Animation
{
private:
    float totalTime;
    float frameDuration;
    int curFrame;
    int frameCount;
    SDL_Rect frameRect;

public:
    Animation(int sheetSpriteX, int sheetSpriteY, int frameCount, float frameDuration);
    void update(float deltaTime);
    void applyToSprite(Sprite &sprite) const;
    void setFrameRect(int x, int y)
    {
        this->frameRect.x = x;
        this->frameRect.y = y;
    }
};