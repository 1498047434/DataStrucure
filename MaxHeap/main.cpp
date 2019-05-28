#include "Heap.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortTestHelper.h"
#include "HeapSort.h"



int main() {

    int n = 100000;

    //测试一  一般性测试
    cout<<"1  Test for Random Array, size = "<<n<<", random rang [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);
    int *arr3 = SortTestHelper::copyIntArray(arr1,n);
    int *arr4 = SortTestHelper::copyIntArray(arr1,n);
    int *arr5 = SortTestHelper::copyIntArray(arr1,n);
    int *arr6 = SortTestHelper::copyIntArray(arr1,n);
    int *arr7 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("mergeSort", mergeSort, arr1,n);
    SortTestHelper::testSort("quickSort", quickSort, arr2,n);
    SortTestHelper::testSort("quickSort3Ways", quickSort3Ways, arr3,n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr4,n);
    SortTestHelper::testSort("heapSort2", heapSort2, arr5,n);
    SortTestHelper::testSort("heapSort", heapSort, arr6,n);
    SortTestHelper::testSort("IndexheapSort", IndexheapSort, arr7,n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    cout<<endl;


    //2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"2   Test for Random Nearly Ordered Array, size = "<<n<<", random rang [0, "<<n<<"]"<<endl;
    arr1 = SortTestHelper::generateNearlyOrderArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);
    arr6 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("mergeSort", mergeSort, arr1,n);
    SortTestHelper::testSort("quickSort", quickSort, arr2,n);
    SortTestHelper::testSort("quickSort3Ways", quickSort3Ways, arr3,n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr4,n);
    SortTestHelper::testSort("heapSort2", heapSort2, arr5,n);
    SortTestHelper::testSort("heapSort", heapSort, arr6,n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    cout<<endl;



    //测试3 测试含有存在大量相同元素的数组
    cout<<"3   Test for Random Array and almost the same size = "<<n<<", random rang [0, "<<10<<"]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);
    arr6 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("mergeSort", mergeSort, arr1,n);
    SortTestHelper::testSort("quickSort", quickSort, arr2,n);
    SortTestHelper::testSort("quickSort3Ways", quickSort3Ways, arr3,n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr4,n);
    SortTestHelper::testSort("heapSort2", heapSort2, arr5,n);
    SortTestHelper::testSort("heapSort", heapSort, arr6,n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    cout<<endl;



}