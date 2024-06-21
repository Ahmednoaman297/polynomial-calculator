#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long double t;

int main() {
    int row, column;
    float A[100][100];
    float B[100][1];
    float C[100][1];
    float inv[100][100];

    srand(time(0));

    cout << "Enter the number of rows of matrix A: ";
    cin >> row;
    cout << "Enter the number of columns of matrix A: ";
    cin >> column;

    if (row != column) {
        cout << "Matrix A must be square to calculate its inverse." << endl;
        return 1;
    }

    cout << "\nThe random matrix A is:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            A[i][j] = 1 + (rand() % 10);
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nEnter the number of rows of matrix B (should be " << row << "): ";
    int bRow;
    cin >> bRow;

    if (bRow != row) {
        cout << "Matrix B's number of rows must match Matrix A's number of rows." << endl;
        return 1;
    }

    cout << "\nThe random matrix B is:\n";
    for (int i = 0; i < row; i++) {
        B[i][0] = 1 + (rand() % 10);
        cout << B[i][0] << "\t";
    }
    cout << endl;

    // Augmenting A with the identity matrix
    for (int i = 0; i < row; i++) {
        for (int j = row; j < 2 * row; j++) {
            if (i == j - row)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }

    // Performing Gaussian elimination
    for (int i = 0; i < row; i++) {
        t = A[i][i];
        for (int j = i; j < 2 * row; j++)
            A[i][j] /= t;
        for (int j = 0; j < row; j++) {
            if (i != j) {
                t = A[j][i];
                for (int k = 0; k < 2 * row; k++)
                    A[j][k] -= t * A[i][k];
            }
        }
    }

    // Extracting the inverse matrix
    cout << "Inverse of matrix A is:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            inv[i][j] = A[i][j + row];
            cout << inv[i][j] << "\t";
        }
        cout << endl;
    }

    // Multiplying inverse(A) with B to get C
    cout << "\nThe result matrix X (C) is:\n";
    for (int i = 0; i < row; i++) {
        C[i][0] = 0;
        for (int k = 0; k < row; k++) {
            C[i][0] += inv[i][k] * B[k][0];
        }
        cout << C[i][0] << "\t";
    }
    cout << endl;

    return 0;
}
