#include "Timer.h"

Timer::Timer(const float _target){
    m_target = _target;
    m_acumulated = 0.f;
}

void Timer::update(const float _dt){
    m_acumulated += _dt;
}

const float Timer::getAcumulated() const{
    return m_acumulated;
}

const bool Timer::isFinished() const{
    return m_acumulated >= m_target;
}

void Timer::reset(){
    m_acumulated = 0.f;
}

void Timer::reset(float _newTarget){
    m_acumulated = 0.f;
    m_target = _newTarget;
}