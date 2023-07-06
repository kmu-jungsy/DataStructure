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
    void quickSort(int left, int right);
    int partition(int left, int right);
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

int Sort::partition(int left, int right){
    int pivot, low, high, temp;
    low = left; high = right + 1;
    pivot = list[left];

    while(1){
        while(1){
            low++;
            if(list[low] >= pivot) break;
        }
        while(1){
            high--;
            if(list[high] <= pivot) break;
        }

        if(low < high){
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }

        if(low > high)
            break;
    }
    temp = list[left];
    list[left] = list[high];
    list[high] = temp;
    return high;
}

void Sort::quickSort(int left, int right){
    if(left < right){
        int q = partition(left, right);
        quickSort(left, q-1);
        quickSort(q+1, right);
    }
}

int main(){
    srand(time(NULL));
    Sort S;
    S.init();
    S.printList();
    S.quickSort(0, N-1);
    S.printList();
}