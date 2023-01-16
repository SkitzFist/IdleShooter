#ifndef _ValueColor
#define _ValueColor

#include "include/raylib.h"

class ValueColor{
public:
    virtual ~ValueColor(){}
    virtual const Color& getColor() const = 0;
    virtual ValueColor* copy() = 0;
};

#endif