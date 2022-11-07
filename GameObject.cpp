#include "GameObject.h"

void GameObject::setPosition(const Vec2<float>& _newPosition){
    m_position = _newPosition;
}

const Vec2<float>& GameObject::getPositon() const{
    return m_position;
}