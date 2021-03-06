#include <iostream>
#include "binarySearch.h"
#include <vector>
#include "FileOps.h"
#include "SequenceST.h"
#include <ctime>
#include <string>
#include <queue>
#include <cassert>


using namespace std;


template <typename Key, typename Value>
class BST{

private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;

        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;

        }
    };

    Node *root;
    int count;

public:
    BST(){
        root = NULL;
        count = 0;
    }

    ~BST(){
       destory(root);
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return  count == 0;
    }

    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    bool contain(Key key){
        return contain(root ,key);
    }

    Value* search(Key key){
        search(root, key);
    }

    void preOrder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    void levelOrder(){

        queue<Node*> q;
        q.push(root);

        while ( !q.empty() ){
            Node *node = q.front();
            q.pop();

            cout<<node->key<<" : "<< node->value<<endl;

            if (node->left != NULL){
                q.push(node->left);
            }
            if (node->right != NULL){
                q.push(node->right);
            }
        }
    }

    //获取最小值Key
    Key minimum(){
        assert(count != 0);
        Node* node = minimum(root);
        return node->key;
    }

    Key maximum(){
        assert(count != 0);
        Node* node = maximum(root);
        return node->key;
    }

    Node* removeMin(){
        if (root != NULL){
            root = removeMin(root);
        }
    }

    Node* removeMax(){
        if (root !=NULL){
            root = removeMax(root);
        }
    }

    Node* remove(Key key){
        root = remove(root, key);
        return root;
    }

private:

    Node* insert(Node *node, Key key, Value value){

        if (node == NULL){
            count ++;
            return new Node(key, value);
        }

        if (key == node->key){
            node->key = key;
            node->value = value;
        }else if (key < node->key)
            node->left = insert(node->left, key, value);
        else // key > node->key
            node->right =insert(node->right, key, value);
        return node;
    }

    bool contain(Node* node, Key key){

        if (node == NULL)
            return false;

        if(key == node->key)
            return true;
        else if (key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }

    Value* search(Node *node, Key key){
        if (node == NULL)
            return NULL;

        if(key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    void preOrder(Node *node){
        if (node == NULL){
            return;
        }
        cout<<node->key<<" : "<< node->value<<endl;
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node *node){
        if (node == NULL){
            return;
        }
        preOrder(node->left);
        cout<<node->key<<" : "<< node->value<<endl;
        preOrder(node->right);
    }

    void postOrder(Node *node){
        if (node == NULL){
            return;
        }
        preOrder(node->left);
        preOrder(node->right);
        cout<<node->key<<" : "<< node->value<<endl;
    }

    void destory(Node *node){
        if (node != NULL){
            destory(node->left);
            destory(node->right);

            delete node;
            count --;
        }
    }

    Node* minimum(Node* node){
        if (node->left == NULL){
            return node;
        }
        return minimum(node->left);
    }

    Node* maximum(Node* node){
        if (node->right == NULL){
            return node;
        }
        return maximum(node->right);
    }

    Node* removeMin(Node* node){

        if (node->left == NULL){

            Node* rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node){
        if (node->right == NULL){
            Node* leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }

        node->right = removeMax(node);
        return node;
    }

    Node* remove(Node* node, Key key){

        if(node == NULL){
            return NULL;

        } else if(key < node->key){
            node->left = remove(node->left,key);
            return node;

        } else if(key > node->key){
            node->right = remove(node->right,key);
            return node;

        }else{

            if (node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }else if (node->right == NULL){
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            Node* successorNode = new Node(minimum(node->right));

            successorNode->right = removeMin(node->right);
            successorNode->left = node->left;

            delete node;

            return successorNode;
        }
    }
};




int main() {

    BST<int,int> bst = BST<int,int>();
    bst.insert(8,8);
    bst.insert(4,4);
    bst.insert(3,3);
    bst.insert(10,10);
    bst.insert(9,9);

    bst.insert(12,12);
    bst.insert(15,15);
    bst.insert(11,11);


    bst.preOrder();
    cout<<endl;
    bst.levelOrder();
    cout<<endl;
    bst.remove(10);
    bst.preOrder();


//    // 使用圣经作为我们的测试用例
//    string filename = "bible.txt";
//    vector<string> words;
//    if( FileOps::readFile(filename, words) ) {
//
//        cout << "There are totally " << words.size() << " words in " << filename << endl;
//        cout << endl;
//
//
//        // 测试 BST
//        time_t startTime = clock();
//
//        // 统计圣经中所有词的词频
//        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//        // 在这里只做性能测试用
//        BST<string, int> bst = BST<string, int>();
//        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
//            int *res = bst.search(*iter);
//            if (res == NULL)
//                bst.insert(*iter, 1);
//            else
//                (*res)++;
//        }
//
//        // 输出圣经中god一词出现的频率
//        if(bst.contain("god"))
//            cout << "'god' : " << *bst.search("god") << endl;
//        else
//            cout << "No word 'god' in " << filename << endl;
//
//        time_t endTime = clock();
//
//        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
//        cout << endl;
//
//
//        // 测试顺序查找表 SST
//        startTime = clock();
//
//        // 统计圣经中所有词的词频
//        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//        // 在这里只做性能测试用
//        SequenceST<string, int> sst = SequenceST<string, int>();
//        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
//            int *res = sst.search(*iter);
//            if (res == NULL)
//                sst.insert(*iter, 1);
//            else
//                (*res)++;
//        }
//
//        // 输出圣经中god一词出现的频率
//        if(sst.contain("god"))
//            cout << "'god' : " << *sst.search("god") << endl;
//        else
//            cout << "No word 'god' in " << filename << endl;
//
//        endTime = clock();
//
//        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
//    }

    return 0;


}