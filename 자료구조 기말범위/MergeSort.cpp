#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 15
using namespace std;

class Sort{
    int list[N];
    int sorted[N];
    public:
    void init();
    void printList();
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
};

void Sort::init(){
    for(int i=0;i<N;i++)
        list[i] = rand() % 100;
}

void Sort::printList(){
    for(int i=0;i<N;i++)
        cout << list[i] << " ";
    cout << endl;
}

void Sort::merge(int left, int mid, int right){
    int i = left, j = mid+1, k = left;
    while(i <= mid && j <= right){
        if(list[i] < list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i>mid){
        while(j <= right)
            sorted[k++] = list[j++];
    }
    else{
        while(i <= mid)
            sorted[k++] = list[i++];
    }
    for(int l = left;l<=right;l++)
        list[l] = sorted[l];
}

void Sort::mergeSort(int left, int right){
    int mid = (left + right) / 2;
    if(left < right){
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}

int main(){
    srand(time(NULL));

    Sort S;
    S.init();
    S.printList();
    S.mergeSort(0,N-1);
    S.printList();
}