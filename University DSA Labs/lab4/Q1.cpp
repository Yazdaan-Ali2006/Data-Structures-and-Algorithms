#include <iostream>
using namespace std;

int main()
{
    
    int n;
    cout << "Enter the order of matrix: ";
    cin >> n;
    int A[n][n];
     cout << "\nEnter the elements of the matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
   int size = n * (n + 1) / 2;
    int U[size];
    // Storing
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            U[k] = A[i][j];
            k++;
        }
    }

    cout << "Elements stored in U:"<<endl;

    for (int i = 0; i < size; i++)
    {
        cout << U[i] << " ";
    }

    // Retrieving
    k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            A[i][j] = U[k];
            k++;
        }
    }
      cout << "Retrieved Matrix:"<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }cout << endl;
    }

    return 0;
}