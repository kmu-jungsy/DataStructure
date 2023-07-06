#include <iostream>
using namespace std;
typedef int element;

class SCL{
    element data;
    SCL* next;
    int size;
    public:
    void init();
    void insertFirst(element e);
    void insert(int pos, element e);
    void insertLast(element e);
    void deleteFirst();
    void deleteNode(int pos);
    void deleteLast();
    void printNode();
};

void SCL::init(){
    next = NULL;
    size = 0;
}

void SCL::insertFirst(element e){
    SCL* node = new SCL;
    node->data = e;
    if(size == 0)
        this->next = node;
    node->next = this->next->next;
    this->next->next = node;
    size++;
}

void SCL::insert(int pos, element e){
    if(pos < 0 || pos > size + 1)
        cout << "Wrong Range" << endl;
    else{
        if(pos == 1)
            insertFirst(e);
        else if(pos == size + 1)
            insertLast(e);
        else{
            SCL* p = next;
            for(int i=1;i<pos;i++)
                p = p->next;
            SCL* node = new SCL;
            node->data = e;
            node->next = p->next;
            p->next = node;
            size++;
        }
    }
}

void SCL::insertLast(element e){
    SCL* p = next;
    SCL* node = new SCL;
    node->data = e;
    node->next = p->next;
    p->next = node;
    this->next = node;
    size++;
}

void SCL::deleteFirst(){
    SCL* p = next;
    p = p->next;
    this->next->next = p->next;
    size--;
}

void SCL::deleteNode(int pos){
    if(pos < 0 || pos > size)
        cout << "Wrong range" << endl;
    else if(pos == 1)
        deleteFirst();
    else if(pos == size)
        deleteLast();
    else{
        SCL* p = next;
        SCL* q = next;
        q = q->next;
        for(int i=1;i<pos;i++){
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        size--;
    }
}

void SCL::deleteLast(){
    SCL* p = next;
    for(int i=1;i<size;i++)
        p = p->next;
    p->next = this->next->next;
    this->next = p;
    size--;
}

void SCL::printNode(){
    SCL*p = this->next->next;
    for(int i=0;i<size;i++){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    SCL head;
    head.init();
    head.insertFirst(30);
    head.insertFirst(20);
    head.insertFirst(10);
    head.printNode();
    head.insert(1, 40);
    head.insert(2, 50);
    head.insert(6, 60);
    head.printNode();
    head.deleteFirst();
    head.deleteNode(2);
    head.deleteLast();
    head.printNode();
}