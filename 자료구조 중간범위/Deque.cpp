#include <iostream>
#define N 10
using namespace std;

typedef char element;
class Deque{
    element data[N];
    int front, rear;
    public:
    void init();
    int is_full();
    int is_empty();
    void addRear(element e);
    void addFront(element e);
    element deleteRear();
    element deleteFront();
    element getRear();
    element getFront();
    void printDeque();
};

void Deque::init(){
    front = rear = 0;
}

int Deque::is_full(){
    return (rear + 1) % N == front;
}

int Deque::is_empty(){
    return rear == front;
}

void Deque::addRear(element e){
    if(is_full()){
        cout << "Full";
    }
    else{
        rear = (rear+1)%N;
        data[rear] = e;
    }
}

void Deque::addFront(element e){
    if(is_full())
        cout << "Full" << endl;
    else{
        data[front] = e;
        front = (front - 1 + N) % N;
    }
}

element Deque::deleteRear(){
    if(is_empty())
        cout << "Empty" << endl;
    else{
        element e;
        e = rear;
        rear = (rear - 1 + N) % N;
        return data[e];
    }
}

element Deque::deleteFront(){
    if(is_empty()){
        cout << "Empty" << endl;
    }
    else{
        front = (front + 1) % N;
        return data[front];
    }
}

void Deque::printDeque(){
    int i = front;
    while(i != rear){
        i = (i+1)%N;
        cout << data[i] << " ";
    }
    cout << endl;
}

int main(){
    Deque D;
    D.init();
    D.addRear('A'); D.addRear('B');
    D.addFront('C'); D.addFront('D');
    D.printDeque();

    cout << D.deleteFront() << " is deleted." << endl;
    cout << D.deleteRear() << " is deleted." << endl;
    D.printDeque();
}