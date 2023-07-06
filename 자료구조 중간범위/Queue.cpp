#include <iostream>
#define N 10
using namespace std;

typedef char element;
class Queue{
    element data[N];
    int front, rear;
    public:
    void init();
    int is_full();
    int is_empty();
    void enqueue(element e);
    element dequeue();
    void printQueue();
};

void Queue::init(){
    front = rear = 0;
}

int Queue::is_full(){
    return (rear + 1) % N == front;
}

int Queue::is_empty(){
    return rear == front;
}

void Queue::enqueue(element e){
    if(is_full()){
        cout << "Full";
        return;
    }
    else{
        data[++rear] = e;
    }
}

element Queue::dequeue(){
    if(is_empty()){
        cout << "Empty";
        return 0;
    }
    else{
        return data[++front];
    }
}

void Queue::printQueue(){
    for(int i=front+1;i<=rear;i++)
        cout << data[i] << " ";
    cout << endl;
}

int main(){
    Queue Q;
    Q.init();
    Q.enqueue('A'); Q.enqueue('B'); Q.enqueue('C');
    Q.enqueue('D'); Q.enqueue('E'); Q.enqueue('F');
    Q.printQueue();

    cout << Q.dequeue() << " is deleted." << endl;
    cout << Q.dequeue() << " is deleted." << endl;
    Q.printQueue();
}