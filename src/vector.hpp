#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

template<typename T> struct vec2 {
    T x;
    T y;

    vec2(){};
    vec2(T val1, T val2) {
        x = val1;
        y = val2;
    }

    vec2<T>(const sf::Vector2f& V)
    {
        x = V.x;
        y = V.y;
    }

    vec2<T>(const sf::Vector2i& V)
    {
        x = V.x;
        y = V.y;
    }
    vec2<T>(const sf::Vector2u& V)
    {
        x = V.x;
        y = V.y;
    }
    void operator = (const sf::Vector2f& V)
    {
        x = V.x;
        y = V.y;
    }

    void operator = (const sf::Vector2i& V)
    {
        x = V.x;
        y = V.y;
    }

    void operator = (const sf::Vector2u& V)
    {
        x = V.x;
        y = V.y;
    }

    template<typename T2>
    vec2<T> operator/ (T2 num) {
        return {x/num, y/num};
    }
    template<typename T2>
    vec2<T> operator* (T2 num) {
        return {x*(T)num, y*(T)num};
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
    vec2<T> operator+ (const vec2<T2>& other) const {
        return vec2<T>{x + (T)other.x, y + (T)other.y};
    }
    template<typename T2>
    vec2<T> operator+= (const vec2<T2>& other) {
        x += (T)other.x;
        y += (T)other.y;
        return *this;
    }
    template<typename T2>
    vec2<T> operator- (const vec2<T2>& other) const {
        return vec2<T>{x - (T)other.x, y - (T)other.y};
    }
    template<typename T2>
    vec2<T> operator-= (const vec2<T2>& other) {
        x -= (T)other.x;
        y -= (T)other.y;
        return *this;
    }

    float lenght() const {
        return sqrt(x*x + y*y);
    }

    vec2<T> normalize() {
        float len = this->lenght();
        if(len == 0)
            return *this;
        x /= len;
        y /= len;
        return *this;
    }

    void rotate(double alpha) {
        T X = x*cos(alpha) - y*sin(alpha);
        T Y = x*sin(alpha) + y*cos(alpha);
        x = X;
        y = Y;
        float epsilon = 1e-13;
        if(x > -epsilon && x < epsilon)
            x = 0;
        if(y > -epsilon && y < epsilon)
            y = 0;
    }

    template<typename T2>
    bool operator== (const vec2<T2>& other) const {
        if(!std::is_same<T, T2>::value)
            return 0;
        if(std::is_same<T, float>::value || std::is_same<T, double>::value) {
            double epsilon = 1e-13;
            T deltaX = x-other.x;
            T deltaY = y-other.y;
            return  -epsilon < deltaX && deltaX < epsilon &&
                    -epsilon < deltaY && deltaY < epsilon;
        }
        else {
            return x == other.x && y == other.y;
        }
    }
    template<typename T2>
    bool operator!= (const vec2<T>& other) const {
        return !(*this == other);
    }

    bool isZero() {
        return *this == vec2<T>{0, 0};
    }

    operator sf::Vector2f() const {return {x, y};}
    operator sf::Vector2i() const {return {x, y};}
    operator sf::Vector2u() const {return {x, y};}
};

using vec2f = vec2<float>;
using vec2i = vec2<float>;
using vec2u = vec2<unsigned>;
