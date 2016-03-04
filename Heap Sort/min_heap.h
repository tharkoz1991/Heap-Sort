//
//  min_heap.h
//  Foothill CS 2c Min Heap (priority queue)
//
//  Created by Tomas Aviles on 2/22/16.
//  Copyright (c) 2016 Tomas Aviles. All rights reserved.
//

#ifndef __Heap_Sort__min_heap__
#define __Heap_Sort__min_heap__
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MinHeap {
private:
    void floatTop();
    void swapValues(int position, int post_position);
    void floatDown();

public:
    vector<T> values;
    typedef typename vector<T>::iterator iterator;
    
    void push(const T& value);
    void pop();
    const T& top() const;
    
    //operator << overloaded. e.g. cout << myMinHeap;
    const vector<T>& operator=(const vector<T>& array);
    const int size();
    const bool empty() const;
    iterator begin();
    iterator end();
};
#endif /* defined(__Foothill_CS_2c_Min_Heap__priority_queue___min_heap__) */
