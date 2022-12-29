#pragma once
#ifndef _Value
#define _Value

/*
    Needs a copy constructor,
    Not sure if needed in children or just mother class.

    RandomValue, ColorValue, Vec2<T> value
*/

template<class T>
class Value{
public:
    virtual ~Value(){};
    virtual const T& getValue() const = 0;
    virtual const bool shouldReset() const = 0;
    virtual void reset() = 0;
};

#endif