#pragma once
#ifndef _Utility
#define _Utility

namespace Utility
{
    static void swap(float& a, float& b){
        float tmp = a;
        a = b;
        b = tmp;
    }
} // namespace Utility


#endif