#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the order of your matrix" << endl;
    cin >> n;
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "[" << i+1 << "][" << j+1 << "]:";
            cin >> A[i][j];
        }
    }
    int size = 3 * n - 2;
    int U[size];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i - j == 1 || i == j ||i - j == -1))
            {
                U[count] = A[i][j];
                count++;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << U[i] << " ";
    }

    return 0;
}