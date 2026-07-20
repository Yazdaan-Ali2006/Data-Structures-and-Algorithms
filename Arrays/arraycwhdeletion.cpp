#include <iostream>
using namespace std;
int arraydeletion(int arr[], int size, int capacity, int index)
{
    int i;
    if (size > capacity)
    {
        return 0;
    }
    else if (index >= capacity)
    {
        return 0;
    }
    else
    {
        for (i = index; i < size; i++)
        {
            arr[i] = arr[i+1];
        }
        return 1;
    }
}
void displayarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void inputarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER ELEMENT NO.(" << i + 1 << ")=";
        cin >> arr[i];
    }
}
int main()

{
    int capacity = 100;
    int arr[capacity];
    int size;

    int index;
    string decision;
    cout << "ENTER THE SIZE OF YOUR ARRAY" << endl;
    cin >> size;
    cout << "ENTER THE ELEMENTS IN YOUR ARRAY" << endl;
    inputarray(arr, size);
    cout << "DO YOU WANT TO (DELETE) AN ELEMENT IN YOUR ARRAY?(Y/N)" << endl;
    cin >> decision;
    if (decision == "y" || decision == "Y")
    {
        cout << "ENTER THE INDEX AT WHICH YOU WANT TO DELETE ELEMENT" << endl;
        cin >> index;
        if (arraydeletion(arr, size, capacity, index))
        {
            cout << "SUCCESSFULLY DELETED!" << endl;
            size--;
            cout << "DISPLAYING NEW ARRAY" << endl;
            displayarray(arr, size);
        }
        else
        {
            cout << "DELETION FAILED!" << endl;
        }
    }
    else
    {
        cout << "EXITING..." << endl;
    }

    return 0;
}