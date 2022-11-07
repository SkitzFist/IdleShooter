#include "Entity.h"
#include "Log.h"

Entity::Entity()
    :m_bodies(1){

}

Entity::~Entity(){
    m_bodies.clear();
}

void Entity::draw() const{
    for(int i = 0; i < m_bodies.size(); ++i){
        m_bodies[i]->draw(getPositon(), 15);
    }
}

void Entity::equip(Body* _body){
    _body->onEquip(this);
    m_bodies.add(_body);
}