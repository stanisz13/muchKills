#pragma once
#include <math.h>

template<typename T> struct vector2 {
    T x;
    T y;

    vector2();
    vector2(T val1, T val2) {
        x = val1;
        y = val2;
    }

    template<typename T2> void operator+= (T2 num) {
        x += num;
        y += num;
    }
    template<typename T2> void operator-= (T2 num) {
        x -= num;
        y -= num;
    }
    template<typename T2> void operator*= (T2 num) {
        x *= num;
        y *= num;
    }
    template<typename T2> void operator/= (T2 num) {
        if(num == 0)
            return;
        x /= num;
        y /= num;
    }

    template<typename T2>
    vector2<T> operator+ (const vector2<T2>& other) const {
        T X = x + (T)other.x;
        T Y = y + (T)other.y;
        return vector2<T>{X, Y};
    }
    template<typename T2>
    vector2<T> operator+= (const vector2<T2>& other) {
        x += (T)other.x;
        y += (T)other.y;
    }
    template<typename T2>
    vector2<T> operator- (const vector2<T2>& other) const {
        T X = x - (T)other.x;
        T Y = y - (T)other.y;
        return vector2<T>{X, Y};
    }
    template<typename T2>
    vector2<T> operator-= (const vector2<T2>& other) {
        x -= (T)other.x;
        y -= (T)other.y;
    }

    float lenght() const {
        return sqrt(x*x + y*y);
    }
    vector2<T> normalize() {
        float len = this->lenght();
        if(len == 0)
            return;
        x /= len;
        y /= len;
        return *this;
    }
};
