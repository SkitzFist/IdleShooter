#pragma once
#ifndef _Value2
#define _Value2

#include "Value.h"
#include "Vec2.h"

template <class T>
class Value2<T>{
public:
    Value<T>* x;
    Value<T>* y;

    Value2(Value<T>* _x, Value<T>* _y){
        m_x = _x->copy();
        m_y = _y->copy();
    }

    ~Value2(){
        if(x){
            delete m_x;
        }

        if(y){
            delete m_y;
        }
    }

    const Vec2<T>& getValue() const{
        return std::move(Vec2<T>(x->getValue(), y->getValue()));
    }

private:

}; 

#endif