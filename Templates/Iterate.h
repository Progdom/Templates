//
//  Iterate.h
//  Templates
//
//  Created by Isaac Brown on 3/8/13.
//  Copyright (c) 2013 Isaac Brown. All rights reserved.
//
#include <iterator>

#ifndef Templates_Iterate_h
#define Templates_Iterate_h

template <class T>
class Iterate : public std::iterator<std::iterator_type, T>
{
public:
    typedef T value_type;
    Iterate(const value_type * start_remaining, size_t first_size_remaining) : remaining(start_remaining), size_remaining(first_size_remaining) {}
    const T &operator*(void) const { return *remaining; }
    Iterate<T> operator++(void)
    {
        if (size_remaining > 0)
        {
            ++remaining;
            --size_remaining;
        }
        return *this;
    }
    
    Iterate<T> operator++(int)
    {
        
    }
    
private:
    size_t size_remaining = 0;
    const value_type *remaining;
    
};

#endif
