#include "Game.h"
#include "include/emscripten.h"


Game::Game(){
    emscripten_set_main_loop(mainLoop, 60, 1);
}

Game::~Game(){

}

void mainLoop(){

}

void Game::run(){

}
    