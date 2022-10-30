#pragma once
#ifndef _BinarySearch
#define _BinarySearch

#include "Array.h"

namespace BinarySearch{
    template <typename T>
    static int binarySearch(const Array<T>& _vec, int left, int right, const T& _target){
        int mid = (left + (right-1)) / 2;
        if(left <= right ){
            if(_vec[mid] == _target){
                return mid;
            }

            if(_target < _vec[mid]){
                return binarySearch(_vec, left, mid-1, _target);
            }

            if(_target > _vec[mid]){
                return binarySearch(_vec, mid+1, right, _target);
            }   
        }
        return -1;
    };

    template <typename T>
    static const bool Find(const Array<T>& _vec, const T& _target){
        int _targetIndex = binarySearch(_vec, 0, _vec.size() -1, _target);
        if(_targetIndex == -1){
            return false;
        }
        return true;
    };
}
#endif