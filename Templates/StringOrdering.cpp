//
//  StringOrdering.cpp
//  Templates
//
//  Created by Isaac Brown on 3/16/13.
//  Copyright (c) 2013 Isaac Brown. All rights reserved.
//

#include "StringOrdering.h"

#include <iostream>
using namespace std;

bool operator<( const StringOrdering &left, const StringOrdering &right)
{
    if ( left.value.length() < right.value.length())
    {
        return true;
    }
    else if (left.value.length() == right.value.length() && left.value < right.value)
    {
        return true;
    }
    
    return false;
}

bool operator>=(const StringOrdering &left, const StringOrdering &right)
{
    return !(left < right);
}

bool operator<=(const StringOrdering &left, const StringOrdering &right)
{
    return left.value <= right.value || left.value == right.value;
}

bool operator==(const StringOrdering &left, const StringOrdering &right)
{
    return left.value == right.value;
}

bool operator!=(const StringOrdering &left, const StringOrdering &right)
{
    return !(left.value == right.value);
}

bool operator>(const StringOrdering &left, const StringOrdering &right)
{
    return !(left < right);
}

ostream &operator<<(ostream &stream, const StringOrdering &source)
{
    return stream << source.value;
}

istream &operator>>(istream &stream, StringOrdering &dest)
{
    return stream >> dest.value;
}

istream &getline(istream &stream, StringOrdering &dest)
{
    return getline(stream, dest.value);
}
