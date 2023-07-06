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

class ListNode;

class IncidentNode{
    public:
    IncidentNode* next;
    element data;
    void insert(ListNode* node, element e);
};

class ListNode{
    int isVisit;
    element data;
    ListNode* next;
    public:
    IncidentNode* head;
    void init();
    void insert(element e);
    void insertIncident(element e1, element e2);
    ListNode* findNode(element e);
    void printNode();
    void DFS(element e);
    void iDFS(element e);
    void BFS(element e);
};

void IncidentNode::insert(ListNode* node, element e){
    IncidentNode* p = new IncidentNode;
    p->data = e;
    p->next = NULL;

    IncidentNode* q = node->head;
    if(q==NULL)
        node->head = p;
    else{
        while(q->next!=NULL)
            q = q->next;
        q->next = p;
    }
}

void ListNode::init(){
    head = NULL;
    next = NULL;
}

void ListNode::insert(element e){
    ListNode* p = next;
    ListNode* q = new ListNode;
    q->data = e;
    q->next = NULL;
    q->head = NULL;
    q->isVisit = 0;

    if(next==NULL)
        next = q;
    else{
        while(p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

ListNode* ListNode::findNode(element e){
    ListNode* p = next;
    while(p->data != e)
        p = p->next;
    return p;
}

void ListNode::insertIncident(element e1, element e2){
    IncidentNode q;
    ListNode* p = this->findNode(e1);
    q.insert(p, e2);
    p = this->findNode(e2);
    q.insert(p, e1);
}

void ListNode::printNode(){
    ListNode* p = next;
    IncidentNode* q;
    while(p != NULL){
        cout << p->data << " : ";
        q = p->head;
        while(q != NULL){
            cout << q->data << " ";
            q = q->next;
        }
        p = p->next;
        cout << endl;
    }
}

void ListNode::DFS(element e){
    ListNode* p = this->findNode(e);
    IncidentNode* q;
    if(p->isVisit == 0){
        p->isVisit = 1;
        cout << p->data << " ";
    }
    for(q = p->head; q != NULL; q = q->next){
        p = this->findNode(q->data);
        if(p->isVisit == 0)
            DFS(p->data);
    }
}

void ListNode::iDFS(element e){
    ListNode* p = this->findNode(e);
    IncidentNode* q;
    Stack S;
    S.init();
    S.push(p->data);
    while(!S.isEmpty()){
        p = this->findNode(S.pop());
        if(p->isVisit == 0){
            p->isVisit = 1;
            cout << p->data << " ";
        }
        for(q = p->head; q != NULL; q = q->next){
            p = this->findNode(q->data);
            if(p->isVisit == 0){
                S.push(p->data);
                break;
            }
        }
    }
}

void ListNode::BFS(element e){
    ListNode* p = this->findNode(e);
    IncidentNode* q;
    Queue Q;
    Q.init();
    cout << p->data << " ";
    p->isVisit = 1;
    Q.enqueue(p->data);
    while(!Q.isEmpty()){
        p = this->findNode(Q.dequeue());
        for(q = p->head; q != NULL; q = q->next){
            p = this->findNode(q->data);
            if(p->isVisit == 0){
                p->isVisit = 1;
                cout << p->data << " ";
                Q.enqueue(p->data);
            }
        }
    }
}

int main(){
    ListNode p;
    p.init();
    p.insert(0); p.insert(1);
    p.insert(2); p.insert(3);

    p.insertIncident(0,1); p.insertIncident(0,2);
    p.insertIncident(0,3); p.insertIncident(1,2);
    p.insertIncident(2,3);

    p.printNode();
    // cout << "DFS : "; p.DFS(1); cout << endl;
    // cout << "iDFS : "; p.iDFS(1);
    cout << "BFS : "; p.BFS(1);
}