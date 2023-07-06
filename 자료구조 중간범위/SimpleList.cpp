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
    void deleteFirst();
    void deleteNode(int pos);
    void printNode();
};

void SCL::init(){
    next = NULL;
    size = 0;
}

void SCL::insertFirst(element e){
    SCL* node = new SCL;
    node->data = e;
    node->next = next;
    next = node;
    size++;
}

void SCL::insert(int pos, element e){
    if(pos < 0 || pos > size)
        cout << "Wrong Range" << endl;
    else{
        if(pos == 1)
            insertFirst(e);
        else{
            SCL* p = next;
            for(int i=1;i<pos-1;i++)
                p = p->next;
            SCL* node = new SCL;
            node->data = e;
            node->next = p->next;
            p->next = node;
            size++;
        }
    }
}

void SCL::deleteFirst(){
    SCL* p = next;
    p = p->next;
    next = p;
    size--;
}

void SCL::deleteNode(int pos){
    if(pos < 0 || pos > size)
        cout << "Wrong range" << endl;
    else if(pos == 1)
        deleteFirst();
    else{
        SCL* p = next;
        SCL* q = next;
        q = q->next;
        for(int i=1;i<pos-1;i++){
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        size--;
    }
}

void SCL::printNode(){
    for(SCL* p = next; p != NULL; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

int main(){
    SCL head;
    head.init();
    head.insertFirst(10);
    head.insertFirst(20);
    head.insertFirst(30);
    head.insert(1, 40);
    head.insert(2, 50);
    head.deleteFirst();
    head.deleteNode(2);
    head.printNode();
}