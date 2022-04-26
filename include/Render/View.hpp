#pragma once
#include <Utility/Vector2.hpp>

class View
{
        friend class RenderWindow;
    public:
        View() = default;
        View(const Vector2i &position, const Vector2i &size);
        Vector2i getPosition() const;
        Vector2i getSize() const;
        void move(int offsetX, int offsetY);
        void move(const Vector2i &offset);
        void setPosition(int x, int y);
        void setPosition(const Vector2i &position);
        void setCenter(int x, int y);
        void setCenter(const Vector2i &center);
        void setSize(int sizeX, int sizeY);
        void setSize(const Vector2i &size);
    private:
        Vector2i position;
        Vector2i size;
};