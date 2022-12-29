#pragma once
#ifndef _ArrayTest
#define _ArrayTest

#include "Array.h"
#include "Log.h"
#include "Random.h"

class ArrayTest{
public:

    static void remove(){
        if(removeInt()){
            Log::info("Remove int Successfull");
        }else{
            Log::info("Remove int unsuccessfull");
        }

        if(removePtr()){
            Log::info("Remove ptr Successfull");
        }else{
            Log::info("Remove ptr unsuccessfull");
        }

        if(removeLast()){
            Log::info("Remove last Successfull");
        }else{
            Log::info("Remove last unsuccessfull");
        }

    }
    static void runAllTests(){
        remove();
    }

private:
//##-REMOVE-##
    static bool removeInt(){
        int size = 100;
        Array<int> array(size);
        for(int i = 0; i < size; ++i){
            array.add(i);
        }
        array.remove(50);
        if(array[50] == 99 && array[size - 1] == NULL){
            return true;
        }

        return false;
    }
    static bool removePtr(){
        float size = 100;
        Array<int*> array(size);
        for(int i = 0; i < size; ++i){
            array.add(new int(i));
        }

        array.remove(50);
        if(*array[50] == 99 && array[99] == nullptr){
            return true;
        }else{
            return false;
        }
    }
    static bool removeLast(){
        int size = 100;
        Array<int> array(size);
        for(int i = 0; i < size; ++i){
            array.add(i);
        }

        array.remove(99);

        if(array[99] == NULL && array.size() == 99){
            return true;
        }else{
            return false;
        }
    }
};

#endif