#include <iostream>
using namespace std;
int arrayinsertion(int arr[], int size, int capacity, int index, int element)
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
        for (i = size; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = element;
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
    int element;
    int index;
    string decision;
    cout << "ENTER THE SIZE OF YOUR ARRAY" << endl;
    cin >> size;
    cout << "ENTER THE ELEMENTS IN YOUR ARRAY" << endl;
    inputarray(arr, size);
    cout << "DO YOU WANT TO INSERT AN ELEMENT IN YOUR ARRAY?(Y/N)" << endl;
    cin >> decision;
    if (decision == "y" || decision == "Y")
    {
        cout << "ENTER THE INDEX AT WHICH YOU WANT TO (INSERT) ELEMENT" << endl;
        cin >> index;
        cout << "ENTER THE ELEMENT" << endl;
        cin >> element;
        if (arrayinsertion(arr, size, capacity, index, element))
        {
            cout << "SUCCESSFULLY INSERTED!" << endl;
            size++;
            cout << "DISPLAYING NEW ARRAY" << endl;
            displayarray(arr, size);
        }
        else
        {
            cout << "INSERTION FAILED!" << endl;
        }
    }
    else
    {
        cout << "EXITING..." << endl;
    }

    return 0;
}