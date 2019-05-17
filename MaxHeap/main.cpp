


int main() {

    MaxHeap<int> maxHeap = MaxHeap<int>(100);
    cout<<maxHeap.size()<<endl;

//    srand(time(NULL));
    for (int i = 0; i < 50; ++i) {
        maxHeap.insert( rand()%100);
    }
//    maxHeap.testPrint();

    while (!maxHeap.isEmpty()){
        cout<<maxHeap.extracMax()<<" ";
    }

    return 0;
}