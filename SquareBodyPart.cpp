#include "SquareBodyPart.h"
#include "Utility.h"
#include "Lerp.h"
#include "Entity.h"

SquareBodyPart::SquareBodyPart() :
    m_timer(1.f), m_angleStart(45.f), m_angleTarget((360.f - m_angleStart) * 3.f), m_sizeFactor(0.f),
    m_sizeStart(2.f), m_sizeTarget(4.f), m_baseRadius(10.f), m_entity(nullptr){
}

SquareBodyPart::~SquareBodyPart(){
}

void SquareBodyPart::update(const float _dt){
    m_timer.update(_dt);
    if(m_timer.isFinished()){
        m_timer.reset();
        Utility::swap(m_sizeStart, m_sizeTarget);
        Utility::swap(m_angleStart, m_angleTarget);
    }else{
        float sizeTime = Lerp::smoothStep2(m_timer.getTime());
        m_sizeFactor = Lerp::lerp(sizeTime, m_sizeStart, m_sizeTarget);
        float angleTime = Lerp::smoothStep(m_timer.getTime()) / 2.f;
        m_boundry.angle = Lerp::lerp(angleTime, m_angleStart, m_angleTarget);
    }

    rec = {
        m_entity->getPositon().x,
        m_entity->getPositon().y,
        m_baseRadius * m_sizeFactor,
        m_baseRadius * m_sizeFactor 
    };
}

void SquareBodyPart::onEquip(Entity* _entity){
    m_entity = _entity;
}

void SquareBodyPart::onCollision(GameObject* _other){
    
}

void SquareBodyPart::draw()const{
    DrawRectanglePro(rec, Vector2{rec.width / 2.f, rec.height / 2.f}, m_boundry.angle, GREEN);
    DrawRectanglePro(rec, Vector2{rec.width / 2.f, rec.height / 2.f}, (-m_boundry.angle - 45.f), GREEN); 
}