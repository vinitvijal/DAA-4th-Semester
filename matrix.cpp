// Write a program to multiply two matrices using the Strassen’s algorithm for matrix multiplication.

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2));
        vector<vector<int>> B11(n / 2, vector<int>(n / 2));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2));
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];
            }
        }
        vector<vector<int>> P1 = multiply(A11, subtract(B12, B22));
        vector<vector<int>> P2 = multiply(add(A11, A12), B22);
        vector<vector<int>> P3 = multiply(add(A21, A22), B11);
        vector<vector<int>> P4 = multiply(A22, subtract(B21, B11

        ));
        vector<vector<int>> P5 = multiply(add(A11, A22), add(B11, B22));
        vector<vector<int>> P6 = multiply(subtract(A12, A22), add(B21, B22));
        vector<vector<int>> P7 = multiply(subtract(A11, A21), add(B11, B12));
        vector<vector<int>> C11 = subtract(add(add(P5, P4), P2), P6);
        vector<vector<int>> C12 = add(P1, P2);
        vector<vector<int>> C21 = add(P3, P4);
        vector<vector<int>> C22 = subtract(subtract(add(P5, P1), P3), P7);

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + n / 2] = C12[i][j];
                C[i + n / 2][j] = C21[i][j];
                C[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }
    return C;
}

int main()
{
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    vector<vector<int>> C = multiply(A, B);
    for (int i = 0; i < C.size(); i++)
    {
        for (int j = 0; j < C.size(); j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
