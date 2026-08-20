#include <iostream>
using namespace std;

void insertion_sort(int *a, int n)
{
    int j, k;
    for (int i = 1; i <= n - 1; i++)
    {
        k = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > k)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1]=k;
    }
}
int main()
{

    int arr[5] = {12,2222, 231, 2133, 4};
    insertion_sort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}