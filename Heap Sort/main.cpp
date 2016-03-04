//
//  main.cpp
//  Heap Sort
//
//  Created by Tomas Aviles on 3/4/16.
//  Copyright (c) 2016 Tomas Aviles. All rights reserved.
//

#include <iostream>
#include <vector>
#include "heap_sort.h"

//ARCHS = "$(ARCHS_STANDARD)";
//CLANG_CXX_LANGUAGE_STANDARD = "gnu++0x";
//CLANG_WARN_CXX0X_EXTENSIONS = YES;
//GCC_C_LANGUAGE_STANDARD = gnu99;

int main(int argc, const char * argv[]) {
    vector<int> myVect;
    vector<int> sortedVect;
    
    for (int i = 0; i < 220; i += 3) {
        myVect.push_back(i);
        if (i % 2 == 0) {
            myVect.push_back(i * 3);
        }
        if (i % 7 == 0) {
            myVect.push_back(i / 3);
            i++;
        }
    }
    
    for (auto iter: myVect){
        cout << myVect.at(iter) << " | ";
    }
    cout << "\n\n";
    
    sortedVect = heapSort(myVect);
    
    for (auto iter: myVect){
        cout << myVect.at(iter) << " | ";
    }
}
