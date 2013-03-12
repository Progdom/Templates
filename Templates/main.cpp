//
//  main.cpp
//  Templates
//
//  Created by Isaac Brown on 3/2/13.
//  Copyright (c) 2013 IRBDesign. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "EArray.h"
#include "Tools.h"

using namespace std;

void getData(string prompt, EArray<int> &source);
int main(int argc, const char * argv[])
{
    
    EArray <int> array;
    getData("Please enter the name of data file: ", array);
    array.output();
    return 0;
}

void getData(string prompt, EArray<int> &array)
{
    ifstream inStream;
    openIfStream(inStream, prompt);
    while (true) {
        int item;
        inStream >> item;
        if (inStream.fail()) break;
        array.push(item);
    }
}

