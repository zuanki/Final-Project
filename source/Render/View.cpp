#include <Render/View.hpp>

View::View(const Vector2i& position, const Vector2i& size): position(position), size(size)
{

}

Vector2i View::getPosition() const
{
    return this->position;
}

Vector2i View::getSize() const
{
    return this->size;
}

void View::move(int offsetX, int offsetY)
{
    this->position.x += offsetX;
    this->position.y += offsetY;
}

void View::move(const Vector2i& offset)
{
    this->move(offset.x, offset.y);
}

void View::setPosition(int x, int y)
{
    this->position.x = x;
    this->position.y = y;
}

void View::setCenter(int x, int y)
{
    this->position.x = x - this->size.x / 2;
    this->position.y = y - this->size.y / 2;
}

void View::setCenter(const Vector2i& center)
{
    this->setCenter(center.x, center.y);
}

void View::setPosition(const Vector2i& position)
{
    this->setPosition(position.x, position.y);
}

void View::setSize(int sizeX, int sizeY)
{
    this->size.x = sizeX;
    this->size.y = sizeY;
}

void View::setSize(const Vector2i& size)
{
    this->setSize(size.x, size.y);
}