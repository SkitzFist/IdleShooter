#ifndef _ColorOverTime
#define _ColorOverTime

#include <chrono>
#include "ValueColor.h"

class ValueColorOverTime : public ValueColor{
public:
    ValueColorOverTime(const Color& _startValue, const Color& _endValue, float _duration, const float(*lerpPtr)(float));
    ~ValueColorOverTime();
    const Color& getColor() const override;
    ValueColor* copy() override;
private:
    Color m_startValue;
    Color m_endValue;
    float m_duration;
    const float (*m_lerpPtr)(float);
    std::chrono::steady_clock::time_point m_startTimeStamp;
};

#endif