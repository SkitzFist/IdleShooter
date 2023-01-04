#pragma once
#ifndef _ValueRandom
#define _ValueRandom

#include "Value.h"
#include "Random.h"
//debug

#include "Log.h"
template <class T>
class ValueRandom : public Value<T>{
public:
    ValueRandom(const T& _min, const T& _max):
        m_min(_min), m_max(_max) {
    }
    
    //TODO::could be optimized
    virtual const T& getValue() const override{
        float x = Random::FLOAT(static_cast<float>(m_min), static_cast<float>(m_max));
        return std::move(static_cast<T>(x));
    }

    virtual const bool shouldReset() const override{
        return false;
    }
    virtual void reset() override{
        //Empty implementation
    }

    virtual Value<T>* copy() override{
        return new ValueRandom<T>(m_min, m_max);
    }
    
private:
    float m_min;
    float m_max;
};

#endif