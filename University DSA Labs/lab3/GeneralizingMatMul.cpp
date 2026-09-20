#include <iostream>
using namespace std;
int ra, ca, rb, cb;
int **MatMul(int **A, int **B)
{
    if (ca != rb)
    {
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }

    int **C = new int *[ra];

    for (int i = 0; i < ra; i++)
    {
        C[i] = new int[cb];
    }

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < ca; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            cout << C[i][j]<<" ";
        }
        cout << endl;
    }
    for (int i = 0; i < ra; i++)
    {
        delete C[i];
    }
    delete[] C;
}

int main()
{

    cout << "Enter The Order Of  Matrix A :" << endl;
    cout << "Rows:";
    cin >> ra;
    cout << "Columns:";
    cin >> ca;
    cout << "Enter The Order Of  Matrix B :" << endl;
    cout << "Rows:";
    cin >> rb;
    cout << "Column:";
    cin >> cb;

    int **A = new int *[ra];
    int **B = new int *[rb];
    for (int i = 0; i < ra; i++)
    {
        A[i] = new int[ca];
    }
    for (int i = 0; i < rb; i++)
    {
        B[i] = new int[cb];
    }

    cout << "Enter The Elements for MATRIX A:" << endl;
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            cout << "Element:[" << i << "]" << "[" << j << "]=";
            cin >> A[i][j];
        }
    }
    cout << "Enter The Elements for MATRIX B:" << endl;
    for (int i = 0; i < rb; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            cout << "Element:[" << i << "]" << "[" << j << "]=";
            cin >> B[i][j];
        }
    }
    MatMul(A, B);
    for (int i = 0; i < ra; i++)
    {
        delete A[i];
    }
    delete[] A;
    for (int i = 0; i < rb; i++)
    {
        delete B[i];
    }
    delete[] B;
}