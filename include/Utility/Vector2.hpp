#pragma once 

template<class T>
struct Vector2
{
    T x, y;
    Vector2(T x = 0, T y = 0) : x(x), y(y) {}
    Vector2 operator*(int k){
        return Vector2(x*k, y*k);
    }
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;