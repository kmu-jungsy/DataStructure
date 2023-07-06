#include <iostream>
#define N 13
using namespace std;

class Bucket{
    public:
    int key;
    int probeCount;
};

class HashType{
    Bucket* B[N];
    public:
    void init();
    int h(int key);
    int h2(int key);
    void insert(int key);
    int isEmpty(int v);
    int getNextBucketLinear(int v, int i);
    int getNextBucketQuadratic(int v, int i);
    int getNextBucketDouble(int v, int i, int key);
    void printBucket();
    int findElement(int key);
};

void HashType::init(){
    for(int i=0;i<N;i++){
        Bucket* p = new Bucket;
        p->key = 0;
        p->probeCount = 0;
        B[i] = p;
    }
}

int HashType::h(int key){
    return key % N;
}

int HashType::h2(int key){
    return 11 - (key % 11);
}

int HashType::isEmpty(int v){
    return B[v]->key == 0;
}

int HashType::getNextBucketLinear(int v, int i){
    return (v + i) % N;
}

int HashType::getNextBucketQuadratic(int v, int i){
    return (v + i * i) % N;
}

int HashType::getNextBucketDouble(int v, int i, int key){
    return (v + i * h2(key)) % N;
}

void HashType::insert(int key){
    int v = h(key);
    int i = 0, count = 0, b;
    while(i < N){
        count++;
        // b = getNextBucketLinear(v, i);
        // b = getNextBucketQuadratic(v,i);
        b = getNextBucketDouble(v,i,key);
        if(isEmpty(b)){
            B[b]->key = key;
            B[b]->probeCount = count;
            break;
        }
        else{
            i++;
        }
    }
}

int HashType::findElement(int key){
    int v = h(key);
    int i = 0, b;
    while(i<N){
        b = getNextBucketDouble(v,i,key);
        if(B[b]->key == key)
            return b;
        else if(isEmpty(b))
            return -1;
        else
            i++;
    }
    return -1;
}

void HashType::printBucket(){
    cout << "Bucket   Key   Probing" << endl;
    cout << "======================" << endl;
    for(int i=0;i<N;i++){
        cout << i << "         " << B[i]->key << "       " << B[i]->probeCount << endl;
    }
}

int main(){
    int key;
    HashType H;
    H.init();
    H.insert(25); H.insert(13); H.insert(16);
    H.insert(15); H.insert(7); H.insert(28);
    H.insert(31); H.insert(20); H.insert(1);
    H.insert(38);

    H.printBucket();

    cout << "Enter Key : ";
    cin >> key;
    if(H.findElement(key) == -1)
        cout << "No Such Key" << endl;
    else
        cout << "Key Location : " << H.findElement(key) << endl;
}