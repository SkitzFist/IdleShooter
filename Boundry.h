#pragma once
#ifndef _Boundry
#define _Boundry

#include "Array.h"

enum Shape{
    circle,
    square,
    undefined
};

struct Boundry
{
    Shape shape;
    float angle;
    float radius;
    Array<float> points;

    Boundry():shape(Shape::undefined), angle(0.f), radius(0.f), points(0){}
};

#endif