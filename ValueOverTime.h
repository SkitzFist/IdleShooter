#pragma once
#ifndef _ValueOverTime
#define _ValueOverTime

#include "Value.h"
#include "Lerp.h"
#include <chrono>

template <class T>
class ValueOverTime : public Value<T>{
public:
    float m_duration;
    T m_startValue;
    T m_endValue;
    std::chrono::steady_clock::time_point m_startPoint;
    
    ValueOverTime(const T& _startValue, const T& _endValue, const float _durationInMS){
        m_startPoint = std::chrono::steady_clock::now();
        m_startValue = _startValue;
        m_endValue = _endValue;
        m_duration = _durationInMS;
    }

    virtual const T& getValue() const override{
        std::chrono::steady_clock::time_point endPoint = std::chrono::steady_clock::now();
        float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - m_startPoint).count();
        if(elapsed >= m_duration){
            return m_endValue;
        }else{
            float time = elapsed / m_duration;
            return std::move(static_cast<T>(Lerp::lerp(time, m_startValue, m_endValue)));   
        }
    }
};

#endif