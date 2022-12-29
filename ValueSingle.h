#pragma once
#ifndef _ValueSingle
#define _ValueSingle

#include "Value.h"

template <class T>
class ValueSingle : public Value<T>{
public:

    ValueSingle(const T& _value):m_value(_value){}
    virtual const T& getValue() const override{ return m_value; }
    virtual const bool shouldReset() const override{ return false; }
    virtual void reset() override{/*Empty implementation*/}
private:
    T m_value;
};

#endif