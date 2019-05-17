#include <iostream>
#include "MergeSortBU.h"
#include "SortTestHelper.h"
//#include "InsertionSort.h"
//#include "MergeSort.h"

using namespace std;

template <typename T>
int __partition(T arr[], int l, int r){

    swap(arr[l], arr[rand()%(r-l+1) + l]);

    T v = arr[l];

    int j = l;
    for (int i = l+1; i <= r; i++) {
        if (arr[i] < v ){
            swap(arr[i], arr[j+1]);
            j++;
        }
    }
    swap(arr[j], arr[l]);

    return j;
}


//快速排序内部调用([l...,r])
template <typename T>
void __quickSort(T arr[], int l, int r){

//    if(l >= r) {
//        return;
//    }
    if ( r-l <= 15){
        insertionSort2(arr,l,r);
        return;
    }

    int p = __partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

//快速排序
template <typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}

// [l+1.......i)<=v     (j.....r]>=v
template <typename T>
int __partition2(T arr[], int l, int r){

    swap(arr[l], arr[rand()%(r-l+1) + l]);
    T v = arr[l];

    int i = l+1, j=r;
    while (true){
        while (i <=r && arr[i] < v) i++;
        while (j >= l+1 && arr[j] > v) j--;
        if (j < i){
            break;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    //[l+1.......j]<=v     [i.....r]>=v
    swap(arr[j], arr[l]);
    return j;
}

//快速排序内部调用2([l...,r])
template <typename T>
void __quickSort2(T arr[], int l, int r){

    if ( r-l <= 15){
        insertionSort2(arr,l,r);
        return;
    }

    int p = __partition2(arr,l,r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);
}
//快速排序2
template <typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}


//三路快速排序内部调用2([l...,r])

//arr[l....r] 分为三部分 <v  ==v  >v
//之后再对<v <v 两部分继续进行三路排序
template <typename T>
void __quickSort3Ways(T arr[], int l, int r){

    if ( r-l <= 15){
        insertionSort2(arr,l,r);
        return;
    }

    //partition
    swap(arr[l], arr[rand()%(r-l+1) + l]);
    T v = arr[l];

    int i = l+1;
    int lt = l, gt =r+1;
    while (i <= gt-1) {
        if (arr[i] < v){
            swap(arr[i], arr[lt + 1]);
            i++;
            lt++;
        }else if(arr[i] == v){
            i++;
        }else{  //} if(arr[i] > v){
            swap(arr[i], arr[gt-1]);
            gt--;
        }
    }
    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr,l,lt-1);
    __quickSort3Ways(arr,gt,r);
}

//三路快速排序
template <typename T>
void quickSort3Ways(T arr[], int n){
    srand(time(NULL));
    __quickSort3Ways(arr,0,n-1);
}

int main() {
    int n = 200000;
    cout<<"1  Test for Random Array, size = "<<n<<", random rang [0, "<<n<<"]"<<endl;

    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);
    int *arr3 = SortTestHelper::copyIntArray(arr2,n);
    int *arr0 = SortTestHelper::copyIntArray(arr2,n);
    SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr1,n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2,n);
    SortTestHelper::testSort("Merge Sort2", mergeSort2, arr3,n);
    SortTestHelper::testSort("Quick Sort3Ways", quickSort3Ways, arr0,n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr0;
    cout<<endl;

    int swapTimes = 100;
    cout<<"2   Test for Random Nearly Ordered Array, size = "<<n<<", random rang [0, "<<n<<"]"<<endl;
    int *arr4 = SortTestHelper::generateNearlyOrderArray(n,swapTimes);
    int *arr5 = SortTestHelper::copyIntArray(arr4,n);
    SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr4,n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr5,n);
    delete[] arr4;
    delete[] arr5;
    cout<<endl;

//    int swapTimes = 100;
    cout<<"3   Test for Random Nearly Ordered Array, size = "<<n<<", random rang [0, "<<n<<"]"<<endl;
    int *arr6 = SortTestHelper::generateNearlyOrderArray(n,100);
    int *arr7 = SortTestHelper::copyIntArray(arr6,n);
    SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr6,n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr7,n);
    delete[] arr6;
    delete[] arr7;
    cout<<endl;


    cout<<"4   Test for Random Nearly Ordered Array, size = "<<n<<", random rang [0, "<<n<<"]"<<endl;
    int *arr8 = SortTestHelper::generateRandomArray(n,0,10);
    int *arr9 = SortTestHelper::copyIntArray(arr8,n);
    int *arr10 = SortTestHelper::copyIntArray(arr8,n);
    int *arr11 = SortTestHelper::copyIntArray(arr8,n);
    SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr8,n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr9,n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr10,n);
    SortTestHelper::testSort("Quick Sort3Ways", quickSort3Ways, arr11,n);
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;
    delete[] arr11;
    cout<<endl;
}