#pragma once
#ifndef _Random
#define _Ranom

#include <random>

namespace Random{
    static std::random_device rd;
    static std::mt19937 mt(rd());

    static int INTEGER(int min, int max){
        std::uniform_int_distribution<int> dst(min, max);
        return dst(rd);
    }

    static float FLOAT(float min, float max){
        std::uniform_real_distribution<float> dst(min,max);
        return dst(rd);
    }
}

#endif