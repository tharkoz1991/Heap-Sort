//
//  heap_sort.cpp
//  Heap Sort
//
//  Created by Tomas Aviles on 3/4/16.
//  Copyright (c) 2016 Tomas Aviles. All rights reserved.
//

#include "heap_sort.h"
#include "min_heap.h"

template <typename T>
const vector<T>& heapSort(const vector<T>& array){
    MinHeap<T> min_heap;
    min_heap = array;
    
    vector<T> sorted_vector;
    
    for (auto iter: min_heap){
        sorted_vector.push_back(min_heap.top());
        min_heap.pop();
    }
    
    return sorted_vector;
}