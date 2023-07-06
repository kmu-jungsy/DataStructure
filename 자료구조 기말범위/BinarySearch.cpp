#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 15
using namespace std;

class Search{
    int data[N];
    public:
    void init();
    void printData();
    void sort();
    int searchNum(int n);
    int rSearchNum(int n, int left, int right);
};

void Search::init(){
    srand(time(NULL));
    for(int i=0;i<N;i++)
        data[i] = rand() % 100;
}

void Search::printData(){
    for(int i=0;i<N;i++)
        cout << data[i] << " ";
    cout << endl;
}

void Search::sort(){
    int i, j, temp;
    for(int i=1;i<N;i++){
        temp = data[i];
        for(j=i-1;j>=0 && data[j] > temp;j--)
            data[j+1] = data[j];
        data[j+1] = temp;
    }
}

int Search::searchNum(int n){
    int mid, left, right;
    left = 0; right = N-1;
    while(left <= right){
        mid = (left + right) / 2;
        if(data[mid] == n)
            return mid;
        else if(data[mid] > n)
            right = mid - 1;
        else    
            left = mid + 1;
    }
    return -1;
}

int Search::rSearchNum(int n, int left, int right){
    int mid = (left + right) / 2;
    if(left <= right){
        if(data[mid] == n)
            return mid;
        else if(data[mid] > n)
            return rSearchNum(n, left, mid - 1);
        else    
            return rSearchNum(n, mid + 1, right);
    }
    return -1;
}

int main(){
    int num;
    Search S;
    S.init();
    S.printData();
    S.sort();
    S.printData();

    cout << "Search Num : ";
    cin >> num;
    cout << "Num pos : " << S.searchNum(num) << endl;

    cout << "Search Num : ";
    cin >> num;
    cout << "Num pos : " << S.rSearchNum(num, 0, N-1) << endl;
}