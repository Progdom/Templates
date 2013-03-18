//
//  StringOrdering.h
//  Templates
//
//  Created by Isaac Brown on 3/16/13.
//  Copyright (c) 2013 Isaac Brown. All rights reserved.
//

#ifndef Templates_StringOrdering_h
#define Templates_StringOrdering_h

#include <string>
#include <iostream>

using namespace std;

class StringOrdering {
public:
    StringOrdering() {};
    StringOrdering(const StringOrdering &source) : value(source.value) {};
    StringOrdering(const string &source) : value(source) {};
    
    StringOrdering &operator=( const StringOrdering &source ) { value = source.value; return *this; }
    StringOrdering &operator=(const string &source) { value = source; return *this; }
    
    friend bool operator<( const StringOrdering &left, const StringOrdering &right);
    friend bool operator>( const StringOrdering &left, const StringOrdering &right);
    friend bool operator<=( const StringOrdering &left, const StringOrdering &right);
    friend bool operator>=( const StringOrdering &left, const StringOrdering &right);
    friend bool operator==( const StringOrdering &left, const StringOrdering &right);
    friend bool operator!=( const StringOrdering &left, const StringOrdering &right);
    friend ostream &operator<<(ostream &stream, const StringOrdering &source);
    friend istream &operator>>(istream &stream, StringOrdering &dest);
    friend istream &getline(istream &stream, StringOrdering &dest);
    
private:
    string value;
};


#endif
