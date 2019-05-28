//
// Created by dingmengdi on 2019/5/19.
//

#ifndef MAXHEAP_HEAPSORT_H
#define MAXHEAP_HEAPSORT_H

#include "Heap.h"

template <typename T>
void heapSort1(T arr[], int n){
    MaxHeap<T> maxHeap = MaxHeap<T>(n);

    for (int i = 0; i < n; ++i) {
        maxHeap.insert(arr[i]);
    }

    for (int i = n-1; i >= 0; --i) {
        arr[i] = maxHeap.extracMax();
    }
}

template <typename T>
void heapSort2(T arr[], int n){
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
    for (int i = n-1; i >= 0; --i) {
        arr[i] = maxHeap.extracMax();
    }
}

using namespace std;


template <typename T>
void __shifDown(T arr[],  int n, int k){

    while (2*k +1 < n){
        int j = 2*k;

        if (j+1 < n && arr[j+1] > arr[j]){
            j = j+1;
        }
        if (arr[k] >= arr[j]){
            break;
        }
        swap(arr[k], arr[j]);
        k = j;
    }

}

template <typename T>
void heapSort(T arr[],  int n){

    for (int i = (n-1)/2; i >=0 ; i--) {
        __shifDown(arr, n, i);
    }

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        __shifDown(arr, i, 0);
    }
}

template <typename T>
void IndexheapSort(T arr[],  int n){
    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);

    for (int i = 0; i < n; ++i) {
        indexMaxHeap.insert(i, arr[i]);
    }

    for (int i = n-1; i >= 0; --i) {
        arr[i] = indexMaxHeap.extracMax();
    }
}
#endif //MAXHEAP_HEAPSORT_H
