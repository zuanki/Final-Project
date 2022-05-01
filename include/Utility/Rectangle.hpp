#pragma once
#include <cmath>

struct Vector2f
{
    Vector2f(float x, float y) : x(x), y(y) {}

    Vector2f() : Vector2f(0.f, 0.f) {}

    Vector2f operator-() const
    {
        return Vector2f(-this->x, -this->y);
    }

    Vector2f &operator+=(const Vector2f &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vector2f &operator-=(const Vector2f &other)
    {
        *this += -other;
        return *this;
    }

    Vector2f &operator*=(float k)
    {
        this->x *= k;
        this->y *= k;

        return *this;
    }

    Vector2f &operator/=(float k)
    {
        this->x *= 1.f / k;
        return *this;
    }

    Vector2f operator+(const Vector2f &other) const
    {
        return Vector2f(this->x + other.x, this->y + other.y);
    }

    Vector2f operator-(const Vector2f &other) const
    {
        return *this + (-other);
    }

    Vector2f operator*(float k) const
    {
        return Vector2f(this->x * k, this->y * k);
    }

    Vector2f operator/=(float k) const
    {
        return (*this) * (1.f / k);
    }

    float x, y;
};

class Rectangle
{
public:
    Rectangle(const Vector2f &center, const Vector2f &halfSize) : center(center), halfSize(halfSize) {}

    bool isCollide(const Rectangle &other)
    {
        Vector2f dis = this->center - other.center;
        Vector2f sumHalfSize = this->halfSize + other.halfSize;

        Vector2f overlap;
        overlap.x = sumHalfSize.x - std::abs(dis.x);
        overlap.y = sumHalfSize.y - std::abs(dis.y);

        return overlap.x > 0.f && overlap.y > 0.f;
    }

    // Tìm vector để di chuyển Rectangle này sao cho không còn va chạm với other
    Vector2f getResolveVector(const Rectangle &other)
    {
        Vector2f dis = this->center - other.center;
        Vector2f sumHalfSize = this->halfSize + other.halfSize;

        Vector2f overlap;
        overlap.x = sumHalfSize.x - std::abs(dis.x);
        overlap.y = sumHalfSize.y - std::abs(dis.y);

        Vector2f resolve;
        if (overlap.x < overlap.y)
        {
            resolve.x = (dis.x > 0.f ? overlap.x : -overlap.x);
        }
        else
        {
            resolve.y = (dis.y > 0.f ? overlap.y : -overlap.y);
        }

        return resolve;
    }

public:
    Vector2f center;
    Vector2f halfSize;
};