#include <iostream>
using namespace std;

int main()
{
    int size = 5;
    int arr[size] = {5, 4, 3, 2, 1};
    int element;
    cout << "ENTER THE ELEMENT YOU WANT TO SEARCH.." << endl;
    cin >> element;
    int i, j;
    int temp;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
                temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int high, low, mid;
    low = 0;
    high = size - 1;
    int flag = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            flag++;
            cout << "ELEMENT FOUND AT INDEX[" << mid << "]:" << arr[mid] << endl;
            break;
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
    if (flag == 0)
    {
        cout << "Element Not Found!" << endl;
    }
    else
    {
        cout << "....Displaying...." << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }

    return 0;
}
