#pragma once
#ifndef _Array
#define _Array

#include <utility>

template <class T>
class Array{
public:
    Array(unsigned int _capacity = 10);
    ~Array();
    const int size() const;
    const int capacity() const{
        return m_capacity;
    }

    void add(const T& item);
    void add(T&& item);

    const T& operator[](unsigned int _index) const;
    T& operator[](unsigned int _index);
    void clear();
    void reallocate(unsigned int _newCapacity);

private:
    unsigned int m_size;
    unsigned int m_capacity;
    T* m_data;
};

template <class T>
Array<T>::Array(unsigned int _capacity)
    :m_capacity(_capacity), m_size(0){
    if(m_capacity > 0){
        m_data = (T*)::operator new(m_capacity * sizeof(T));
    }
}

template <class T>
Array<T>::~Array(){
    if(m_capacity > 0){
        clear();
        ::operator delete(m_data);
    }
}

template <class T>
const int Array<T>::size() const{
    return m_size;
}

template <class T>
void Array<T>::add(const T& item){
    if(m_size >= m_capacity){
        int newCapacity = m_capacity * 2;
        if(newCapacity == 0){
            newCapacity += 1;
        }
        reallocate(newCapacity);
    }
    m_data[m_size++] = item;
}

template <class T>
void Array<T>::add(T&& item){
    if(m_size >= m_capacity){
        int newCapacity = m_capacity * 2;
        if(newCapacity == 0){
            newCapacity += 1;
        }
        reallocate(newCapacity);
    }
    m_data[m_size++] = std::move(item);
}

template <class T>
const T& Array<T>::operator[](unsigned int _index) const{
    return m_data[_index];
}

template <class T>
T& Array<T>::operator[](unsigned int _index){
    return m_data[_index];
}

template <class T>
void Array<T>::clear(){ //Todo::Check if T is pointer, in that case, delete memory or make another method for it.
    for(int i = 0; i < m_size; ++i){
        m_data[i].~T();
    }
    m_size = 0;
}

template <class T>
void Array<T>::reallocate(unsigned int _newCapacity){
    T* tmp = (T*)::operator new(_newCapacity * sizeof(T));

    for(int i = 0; i < m_size; ++i){
        tmp[i] = std::move(m_data[i]);
    }

    for(int i = 0; i < m_size; ++i){
        m_data[i].~T();
    }

    if(m_capacity > 0){
        ::operator delete(m_data);    
    }

    m_data = tmp;
    m_capacity  = _newCapacity;
}

#endif