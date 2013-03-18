//
//  Main.h
//  Templates
//
//  Created by Isaac Brown on 3/16/13.
//  Copyright (c) 2013 Isaac Brown. All rights reserved.
//

#ifndef Templates_Main_h
#define Templates_Main_h
#include "EArray.h"
#include "Tools.h"
#include <iostream>
#include <fstream>

using namespace std;

//get data from file by each type block, or by each line if fullLine is true
template <class T>
void getData(string prompt, EArray<T> &array, bool fullLine = false)
{
    while (true) {
        ifstream inStream;
        openIfStream(inStream, prompt);
        while (true) {
            T item;
            if (!fullLine) {
                inStream >> item;
            } else {
                //getline(inStream, item);
            }
            if (inStream.fail()) break;
            array.push(item);
        }
        if (!array.is_empty()) break;
        cout << "File is empty, try again.";
    }
}

template <class T>
void outputData(EArray<T> &array, bool byLine = false)
{
    ofstream dataOut;
    openOfStream(dataOut, "Enter name of file for sorted results: ");
    int count;
    
    for (typename EArray<T>::const_iterate each = array.begin(); each != array.end(); ++each)
    {
        dataOut << *each;
        if (byLine) {
            dataOut << endl;
        } else if (++count < 10) {
            dataOut << ' ';
        }
        else {
            dataOut << endl;
            count = 0;
        }
    }
}

#endif
