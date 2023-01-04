#pragma once
#ifndef _Value
#define _Value

template<class T>
class Value{
public:
    virtual ~Value(){};
    virtual const T& getValue() const = 0;
    virtual const bool shouldReset() const = 0;
    virtual void reset() = 0;
    virtual Value<T>* copy() = 0;
};

#endif