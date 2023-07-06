#include <iostream>
#define N 10
using namespace std;
typedef int element;

class Queue{
    int front, rear;
    element stack[N];
    public:
    void init();
    void enqueue(element e);
    element dequeue();
    int isFull();
    int isEmpty();
};

void Queue::init(){
    front = rear = 0;
}

int Queue::isFull(){
    return (rear + 1)% N == front;
}

int Queue::isEmpty(){
    return front == rear;
}

void Queue::enqueue(element e){
    if(isFull())
        cout << "Full" << endl;
    else{
        rear = (rear + 1) % N;
        stack[rear] = e;
    }
}

element Queue::dequeue(){
    if(isEmpty())
        cout << "Empty" << endl;
    else{
        front = (front + 1) % N;
        return stack[front];
    }
}

class Stack{
    int top;
    element stack[N];
    public:
    void init();
    void push(element e);
    element pop();
    int isFull();
    int isEmpty();
};

void Stack::init(){
    top = -1;
}

int Stack::isFull(){
    return top == N-1;
}

int Stack::isEmpty(){
    return top == -1;
}

void Stack::push(element e){
    if(isFull())
        cout << "Full" << endl;
    else{
        stack[++top] = e;
    }
}

element Stack::pop(){
    if(isEmpty())
        cout << "Empty" << endl;
    else{
        return stack[top--];
    }
}

class AdjMat{
    int size;
    element adjMat[N][N];
    element visited[N];
    public:
    void init();
    void insert(element e1, element e2);
    void printMat(int n);
    void DFS(element e);
    void iDFS(element e);
    void BFS(element e);
};

void AdjMat::init(){
    for(int i=0;i<N;i++){
        visited[i] = 0;
        for(int j=0;j<N;j++)
            adjMat[i][j] = 0;
    }
    size = 0;
}

void AdjMat::insert(element e1, element e2){
    adjMat[e1][e2] = 1;
    adjMat[e2][e1] = 1;
    size++;
}

void AdjMat::printMat(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << adjMat[i][j] << " ";
        cout << endl;
    }
}

void AdjMat::DFS(element e){
    visited[e] = 1;
    cout << e << " ";
    for(int i=0;i<size;i++){
        if(adjMat[e][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void AdjMat::iDFS(element e){
    Stack S;
    S.init();
    S.push(e);
    while(!S.isEmpty()){
        e = S.pop();
        if(visited[e] != 1){
            cout << e << " ";
            visited[e] = 1;
        }
        for(int i=0;i<4;i++){
            if(adjMat[e][i] == 1 && visited[i] == 0)
                S.push(i);
        }
    }
    cout << endl;
}

void AdjMat::BFS(element e){
    Queue Q;
    Q.init();
    visited[e] = 1;
    cout << e << " ";
    Q.enqueue(e);
    while(!Q.isEmpty()){
        e = Q.dequeue();
        for(int i=0;i<4;i++){
             if(adjMat[e][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                cout << i << " ";
                Q.enqueue(i);
             }
        }
    }
}

int main(){
    AdjMat A;
    A.init();
    A.insert(0,1); A.insert(0,2);
    A.insert(0,3); A.insert(1,2);
    A.insert(2,3);

    A.printMat(4);

    A.BFS(0);
}