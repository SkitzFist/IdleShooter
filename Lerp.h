#pragma once
#ifndef _Lerp
#define _Lerp

namespace Lerp
{
    static constexpr const float smoothStart(float t){
        return t * t;
    }

    static constexpr const float smoothStart2(float t){
        return t * t *t;
    }

    static constexpr const float test(float t){
        return smoothStart(t) * -1;
    }
} // namespace Lerp


#endif