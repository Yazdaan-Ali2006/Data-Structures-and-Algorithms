#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the order of your matrix" << endl;
    cin >> n;

    int size = 3 * n - 2;
    int U[size];

    cout << "Enter the elements of U:" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> U[i];
    }

    int A[n][n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == 1 || i == j || i - j == -1)
            {
                A[i][j] = U[count];
                count++;
            }
            else
            {
                A[i][j] = 0;
            }
        }
    }

    cout << "\nRetrieved Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}