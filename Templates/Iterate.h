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

using namespace std;

template <class T>
class Iterate : public std::iterator<std::forward_iterator_tag, T>
{
public:
    typedef T value_type;
    Iterate(const value_type * start_remaining, size_t first_size_remaining) : remaining(start_remaining), size_remaining(first_size_remaining) {}
    
    const value_type &operator*(void) const { return *remaining; }
    
    Iterate<value_type> operator++(void)
    {
        if (size_remaining > 0)
        {
            ++remaining;
            --size_remaining;
        }
        return *this;
    }
    
    bool operator==(const Iterate<value_type> &compareTo) const
    {
        return remaining == compareTo.remaining;
    }
    
    bool operator!=(const Iterate<value_type> &compareTo) const
    {
        return !(*this == compareTo);
    }
    
    
private:
    size_t size_remaining = 0;
    const value_type *remaining;
};

#endif
