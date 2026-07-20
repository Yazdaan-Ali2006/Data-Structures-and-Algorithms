#include <iostream>
using namespace std;
int binarysearch(int arr[], int size, int element)
{
    int high, low, mid;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
          
            return arr[mid];
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    };
    return -1;
}
int main()
{
    int arr[10] = {2, 7, 11, 16, 22, 54, 122, 297, 358, 800};
    int size = 10;
    int element = 122;
    int result = binarysearch(arr, size, element);
    cout << result << endl;

    return 0;
}