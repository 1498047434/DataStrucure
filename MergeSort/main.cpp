#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include <algorithm>
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



int main() {

    int n = 500000;
    cout<<"Test for Random Array, size = "<<n<<", random rang [0, "<<n<<"]"<<endl;

    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);
    int *arr3 = SortTestHelper::copyIntArray(arr1,n);
    int *arr4 = SortTestHelper::copyIntArray(arr1,n);

//    SortTestHelper::testSort("Insertion Sort", insertionSort2, arr1,n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2,n);
//    SortTestHelper::testSort("Merge Sort2", mergeSort2, arr3,n);
    SortTestHelper::testSort("Merge Sort2", mergeSort2, arr4,n);

    delete[] arr1;
//    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    cout<<endl;
}