#pragma once
#ifndef _Lerp
#define _Lerp

namespace Lerp
{
    static constexpr const float lerp(float time, float startPos, float target){
       return (target - startPos) * time + startPos;
    }

    static constexpr const float smoothStop(float time){
        float x = 1.f - time;
        return 1.f - (x * x);
    }

    static constexpr const float smoothStop2(float time){
        float x = 1.f - time;
        return 1.f - (x * x * x);
    }

    static constexpr const float smoothStop3(float time){
        float x = 1.f - time;
        return 1.f - (x * x * x * x);
    }

    static constexpr const float smoothStart(float time){
        return time * time;
    }

    static constexpr const float smoothStart2(float time){
        return time * time * time;
    }

    static constexpr const float smoothStart3(float time){
        return time * time * time * time; 
    }

    static constexpr const float smoothStep(float time){
        return Lerp::lerp(time, Lerp::smoothStart(time), Lerp::smoothStop(time));
    }

    static constexpr const float smoothStep2(float time){
        return Lerp::lerp(time, Lerp::smoothStart2(time), Lerp::smoothStop2(time));
    }

    static constexpr const float smoothStep3(float time){
        return Lerp::lerp(time, Lerp::smoothStart3(time), Lerp::smoothStop3(time));
    }
} // namespace Lerp


#endif