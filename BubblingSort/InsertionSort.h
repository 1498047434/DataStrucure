//
// Created by Dingmengdi on 2019/4/24.
//

#ifndef BUBBLINGSORT_INSERTIONSORT_H
#define BUBBLINGSORT_INSERTIONSORT_H


template <typename T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; ++i) {
        //寻找元素arr[i]合适的插入位置
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }else{
                break;
            }
        }
    }
}

template <typename T>
void insertionSort2(T arr[], int n){
    for (int i = 1; i < n; ++i) {
        //寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j;
        for(j=i; j>0; j--){
            if(e < arr[j-1]){
                arr[j] = arr[j-1];
            }else{
                break;
            }
        }
        arr[j] = e;
    }
}

#endif //BUBBLINGSORT_INSERTIONSORT_H
