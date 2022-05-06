#pragma once
class State
{
public:
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
    virtual void pause(){};
    virtual void resume(){};
};