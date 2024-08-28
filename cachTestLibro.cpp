#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
#define MAX 1000


int main(){

    double A[MAX][MAX],X[MAX],Y[MAX];
    
    for (int i=0;i< MAX;i++){
        X[i]=i;
        Y[i]=i;
        for (int j=0;j< MAX;j++){
            A[i][j] =i;
        }
    }
    auto start = chrono::high_resolution_clock::now();
    for (int i=0;i< 1000;i++){
        for (int j=0;j< 1000;j++){
            Y[i] +=A[i][j]*X[j];
        }
    }
    auto end= chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end- start;
    cout << "tiempo ejecucion loop 1: " << elapsed.count() << endl;
    for (int i=0;i< MAX;i++){
        X[i]=i;
        Y[i]=i;
        for (int j=0;j< MAX;j++){
            A[i][j] =i;
        }
    }
    auto start1 = chrono::high_resolution_clock::now();
    for (int j=0;j< 1000;j++){
        for (int i=0;i< 1000;i++){
            Y[i] +=A[i][j]*X[j];
        }
    }
    auto end1= chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = end1- start1;
    cout << "tiempo ejecucion loop 2: " << elapsed1.count() << endl;
    
        
    return 0;
}
  
