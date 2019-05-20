//
// Created by dingmengdi on 2019/5/17.
//

#ifndef MAXHEAP_HEAP_H
#define MAXHEAP_HEAP_H


#include <iostream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap{

private:
    Item* data;
    int count;
    int capacity;
    void shiftUp(int k){
        while (k > 1 && data[k/2] < data[k]){
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k){
        while (2*k <= count){
            int j = 2*k;

            if (j+1 <= count && data[j+1] > data[j]){
                j = j+1;
            }
            if (data[k] >= data[j]){
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MaxHeap(int capacity){
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    MaxHeap(Item arr[], int n){
        data = new Item[n];
        capacity = n;

        for (int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }
        count = n;

        for (int i = n/2; i > 0; i--) {
            shiftDown(i);
        }
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count==0;
    }

    void insert(Item item){

        assert( count + 1 <= capacity);
        data[count + 1] = item;
        count ++;
        shiftUp(count);
    }

    Item extracMax(){

        assert(count > 0);

        Item ret = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }

public:
    // 以树状打印整个堆结构
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

template <typename Item>
class IndexMaxHeap{

private:
    Item* data;
    int* indexs;
    int* reverse;
    int count;
    int capacity;
    void shiftUp(int k){
        while (k > 1 && data[indexs[k/2]] < data[indexs[k]]){
            swap(indexs[k/2], indexs[k]);
            reverse[indexs[k/2]] = k/2;
            reverse[indexs[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k){
        while (2*k <= count){
            int j = 2*k;

            if (j+1 <= count && data[indexs[j+1]] > data[indexs[j]]){
                j = j+1;
            }
            if (data[indexs[k]] >= data[indexs[j]]){
                break;
            }
            swap(indexs[k], indexs[j]);

            reverse[indexs[k]] = k;
            reverse[indexs[j]] = j;
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity){
        data = new Item[capacity + 1];
        indexs = new int[capacity + 1];
        reverse = new int[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    IndexMaxHeap(Item arr[], int n){
        data = new Item[n];
        capacity = n;

        for (int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }
        count = n;

        for (int i = n/2; i > 0; i--) {
            shiftDown(i);
        }
    }

    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexs;
        delete[] reverse;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count==0;
    }

    void insert(int i, Item item){

        assert( count + 1 <= capacity);
        assert( i+1 >= 1 && i+1 <= capacity);

        i = i + 1;
        data[i] = item;
        indexs[count + 1] = i;
        reverse[i] = count + 1;
        count ++;
        shiftUp(count);
    }

    Item extracMax(){

        assert(count > 0);

        Item ret = data[indexs[1]];
        swap(data[indexs[1]], data[indexs[count]]);

        count--;
        shiftDown(1);
        return ret;
    }

    int extracMaxIndex(){
        assert(count > 0);

        int ret = indexs[1];
        swap(indexs[1], indexs[count]);

        reverse[indexs[1]] = 1;
        reverse[indexs[count]] = 0;

        count--;
        shiftDown(1);
        return ret;
    }

    Item getItem(int i){
        assert(contain(i));
        return data[i+1];
    }


    bool contain(int i){
        assert(i + 1 >= 1 && i+1 <= capacity);

        return reverse[i+1] != 0;
    }

    void change(int i, Item newItem){

        assert(contain(i));
        i = i +1;
        data[i] = newItem;

        //找到indexs[j] = i, j表示data[i]在 堆中的位置
        //之后siftUp（j), 再siftDown(j);
//        for (int j = 0; j <= count ; ++j) {
//            if (indexs[j] = i){
//                shiftDown(j);
//                shiftUp(j);
//                return;
//            }
//        }
        int j = reverse[i];

        shiftUp(j);
        shiftDown(j);
    }

public:
    // 以树状打印整个堆结构
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

#endif //MAXHEAP_HEAP_H
