#include <iostream>
#define N 10
typedef int element;
using namespace std;

class DCL{
    element data;
    DCL* left;
    DCL* right;
    int size;
    public:
    void init();
    void insertFirst(element e);
    void insertLast(element e);
    void insert(int pos, element e);
    void deleteNode(int pos);
    void printNode();
};

void DCL::init(){
    size = 0;
    left = this;
    right = this;
}

void DCL::insertFirst(element e){
    DCL* node = new DCL;
    node->data = e;
    if(size == 0){
        node->left = this;
        node->right = this;
        this->right = node;
        this->left = node;
    }
    else{
        node->right = this->right;
        node->left = this;
        this->right->left = node;
        this->right = node;
    }
    size++;
}

void DCL::insertLast(element e){
    if(size == 0)
        insertFirst(e);
    else{
        DCL* p = this;
        for(int i=0;i<size;i++)
            p = p->right;
        DCL* node = new DCL;
        node->data = e;
        node->left = p;
        node->right = this;
        p->right = node;
        this->left = node;
        size++;
    }
}

void DCL::insert(int pos, element e){
    if(pos < 0 || pos > size + 1)
        cout << "Wrong Range" << endl;
    else if(pos == 1)
        insertFirst(e);
    else if(pos == size + 1)
        insertLast(e);
    else{
        DCL* p = this;
        DCL* node = new DCL;
        node->data = e;
        for(int i=0;i<pos-1;i++)
            p = p->right;
        node->left = p;
        node->right = p->right;
        p->right->left = node;
        p->right = node;
        size++;
    }
}

void DCL::deleteNode(int pos){
    if(pos < 0 || pos > size)
        cout << "Wrong Range" << endl;
    DCL* p = this;
    for(int i=0;i<pos;i++)
        p = p->right;
    p->right->left = p->left;
    p->left->right = p->right;
    size--;
}

void DCL::printNode(){
    DCL* p = this;
    for(int i=0;i<size;i++){
        p = p->right;
        cout << p->data << " ";
    }
    cout << endl;
}

int main(){
    DCL* head = new DCL;
    head->init();
    head->insertFirst(10);
    head->insertLast(20);
    head->insert(2,30);
    head->printNode();
    head->deleteNode(1);
    head->printNode();
    head->insert(3,10);
    head->printNode();
    head->deleteNode(3);
    head->printNode();
    head->insert(2,10);
    head->printNode();
    head->deleteNode(2);
    head->printNode();
}