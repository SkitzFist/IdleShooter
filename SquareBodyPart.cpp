#include "SquareBodyPart.h"

//debug
#include "Log.h"
#include "Timer.h"
#include "Lerp.h"

SquareBodyPart::SquareBodyPart() :
    m_angle(0){

}

SquareBodyPart::~SquareBodyPart(){
}

float lerpAngle(float a, float b, const float _dt){
    return (a + ((b-a) * _dt));
}

float lerpAngleGoal(float targetValue, float duration, float elapsedTime){
    return (targetValue * (elapsedTime / duration));
}

void SquareBodyPart::update(const float _dt){
    static Timer timer;
    timer.update(_dt);
    m_angle = lerpAngle(0.f, 360.f, timer.getAcumulated());
}

void SquareBodyPart::onEquip(Entity* _entity){
    
}

void SquareBodyPart::draw(const Vec2<float>& _pos, int _radius)const{
    Vec2<float> origin = {
        _pos.x,
        _pos.y
    };

    Vec2<float> size = {
        _radius * 4.f,
        _radius * 4.f
    };

    Rectangle rec = {
        static_cast<float>(_pos.x),
        static_cast<float>(_pos.y),
        static_cast<float>(size.x),
        static_cast<float>(size.y)
    };

    DrawRectanglePro(rec, Vector2{rec.width / 2, rec.height / 2}, m_angle, GREEN);
    DrawRectanglePro(rec, Vector2{rec.width / 2, rec.height / 2}, -m_angle, GREEN);
    
}