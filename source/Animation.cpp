#include <Animation.hpp>
#include <cmath>

Animation::Animation(int sheetSpriteX, int sheetSpriteY, int frameCount, float frameDuration) {
    this->totalTime = 0.f;
    this->frameDuration = frameDuration;
    this->curFrame = 0;
    this->frameCount = frameCount;
    this->frameRect.w = sheetSpriteX/ this->frameCount;
    this->frameRect.h = sheetSpriteY/4;
    this->frameRect.x = 0;
    this->frameRect.y = 0;

}

void Animation::update() {
    this->totalTime += 1.f/60.f;

    if (this->totalTime > this->frameDuration) {
        this->curFrame += this->totalTime / this->frameDuration;
        if (this->curFrame >= this->frameCount) {
            this->curFrame %= this->frameCount;
        }
        this->frameRect.x = this->curFrame * this->frameRect.w;
        
        this->totalTime = fmod(this->totalTime, this->frameDuration);
    }
}

void Animation::applyToSprite(Sprite& sprite) const {
    sprite.setTextureRect(this->frameRect);
}