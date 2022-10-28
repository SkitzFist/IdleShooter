#include "include/emscripten.h"
#include "include/raylib.h"

#include <string>

void run();
void destroy();

int main(void){
    emscripten_set_main_loop(run, 60,1);
    destroy();
}

void destroy(){
    std::string str = "Destroy";
    TraceLog(LOG_INFO, str.c_str());
}

void run(){
     std::string str = "LOOP";
    TraceLog(LOG_INFO, str.c_str());
}