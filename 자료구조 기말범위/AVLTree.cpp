#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class AVLNode{
    int key;
    AVLNode* left;
    AVLNode* right;
    public:
    AVLNode* insertNode(int key);
    AVLNode* createNode(int key);
    int getBalance();
    int getHeight();
    AVLNode* rotateRight();
    AVLNode* rotateLeft();
    void preOrder();
};

void AVLNode::preOrder(){
    if(this != NULL){
        cout << this->key << " ";
        this->left->preOrder();
        this->right->preOrder();
    }
}

AVLNode* AVLNode::rotateRight(){
    AVLNode* p = this->left;
    this->left = p->right;
    p->right = this;
    return p;
}

AVLNode* AVLNode::rotateLeft(){
    AVLNode* p = this->right;
    this->right = p->left;
    p->left = this;
    return p;
}

int AVLNode::getHeight(){
    int height = 0;
    if(this != NULL){
        height = 1 + max(this->left->getHeight(), this->right->getHeight());
    }
    return height;
}

int AVLNode::getBalance(){
    if(this == NULL)
        return 0;
    return this->left->getHeight() - this->right->getHeight();
}

AVLNode* AVLNode::createNode(int key){
    AVLNode* node = new AVLNode;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

AVLNode* AVLNode::insertNode(int key){
    if(this == NULL)
        return createNode(key);

    if(this->key > key)
        this->left = this->left->insertNode(key);
    else if(this->key < key)
        this->right = this->right->insertNode(key);
    else
        return this;
    
    int balance = getBalance();
    if(balance > 1 && key < this->left->key){
        return rotateRight();
    }
    if(balance > 1 && key > this->left->key){
        this->left = this->left->rotateLeft();
        return rotateRight();
    }
    if(balance < -1 && key > this->right->key)
        return rotateLeft();
    if(balance < -1 && key < this->right->key){
        this->right = this->right->rotateRight();
        return rotateLeft();
    }

    return this;
}

int main(){
    srand(time(NULL));
    AVLNode* root = NULL;
    for(int i=0;i<10;i++){
        root = root->insertNode(rand() % 100 + 1);
        root->preOrder();
        cout << endl;
    }
}