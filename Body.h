#pragma once
#ifndef _Body
#define _Body

#include "Vec2.h"

class Entity;

class Body{
public:
    virtual void onEquip(Entity* entity) = 0;
    virtual void draw(const Vec2<float>& _pos, int _radius) const = 0;
private:
};

#endif