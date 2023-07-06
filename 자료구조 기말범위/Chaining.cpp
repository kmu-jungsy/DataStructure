#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class HashNode{
    HashNode* data[13];
    int key;
    HashNode* next;
    public:
    void init();
    int h(int n);
    void insert(int key);
    void printHash();
    int findNode(int key);
    int deleteNode(int key);
};

void HashNode::init(){
    for(int i=0;i<13;i++){
        HashNode* node = new HashNode;
        node->key = 0;
        node->next = NULL;
        data[i] = node;
    }
}

int HashNode::h(int n){
    return n % 13;
}

void HashNode::insert(int key){
    int v = h(key);
    HashNode* node = new HashNode;
    HashNode* p = data[v];
    node->key = key;
    node->next = p->next;
    p->next = node;
}

void HashNode::printHash(){
    HashNode* p;
    for(int i=0;i<13;i++){
        cout << i << " : ";
        for(p = data[i]->next;p != NULL; p = p->next)
            cout << p->key << " ";
        cout << endl;
    }
}

int HashNode::findNode(int key){
    int v = h(key);
    int cnt = 0;
    HashNode* p = data[v]->next;
    while(p != NULL){
        if(p->key == key)
            cnt++;
        p = p->next;
    }
    return cnt;
}

int HashNode::deleteNode(int key){
    int v = h(key);
    int cnt = 0;
    HashNode* p = data[v];
    HashNode* q;
    while(p->next != NULL){
        if(p->next->key == key){
            q = p->next;
            p->next = q->next;
            cnt++;
        }
        else
            p = p->next;
    }
    return cnt;
}

int main(){
    int key;
    srand(time(NULL));
    HashNode H;
    H.init();
    for(int i=0;i<20;i++)
        H.insert(rand() % 50 + 1);
    H.printHash();
    cout << "Enter Key to find : ";
    cin >> key;
    cout << "Key count : " << H.findNode(key) << endl;
    cout << "Enter Key to delete: ";
    cin >> key;
    cout << key << " deleted count : " << H.deleteNode(key) << endl;
    H.printHash();
}