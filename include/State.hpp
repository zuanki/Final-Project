#pragma once
class State {
public:
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;
    virtual void pause() {};
    virtual void resume() {};
};