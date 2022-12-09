#include "MoveSideways.h"
#include "Settings.h"
#include "Entity.h"
#include "Utility.h"
#include "Lerp.h"

MoveSideways::MoveSideways() : 
    m_timer(8.f){
}

void MoveSideways::onSetMovement(Entity* _entity){
    m_target = 0.f + _entity->getLargestRadius();
    m_next = Settings::WORLD_SIZE.x - _entity->getLargestRadius();
    p_entity = _entity;
}

void MoveSideways::update(const float _dt){
    m_timer.update(_dt);

    if(m_timer.isFinished()){
        Utility::swap(m_target, m_next);
        m_timer.reset();
    }else{
        float time = Lerp::smoothStep2(m_timer.getTime());
        float xPos = Lerp::lerp(time, m_next, m_target);
        p_entity->setPosition({
            xPos, p_entity->getPositon().y
        });        
    }
}