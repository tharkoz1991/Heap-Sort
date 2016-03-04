//
//  min_heap.cpp
//  Heap Sort
//
//  Created by Tomas Aviles on 3/4/16.
//  Copyright (c) 2016 Tomas Aviles. All rights reserved.
//

#include <stdio.h>
#include "min_heap.h"

using namespace std;

template <typename T>
void MinHeap<T>::swapValues(int pre_position, int post_position) {
    T temp = values.at(post_position);
    values.at(post_position) = values.at(pre_position);
    values.at(pre_position) = temp;
}

template <typename T>
void MinHeap<T>::floatDown() {
    T *left, *right, floater = values[0];
    int iter = 0;
    
    while (iter * 2 + 1 < size()) {
        left = &values.at(iter * 2 + 1);
        if (iter * 2 + 2 < size()) {
            right = &values.at(iter * 2 + 2);
            
            if (*right < *left && *right < floater) {
                swapValues(iter, iter * 2 + 2);
                iter = iter * 2 + 2;
                continue;
            }
            else if (*left < floater) {
                swapValues(iter, iter * 2 + 1);
                iter = iter * 2 + 1;
                continue;
            }
        }
        else if (*left < floater) {
            swapValues(iter, iter * 2 + 1);
            iter = iter * 2 + 1;
            continue;
        }
        break;
    }
}

template <typename T>
void MinHeap<T>::floatTop() {
    int pre_position, floater_pos = size() - 1;
    pre_position = (floater_pos - 1) / 2;
    
    while (pre_position >= 0) {
        if (values.at(pre_position) > values.at(floater_pos)) {
            swapValues(pre_position, floater_pos);
            floater_pos = pre_position;
            pre_position = (pre_position - 1) / 2;
        }else break;
    }
}

template <typename T>
void MinHeap<T>::push(const T &value) {
    values.push_back(value);
    floatTop();
}

template <typename T>
void MinHeap<T>::pop() {
    swapValues(0, size() - 1);
    values.pop_back();
    floatDown();
}

template <typename T>
const T& MinHeap<T>::top() const {
    return values[0];
}

template <typename T>
ostream& operator<<(ostream& os, MinHeap<T>& min_heap) {
    int parent = 0, children = parent * 2 + 1;
    for (auto iter: min_heap.values) {
        os << iter << "–>";
        if (children + 1 < min_heap.size()) {
            os << "[" << min_heap.values.at(children) << ", " << min_heap.values.at(children + 1) << "] ";
        }
        ++parent;
        children = parent * 2 + 1;
    }
    os << endl;
    return os;
}

template <typename T>
const int MinHeap<T>::size() {
    return values.size();
}

template <typename T>
const bool MinHeap<T>::empty() const {
    return values.size() == 0;
}

template <typename T>
typename vector<T>::iterator MinHeap<T>::begin() {
    return values.begin();
}

template <typename T>
typename vector<T>::iterator MinHeap<T>::end() {
    return values.end();
}
