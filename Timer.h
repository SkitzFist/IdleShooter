#pragma once
#ifndef _Timer
#define _Timer

class Timer{
public:
    Timer(const float _target = 10.f);
    void update(const float _dt);
    const float getAcumulated() const;
    const bool isFinished() const;
    void reset();
    void reset(float _newTarget);
private:
    float m_acumulated;
    float m_target;
};

#endif