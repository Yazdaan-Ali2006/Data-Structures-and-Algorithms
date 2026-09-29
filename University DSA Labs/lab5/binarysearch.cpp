
#include <iostream>
using namespace std;
int binarySearch(int data[], int size, int item)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (data[i] > data[i + 1])
        {
            cout<<"ARRAY IS UNSORTED"<<endl;
            return 0;
        }
    }
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == item)
        {
            return mid;
        }
        else if (data[mid] < item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int data[size];
    cout << "Enter " << size << " elements in SORTED order:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }
    char choice;
    do
    {
        int item;
        cout << "Enter the element you want to find: ";
        cin >> item;
        int result = binarySearch(data, size, item);
        if (result != -1)
        {
            cout << "FOUND AT INDEX: " << result << endl;
        }
        else
        {
            cout << "ELEMENT NOT FOUND" << endl;
        }
        cout << "Do you want to search another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
