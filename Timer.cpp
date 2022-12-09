#include "Timer.h"

Timer::Timer(const float _target){
    m_duration = _target;
    m_elapsed = 0.f;
}

void Timer::update(const float _dt){
    m_elapsed += _dt;
}

const float& Timer::getElapsed() const{
    return m_elapsed;
}

const float Timer::getTime() const{
    return m_elapsed / m_duration;
}

const float& Timer::getDuration() const{
    return m_duration;
}

const bool Timer::isFinished() const{
    return m_elapsed >= m_duration;
}

void Timer::reset(){
    m_elapsed = 0.f;
}

void Timer::reset(float _newTarget){
    m_elapsed = 0.f;
    m_duration = _newTarget;
}