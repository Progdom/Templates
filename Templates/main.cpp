//
//  main.cpp
//  Templates
//
//  Created by Isaac Brown on 3/2/13.
//  Copyright (c) 2013 IRBDesign. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Main.h"
#include "EArray.h"
#include "StringOrdering.h"
#include "Tools.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    
    if (getBool("Do you want to test using integers?"))
    {
       EArray <int> array;
       getData("Please enter the name of data file: ", array);
       outputData(array);
    } else {
        bool isOrdered = getBool("Do you want to test using the ordered string class\n \t (otherwise, regular strings will be used)? ");
        bool getPerLine = getBool("Do you want to input full lines\n \t (otherwise input will be by whitespace-delimited extraction)?");
        
        if (isOrdered)
        {
            EArray<StringOrdering> array;
            getData("Please enter the name of the data file: ", array, getPerLine);
            outputData(array, getPerLine);
        }
        else {
            EArray<string> array;
            getData("Please enter the name of the data file: ", array, getPerLine);
            outputData(array,getPerLine);
        }
    }
    
   
    return 0;
}



