#include <iostream>
#include <chrono>
using namespace std;

void mBloques(int** A, int** B, int** C, int n, int blockSize) {
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int ii = i; ii < i + blockSize && ii < n; ++ii) {
                    for (int jj = j; jj < j + blockSize && jj < n; ++jj) {
                        for (int kk = k; kk < k + blockSize && kk < n; ++kk) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int n = 500;
    int blockSize = 15;

    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
            C[i][j] = 0;
        }
    }

    auto start1 = chrono::high_resolution_clock::now();
    mBloques(A, B, C, n, blockSize);
    auto end1 = chrono::high_resolution_clock::now();

    chrono::duration<double> diff1 = end1 - start1;
    cout << "Tiempo de ejecución (Bloques): " << diff1.count() << " s\n";
    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
