//
// Created by dingmengdi on 2019/5/15.
//

#ifndef QUICKSORT_MERGESORTBU_H
#define QUICKSORT_MERGESORTBU_H

#include "MergeSort.h"

using namespace std;


//自底向上归并排序
template <typename T>
void mergeSortBU(T arr[], int n){

    for (int size = 1; size <= n; size = size*2) {
        for (int i = 0; i + size < n; i = i + size*2) {
            __merge(arr, i, i+size-1, min(i+size*2-1, n-1));
        }
    }
}

#endif //QUICKSORT_MERGESORTBU_H
