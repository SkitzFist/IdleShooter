#pragma once
#include "Event.h"
#include "Object.h"

template <class T>
class EventHandler : public Object{
public:
    virtual void onEvent(const T& event) = 0;
    virtual ~EventHandler(){}
};