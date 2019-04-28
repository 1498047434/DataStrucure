#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"



//冒泡排序
template <typename T>
void bubblingSort(T arr[], int n){

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if(arr[j] > arr[j+1] ){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//冒泡排序2
template <typename T>
void bubblingSort2(T arr[], int n){
    bool falg = true;
    for (int i = 0; i < n-1 && falg; ++i) {
        falg = false;
        for (int j = 0; j < n-i-1; ++j) {
            if(arr[j] > arr[j+1] ){
                swap(arr[j], arr[j+1]);
                falg = true;
            }
        }
    }
}

//冒泡排序3
template <typename T>
void bubblingSort3(T arr[], int n){

    for (int i = 0; i < n-1; ++i) {
        T e = arr[0];
        int j;
        for (j = 0; j < n-i-1; ++j) {
            if(e > arr[j+1] ){
                arr[j] = arr[j+1];
            } else{
                arr[j] = e;
                e = arr[j+1];
            }
        }
        arr[j] = e;
//        SortTestHelper::printArray(arr,n);
    }
}

int main() {
    using namespace std;
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
//    SortTestHelper::printArray(arr,n);
//    BubblingSort(arr,n);
//    SortTestHelper::printArray(arr,n);

//    int *arr = SortTestHelper::generateNearlyOrderArray(n,5);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);
    int *arr4 = SortTestHelper::copyIntArray(arr,n);
    int *arr5 = SortTestHelper::copyIntArray(arr,n);
    int *arr6 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("insertionSort",insertionSort,arr,n);
    SortTestHelper::testSort("insertionSort2",insertionSort2,arr2,n);
    SortTestHelper::testSort("selectionSort",selectionSort,arr3,n);
    SortTestHelper::testSort("bubblingSort",bubblingSort,arr4,n);
    SortTestHelper::testSort("bubblingSort2",bubblingSort2,arr5,n);
    SortTestHelper::testSort("bubblingSort3",bubblingSort3,arr6,n);

    int n33 = 10;
    int *arr33 = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::printArray(arr33,n33);
    bubblingSort3(arr33,n33);
    SortTestHelper::printArray(arr33,n33);

}