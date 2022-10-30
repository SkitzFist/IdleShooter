#pragma once
#ifndef _PlainSearch
#define _PlainSearch

#include "Array.h"

namespace LinearSearch{
    template <typename T>
    static const bool Find(const Array<T>& _vec, const T& _target){
        for(int i = 0; i < _vec.size(); ++i){
            if(_vec[i] == _target){
                return true;
            }
        }       
        return false;
    };
}
#endif