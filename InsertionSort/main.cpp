#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

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


int main() {
    int n = 10000;
//    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr = SortTestHelper::generateNearlyOrderArray(n,5000);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("insertionSort",insertionSort,arr,n);
    SortTestHelper::testSort("insertionSort2",insertionSort2,arr2,n);
    SortTestHelper::testSort("selectionSort",selectionSort,arr3,n);

    delete[] arr;
    delete[] arr2;
    return 0;
}