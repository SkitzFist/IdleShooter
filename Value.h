#pragma once
#ifndef _Value
#define _Value

template<class T>
class Value{
public:
    T m_value;
    virtual const T& getValue() const { return m_value; }
};

#endif