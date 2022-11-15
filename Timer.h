#pragma once
#ifndef _Timer
#define _Timer

class Timer{
public:
    Timer(const float _duration = 10.f);
    void update(const float _dt);
    const float& getElapsed() const;
    const float getTime() const;
    const float& getDuration() const;
    const bool& isFinished() const;
    void reset();
    void reset(float _newTarget);
private:
    float m_elapsed;
    float m_duration;
};

#endif