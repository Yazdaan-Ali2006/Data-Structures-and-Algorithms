#include <iostream>
using namespace std;
void print_matrix(int **A,int n){
  for (int i = 0; i < n; i++)
    {for (int j = 0; j < n; j++)
        {cout<<A[i][j]<<" ";}
           cout<<endl;}
}
int **MatMul(int **A, int **B, int n)
{
    int **C = new int *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j]=0;
            for(int k=0;k<n;k++){
                C[i][j]=C[i][j]+A[i][k]*B[k][j];
            }

        }
    }
    return C;
}
int main()
{
    int n;
    cout << "Enter The Order Of Square Matrix:" << endl;
    cin >> n;
    int **A = new int *[n];
    int **B = new int *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
    }

    cout << "Enter The Elements for MATRIX A:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Element:[" << i << "]" << "[" << j << "]=";
            cin >> A[i][j];
        }
    }
    cout << "Enter The Elements for MATRIX B:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Element:[" << i << "]" << "[" << j << "]=";
            cin >> B[i][j];
        }
    }
    int **C=MatMul(A,B,n);
    print_matrix(C,n);
       for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}