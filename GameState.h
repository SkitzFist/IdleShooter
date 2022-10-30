#pragma once
#ifndef _GameState
#define _GameState

class GameState{
public:
     GameState(){}
     virtual ~GameState(){}
     virtual GameState* handleInput() = 0;
     virtual GameState* update(const float _dt) = 0;
     virtual void render() const = 0;
private:

};

#endif