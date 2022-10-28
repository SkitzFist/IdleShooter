#pragma once
#include <utility>

#include "include/raylib.h"

template <class T>
class Vec2{
public:
    Vec2() = default;
    constexpr Vec2(T _x, T _y) :  x(_x), y(_y) {}

    T x;
    T y;

    inline constexpr const float length(){return (sqrt((x * x) + (y * y)));}
    inline constexpr const Vec2<float>& normalize(){
        float length = (sqrt((x * x) + (y * y)));
        Vec2<float>normalized(x / length, y / length);
        return std::move(normalized);
    }

    inline constexpr const Vec2 operator+(const Vec2& rhs)const{ return {x + rhs.x, y + rhs.y}; }
    inline constexpr const Vec2& operator+=(const Vec2& rhs){ return *this = *this + rhs;}
    inline constexpr const Vec2 operator+(const int& rhs)const{return{x + rhs, y + rhs};}
    inline constexpr const Vec2& operator+=(const int& rhs) {return *this = *this + rhs;}
    inline constexpr const Vec2 operator+(const float& rhs)const{return{x + rhs, y + rhs};}
    inline constexpr const Vec2& operator+=(const float& rhs) {return *this = *this + rhs;}

    inline constexpr const Vec2 operator-(const Vec2& rhs)const{ return {x - rhs.x, y - rhs.y}; }
    inline constexpr const Vec2& operator-=(const Vec2& rhs){ return *this = *this - rhs;}
    inline constexpr const Vec2 operator-(const int& rhs)const{return{x - rhs, y - rhs};}
    inline constexpr const Vec2& operator-=(const int& rhs) {return *this = *this - rhs;}
    inline constexpr const Vec2 operator-(const float& rhs)const{return{x - rhs, y - rhs};}
    inline constexpr const Vec2& operator-=(const float& rhs) {return *this = *this - rhs;}

    inline constexpr const Vec2 operator*(const Vec2& rhs)const{ return {x * rhs.x, y * rhs.y}; }
    inline constexpr const Vec2& operator*=(const Vec2& rhs){ return *this = *this * rhs;}
    inline constexpr const Vec2 operator*(const int& rhs)const{return{x * rhs, y * rhs};}
    inline constexpr const Vec2& operator*=(const int& rhs) {return *this = *this * rhs;}
    inline constexpr const Vec2 operator*(const float& rhs)const{return{x * rhs, y * rhs};}
    inline constexpr const Vec2& operator*=(const float& rhs) {return *this = *this * rhs;}

    inline constexpr const Vec2 operator/(const Vec2& rhs)const{ return {x / rhs.x, y / rhs.y}; }
    inline constexpr const Vec2& operator/=(const Vec2& rhs){ return *this = *this / rhs;}
    inline constexpr const Vec2 operator/(const int& rhs)const{return{x / rhs, y / rhs};}
    inline constexpr const Vec2& operator/=(const int& rhs) {return *this = *this / rhs;}
    inline constexpr const Vec2 operator/(const float& rhs)const{return{x / rhs, y / rhs};}
    inline constexpr const Vec2& operator/=(const float& rhs) {return *this = *this / rhs;}

    inline constexpr bool operator==(const Vec2& rhs) const {return x == rhs.x && y == rhs.y;}
    inline constexpr bool operator!=(const Vec2& rhs) const {return !(*this == rhs);}

private:

};