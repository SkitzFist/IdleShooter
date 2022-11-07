#include "Entity.h"
#include "Log.h"

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
        m_bodies[i]->update(_dt);
    }
}

void Entity::draw() const{
    for(int i = 0; i < m_bodies.size(); ++i){
        m_bodies[i]->draw(getPositon(), 15);
    }
}

void Entity::equip(BodyPart* _body){
    _body->onEquip(this);
    m_bodies.add(_body);
    Log::info("BodyParts equipped: " + std::to_string(m_bodies.size()));
}