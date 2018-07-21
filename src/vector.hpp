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
        T X = x + (T)other.x;
        T Y = y + (T)other.y;
        return vec2<T>{X, Y};
    }
    template<typename T2>
    vec2<T> operator+= (const vec2<T2>& other) {
        x += (T)other.x;
        y += (T)other.y;

        return *this;
    }
    template<typename T2>
    vec2<T> operator- (const vec2<T2>& other) const {
        T X = x - (T)other.x;
        T Y = y - (T)other.y;
        return vec2<T>{X, Y};
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

    operator sf::Vector2f() const {return {x, y};}
    operator sf::Vector2i() const {return {x, y};}
    operator sf::Vector2u() const {return {x, y};}
};


using vec2f = vec2<float>;
using vec2i = vec2<float>;
using vec2u = vec2<unsigned>;
