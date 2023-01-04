#include "Entity.h"

Entity::Entity()
    :m_bodies(1), m_movement(nullptr){
}

Entity::~Entity(){
    delete m_movement;
    for(int i = 0; i < m_bodies.size(); ++i){
        delete m_bodies[i];
    }
    m_bodies.clear();
}

void Entity::update(const float _dt){

    if(m_movement){
        m_movement->update(_dt);
    }

    for(int i = 0; i < m_bodies.size(); ++i){
        m_bodies[i]->update(_dt);
    }
}

void Entity::render() const{
    for(int i = 0; i < m_bodies.size(); ++i){
        m_bodies[i]->render();
    }
}

void Entity::equip(BodyPart* _body){
    _body->onEquip(this);
    m_bodies.add(_body);
}

void Entity::setMovementBehaviour(AiMovement* _movement){
    if(m_movement){
        delete m_movement;
    }
    m_movement = _movement;
    m_movement->onSetMovement(this);
}

const float Entity::getLargestRadius() const{
    float biggestRadius = m_boundry.radius; 
    for(int i = 0; i < m_bodies.size(); ++i){
        if(m_bodies[i]->getBoundry().radius > biggestRadius){
            biggestRadius = m_bodies[i]->getBoundry().radius;
        }
    }
    return biggestRadius;
}