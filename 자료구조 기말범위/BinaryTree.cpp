#include <iostream>
typedef int element;
using namespace std;
#define N 10

class Tree{
    element data;
    Tree* left;
    Tree* right;
    public:
    // Tree(element e, Tree* left, Tree* right);
    void preorder();
    void inorder();
    void postorder();
    void iterOrder();
    void levelOrder();
    Tree* makeNode(element e);
    Tree* insertNode(element e);
    Tree* deleteNode(element e);
    Tree* minValue();
};

class Stack{
    Tree* stack[N];
    int top;
    public:
    void init();
    void push(Tree* node);
    Tree* pop();
};

class Queue{
    Tree* queue[N];
    int front, rear;
    public:
    void init();
    int isEmpty();
    int isFull();
    void enqueue(Tree* node);
    Tree* dequeue();
};

void Queue::init(){
    front = rear = 0;
}

int Queue::isEmpty(){
    return front == rear;
}

int Queue::isFull(){
    return (rear+1)%N == front;
}

void Queue::enqueue(Tree* node){
    if(isFull())
        cout << "Full" << endl;
    else{
        rear = (rear + 1) % N;
        queue[rear] = node;
    }
}

Tree* Queue::dequeue(){
    if(isEmpty()){
        cout << "Empty" << endl;
        return 0;
    }
    else{
        front = (front + 1) % N;
        return queue[front];
    }
}

void Stack::init(){
    top = -1;
}

void Stack::push(Tree* node){
    if(top < N - 1)
        stack[++top] = node;
}

Tree* Stack::pop(){
    Tree* p = NULL;
    if(top >= 0)
        p = stack[top--];
    return p;
}

// Tree::Tree(element e, Tree* left, Tree* right){
//     data = e;
//     this->left = left;
//     this->right = right;
// }

void Tree::preorder(){
    if(this != NULL){
        cout << data << " ";
        this->left->preorder();
        this->right->preorder();
    }
}

void Tree::inorder(){
    if(this != NULL){
        this->left->inorder();
        cout << data << " ";
        this->right->inorder();
    }
}

void Tree::postorder(){
    if(this != NULL){
        this->left->postorder();
        this->right->postorder();
        cout << data << " ";
    }
}

void Tree::iterOrder(){
    Stack stack;
    stack.init();
    Tree* root = this;
    while(1){
        for(;root;root = root->left)
            stack.push(root);
        root = stack.pop();
        if(root == NULL)
            break;
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

void Tree::levelOrder(){
    Queue Q;
    Q.init();
    Tree* root = this;
    Q.enqueue(root);
    while(!Q.isEmpty()){
        root = Q.dequeue();
        cout << root->data << " ";
        if(root->left)
            Q.enqueue(root->left);
        if(root->right)
            Q.enqueue(root->right);
    }
    cout << endl;
}

Tree* Tree::makeNode(element e){
    Tree* node = new Tree;
    node->data = e;
    node->right = NULL;
    node->left = NULL;
    return node;
}

Tree* Tree::insertNode(element e){
    if(this == NULL) return makeNode(e);

    if(e<this->data)
        this->left = this->left->insertNode(e);
    else if(e > this->data)
        this->right = this->right->insertNode(e);
    return this;
}

Tree* Tree::minValue(){
    Tree* p = this;
    while(p->left != NULL)
        p = p->left;
    return p;
}

Tree* Tree::deleteNode(element e){
    if(this == NULL) 
        return this;
    if(e < this->data)
        this->left = this->left->deleteNode(e);
    else if(e > this->data)
        this->right = this->right->deleteNode(e);
    else{
    if(this->left == NULL){
        Tree* temp = this->right;
        free(this);
        return temp;
    }
    else if(this->right == NULL){
        Tree* temp = this->left;
        free(this);
        return temp;
    }
    else{
        Tree* temp = this->right->minValue();
        this->data = temp->data;
        this->right = this->right->deleteNode(temp->data);
    }
    }
    return this;
}

int main(){
    // Tree N4(4, NULL, NULL);
    // Tree N5(5, NULL, NULL);
    // Tree N6(6, NULL, NULL);
    // Tree N7(7, NULL, NULL);
    // Tree N3(3, &N6, &N7);
    // Tree N2(2, &N4, &N5);
    // Tree N1(1, &N2, &N3);
    // N1.iterOrder();
    // N1.levelOrder();

    Tree* root = NULL;
    root = root->insertNode(35); root = root->insertNode(68);
    root = root->insertNode(99); root = root->insertNode(18);
    root = root->insertNode(7); root = root->insertNode(3);
    root = root->insertNode(12); root = root->insertNode(26);
    root = root->insertNode(22); root = root->insertNode(30);
    root->preorder();

    cout << endl;
    root = root->deleteNode(12);
    root->preorder();

}