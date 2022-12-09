#pragma once
#ifndef _ColorStruct
#define _ColorStruct

#include "include/raylib.h"

struct ColorStruct
{
    unsigned char r,g,b,a;
    ColorStruct(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a){
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    };

    ColorStruct(const Color& _color){
        r = _color.r;
        g = _color.g;
        b = _color.b;
        a = _color.a;
    }

    /*Color 0-3 r,g,b,a*/
    void addColor(int color, char amount){
        switch (color)
        {
        case 0:
            r += amount;
            break;
        case 1:
            g += amount;
            break;
        case 2:
            b += amount;
            break;
        case 3:
            a += amount;
            break;
        default:
            break;
        }
    }

    unsigned char getColor(int color){
        switch (color)
        {
        case 0:
            return r;
        case 1:
            return g;
        case 2:
            return b;
        case 3:
            return a;
        default:
            return 0;
            break;
        }
    }

    const Color toColor() const{
        return Color{r,g,b,a};
    }
};


#endif