#include "ValueColorOverTime.h"

#include <utility>

#include "Lerp.h"

ValueColorOverTime::ValueColorOverTime(const Color& _startValue, 
const Color& _endValue, float _duration, const float(*lerpPtr)(float)):
    m_startValue(_startValue), m_endValue(_endValue), m_duration(_duration),
    m_lerpPtr(lerpPtr){
    m_startTimeStamp = std::chrono::steady_clock::now();
}

ValueColorOverTime::~ValueColorOverTime(){

}

const Color& ValueColorOverTime::getColor() const{
    std::chrono::steady_clock::time_point currentTimeStampa = std::chrono::steady_clock::now();
    float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTimeStampa - m_startTimeStamp
    ).count();

    if(elapsed >= m_duration){
        return m_endValue;
    }else{
        float time = m_lerpPtr(elapsed / m_duration);
        unsigned char r = Lerp::lerp(time, m_startValue.r, m_endValue.r);
        unsigned char g = Lerp::lerp(time, m_startValue.g, m_endValue.g);
        unsigned char b = Lerp::lerp(time, m_startValue.b, m_endValue.b);
        unsigned char a = Lerp::lerp(time, m_startValue.a, m_endValue.a);

        return std::move(Color{r,g,b,a});
    }

}

ValueColor* ValueColorOverTime::copy(){
    return new ValueColorOverTime(m_startValue, m_endValue, m_duration, m_lerpPtr);
}