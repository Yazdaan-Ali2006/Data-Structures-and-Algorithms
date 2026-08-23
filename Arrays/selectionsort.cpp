#include <iostream>
using namespace std;
void selection_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])

                min = j;
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int arr[5] = {12, 2222, 231, 2133, 4};
    selection_sort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}