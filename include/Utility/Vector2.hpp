#pragma once

template <class T>
struct Vector2
{
    T x, y;
    Vector2(T x = 0, T y = 0) : x(x), y(y) {}
    Vector2 operator*(float k)
    {
        return Vector2(x * k, y * k);
    }
    Vector2 operator-() const
    {
        return Vector2(-this->x, -this->y);
    }

    Vector2 &operator+=(const Vector2 &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vector2 &operator-=(const Vector2 &other)
    {
        *this += -other;
        return *this;
    }

    Vector2 &operator*=(float k)
    {
        this->x *= k;
        this->y *= k;

        return *this;
    }

    Vector2 &operator/=(float k)
    {
        this->x *= 1.f / k;
        return *this;
    }

    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    Vector2 operator-(const Vector2 &other) const
    {
        return *this + (-other);
    }

    Vector2 operator*(float k) const
    {
        return Vector2(this->x * k, this->y * k);
    }

    Vector2 operator/=(float k) const
    {
        return (*this) * (1.f / k);
    }
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;