#pragma once 

template<class T>
struct Vector2
{
    T x, y;
    Vector2(T x = 0, T y = 0) : x(x), y(y) {}
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;