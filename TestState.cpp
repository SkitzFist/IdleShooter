#include "TestState.h"
#include "SquareBodyPart.h"
#include "Log.h"

TestState::TestState(){
    player = new Player({200,100});
}

TestState::~TestState(){
    delete player;
}

GameState* TestState::handleInput(){
    GameState* state = this;
    if(IsKeyReleased(KEY_ESCAPE)){
        Log::info("Esc is released");
        delete this;
        return nullptr;
    }

    if(IsKeyPressed(KEY_SPACE)){
        player->equip(new SquareBodyPart());
    }
    return state;
}

GameState* TestState::update(const float _dt){
    GameState* state = this;
    player->update(_dt);
    return state;
}

void TestState::render()const{
    player->draw();
}