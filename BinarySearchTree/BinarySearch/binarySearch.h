//
// Created by dingmengdi on 2019/5/20.
//

#ifndef BINARYSEARCH_BINARYSEARCH_H
#define BINARYSEARCH_BINARYSEARCH_H

//二分查找法，在有序数组arr中，查找traget
//如果找到target，返回相应的索引index
//如果没有找到traget，则返回-1
template <typename T>
int binarySearch(T arr[], int n, T traget){

    //在arr[l.....r]之间进行查找traget
    int l = 0, r = n-1;
    while (l <= r){
        int mid = l + (r-l)/2;

        if (traget == arr[mid])
            return mid;
        else if(traget < arr[mid])
            r = mid - 1;
        else // traget > arr[mid]
            l = mid + 1;

    }
    return -1;
}

template <typename T>
int __binarySearchRec(T arr[], int n, T traget, int l, int r){

    int mid = l + (r-l)/2;
    if (traget == arr[mid])
        return mid;
    else if(traget < arr[mid])
        return  __binarySearchRec(arr, n, traget, l, mid-1);

    else // traget > arr[mid]
        return  __binarySearchRec(arr, n, traget, l = mid + 1, r);
}

template <typename T>
int binarySearchRec(T arr[], int n, T traget){

    return  __binarySearchRec(arr, n, traget, 0, n-1);

    return -1;
}

#endif //BINARYSEARCH_BINARYSEARCH_H
