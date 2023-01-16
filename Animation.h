#ifndef _Animation
#define _Animation

#include "Vec2.h"

class Animation{
public:
    virtual ~Animation(){}
    virtual void update(const float& _dt) = 0;
    virtual void render() const = 0;
};

#endif