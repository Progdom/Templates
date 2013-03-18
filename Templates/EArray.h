//
//  EArray.h
//  Templates
//
//  Created by Isaac Brown on 3/2/13.
//  Copyright (c) 2013 IRBDesign. All rights reserved.
//

#ifndef Templates_EArray_h
#define Templates_EArray_h
#include "Iterate.h"
#include <iostream>
using namespace std;

template <class T>
class EArray {
    friend bool operator<(const EArray<T> &lhs, const EArray<T> &rhs);
    friend bool operator>(const EArray<T> &lhs, const EArray<T> &rhs);
    friend ostream& operator<<(ostream& out, const EArray<T> &source);
    friend istream& operator>>(istream& in, EArray<T> &source);
public:
    EArray(void);
    EArray(int l);
    EArray(const EArray<T> &source);
    EArray& operator=(const EArray<T> & source);
    T& operator[](const int index) const;
    T& operator[](int index);
    ~EArray();
    
    void set_element(int i, const T & newval);
    void erase_element(int i);
    void add_element(int i, const T & newval);
    void push(const T & newval);
    void output();
    
    bool is_empty() const;
    
    typedef Iterate<T> const_iterate;
    
    Iterate<T> begin() const;
    Iterate<T> end() const;
    
private:
    T* array;
    int size;
};

template <class T>
EArray<T>::EArray() : size(0), array(new T[0]) {}

template <class T>
EArray<T>::EArray(int l)
{
    size = l;
    array = new T[size];
}

template <class T>
EArray<T>::EArray(const EArray<T> &source) : size(source.size), array(new T[source.size]) {
    for (unsigned int index = 0;index < size; index++) {
        array[index] = source.array[index];
    }
}

template <class T>
T& EArray<T>::operator[](const int index) const
{
    return array[index];
}

template <class T>
T& EArray<T>::operator[](int index)
{
    return array[index];
}
template<class T>
bool EArray<T>::is_empty() const
{
    return size == 0;
}

template<class T>
EArray<T>& EArray<T>::operator=( const EArray<T> &source)
{
    if (this==&source)
        return *this;
    
    for (unsigned int index = 0; index < source.size; index++)
    {
        push(source.array[index]);
    }
    
    size = source.size;
    return *this;
}

template <class T>
bool operator<(const EArray<T> &lhs, const EArray<T> &rhs)
{
    return lhs < rhs;
}

template <class T>
bool operator>(const EArray<T> &lhs, const EArray<T> &rhs)
{
    return lhs > rhs;
}

template <class T>
EArray<T>::~EArray()
{
    delete [] array;
}

template <class T>
void EArray<T>::set_element(int i, const T & newval)
{
    if (i < size && i >= 0)
    {
        array[i] = newval;
    }
}

template <class T>
void EArray<T>::erase_element(int index)
{
    if (index < size + 1 && index >= 0)
    {
        size -= 1;
        T* newarray = new T[size];
        
        for (int i = 0; i < size +1; i++) {
            if (i < index)
            {
                newarray[i] = array[i];
            }
            else if(i > index)
            {
                newarray[i-1] = array[i];
            }
        }
        
        delete [] array;
        array = newarray;
    }
}

template <class T>
void EArray<T>::add_element(int index, const T & newval)
{
    if (index < size + 1 && index > 0)
    {
        size += 1;
        T* newarray = new T[size];
        
        for (int i = 0; i < size; i++) {
            if (i < index)
            {
                newarray[i] = array[i];
            }
            else if (i == index)
            {
                newarray[i] = newval;
            }
            else
            {
                newarray[i] = array[i-1];
            }
        }
        
        delete [] array;
        array = newarray;
    }
}

template <class T>
void EArray<T>::push(const T & newval)
{
    
    size += 1;
    T* newarray = new T[size];
    
//    if (size > 2) {
//        for (size_t copyIndex = 0; copyIndex < size-2;++copyIndex )
//        {
//            newarray[copyIndex] = array[copyIndex];
//        }
//    }
    
    
    int hole = size -1;
    
    for (;hole  > 0 && newval < array[hole-1]; --hole)
    {
        array[hole] = array[hole - 1];
    }
    
    array[hole] = newval;
    
    //delete [] array;
    //newarray[size-1] = newval;
    //array = newarray;
}


template <class T>
void EArray<T>::output()
{
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

template <class T>
Iterate<T> EArray<T>::begin() const
{
    return const_iterate(array, size);
}

template <class T>
Iterate<T> EArray<T>::end() const
{
    return const_iterate(array + size, 0);
}

#endif
