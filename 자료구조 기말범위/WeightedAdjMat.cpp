#include <iostream>
#define N 7
#define INF 100
using namespace std;
typedef int element;

class AdjMat{
    int distance[N];
    int found[N];
    int arr[N][N];
    public:
    void init();
    void Dijkstra(int num);
    void Floyd();
};

void AdjMat::init(){
    int temp[N][N] = {
    {0,7,INF,INF,3,10,INF},
    {7,0,4,10,2,6,INF},
    {INF,4,0,2,INF,INF,INF},
    {INF,10,2,0,11,9,4},
    {3,2,INF,11,0,INF,5},
    {10,6,INF,9,INF,0,INF},
    {INF,INF,INF,4,5,INF,0}};
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            arr[i][j] = temp[i][j];
}

void AdjMat::Dijkstra(int num){
    int least, Cnt = 1, node;
    for(int i=0;i<N;i++){
        found[i] = 0;
        distance[i] = arr[num][i];
    }
    found[num] = 1;
    cout << Cnt << " : ";
    for(int i=0;i<N;i++){
        cout << distance[i] << " ";
    }
    cout << endl;
    cout << "found : ";
    for(int i=0;i<N;i++){
        cout << found[i] << " ";
    }
    cout << endl;
    while(Cnt < N){
        least = INF;
        for(int j=0;j<N;j++){
            if(found[j] == 0 && distance[j] < least){
                least = distance[j];
                node = j;
            }
        }
        found[node] = 1;
        for(int i=0;i<N;i++){
            if(arr[node][i] != INF && 
            distance[node] + arr[node][i] < distance[i])
                distance[i] = distance[node] + arr[node][i];
        }
        Cnt++;
        cout << Cnt << " : ";
        for(int i=0;i<N;i++){
            cout << distance[i] << " ";
        }
        cout << endl;
        cout << "found : ";
        for(int i=0;i<N;i++){
            cout << found[i] << " ";
        }
        cout << endl;
    }
}

void AdjMat::Floyd(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

int main(){
    AdjMat A;
    A.init();
    A.Floyd();
}