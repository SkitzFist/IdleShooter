#pragma once
#ifndef _Value2
#define _Value2

#include "Value.h"
#include "Vec2.h"

template <class T>
class Value2{
public:
    Value2(Value<T>* _x, Value<T>* _y){
        m_x = _x->copy();
        m_y = _y->copy();
    }

    ~Value2(){
        if(m_x){
            delete m_x;
        }

        if(m_y){
            delete m_y;
        }
    }
    
    const Vec2<T>& getValue() const{
        return std::move(Vec2<T>(m_x->getValue(), m_y->getValue()));
    }

    void reset(){
        m_x->reset();
        m_y->reset();
    }

    void shouldReset(){
        if(m_x->shouldReset()){
            m_x->reset();
        }
        if(m_y->shouldReset()){
            m_y->reset();
        }
    }

private:
    Value<T>* m_x;
    Value<T>* m_y;
}; 

#endif