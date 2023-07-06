#include <iostream>
#define N 20
typedef int element;
using namespace std;

class Heap{
    element heap[N];
    int size;
    public:
    void init();
    void insert(element e);
    void deleteHeap();
    void printHeap();
};

void Heap::init(){
    size = 0;
}

void Heap::insert(element e){
    heap[++size] = e;
    int i = size;
    element temp;
    while(i != 1 && heap[i] > heap[i/2]){
        temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i = i / 2;
    }
}

void Heap::deleteHeap(){
    heap[1] = heap[size--];
    int child = 2, parent = 1;
    element temp;
    while(child <= size){
        if(child < size && heap[child] < heap[child + 1])
            child++;
        if(heap[parent] > heap[child])
            break;
        temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        parent = child;
        child *= 2;
    }
}

void Heap::printHeap(){
    for(int i=1;i<=size;i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main(){
    Heap H;
    H.init();
    H.insert(3); H.insert(5);
    H.insert(2); H.insert(7);
    H.insert(6); H.insert(1);
    H.insert(8); H.insert(4);
    H.printHeap();
    H.deleteHeap();
    H.printHeap();
}