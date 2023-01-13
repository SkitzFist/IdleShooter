
# IdleShooter

--WORK IN PROGRESS--

## Emscripten 3.1.24  
in order to compile this project, you need to have emscripten version 3.1.24

1. git clone https://github.com/emscripten-core/emsdk.git  
2. cd emsdk  
3. ./emsdk install 3.1.24  
4. ./emsdk activate 3.1.24 
    >***Only with the terminal you will compile with.***   
    >***Run '.\emsdk activate 3.1.24 --permanent' if you want emsdk permanently activated with this version***


##Compiling

When emsdk is activated you can go ahead and compile using the projects own makefile.

when in the projects root folder type 'make'

##Running
The compilation will output three files
* game.html
* game.wasm
* game.js

emscripten provides a simple way to run the html file. Simply type 'emrun game.html'
