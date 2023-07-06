#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 3
using namespace std;

void makeMatrix(int A[N][N]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            A[i][j] = rand() % 10;
}

void printMatrix(int A[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void transposeMatrix(int A[N][N], int B[N][N]){
    int temp;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            temp = A[i][j];
            A[i][j] = B[i][j];
            B[i][j] = temp;
        }
}

void multiMatrix(int A[N][N], int B[N][N], int C[N][N]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            C[i][j] = 0;
            for(int k=0;k<N;k++)
                C[i][j] = C[i][j] + A[i][k] + B[k][j];
        }
}

int main(){
    srand((unsigned int)time(NULL));
    int arr1[N][N];
    int arr2[N][N];
    int arr3[N][N];

    makeMatrix(arr1);
    makeMatrix(arr2);
    printMatrix(arr1);
    printMatrix(arr2);
    
    transposeMatrix(arr1, arr2);
    printMatrix(arr1);
    printMatrix(arr2);

    multiMatrix(arr1, arr2, arr3);
    printMatrix(arr1);
    printMatrix(arr2);
    printMatrix(arr3);
}