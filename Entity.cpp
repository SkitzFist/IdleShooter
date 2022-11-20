#include "Entity.h"

Entity::Entity()
    :m_bodies(1){
}

Entity::~Entity(){
    for(int i = 0; i < m_bodies.size(); ++i){
        delete m_bodies[i];
    }
    m_bodies.clear();
}

void Entity::update(const float _dt){
    for(int i = 0; i < m_bodies.size(); ++i){
        m_bodies[i]->update(_dt, getPositon());
    }
}

void Entity::draw() const{
    for(int i = 0; i < m_bodies.size(); ++i){
        m_bodies[i]->draw();
    }
}

void Entity::equip(BodyPart* _body){
    _body->onEquip(this);
    m_bodies.add(_body);
}

const float Entity::getRadius() const{
    float biggestRadius = m_boundry.radius;
    for(int i = 0; i < m_bodies.size(); ++i){
        if(m_bodies[i]->getBoundry().radius > biggestRadius){
            biggestRadius = m_bodies[i]->getBoundry().radius;
        }
    }
    return biggestRadius;
}