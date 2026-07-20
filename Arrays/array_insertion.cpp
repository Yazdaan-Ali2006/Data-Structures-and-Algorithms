#include <iostream>
using namespace std;

int main()
{
    int arr1[3] = {0, 1, 2};
    int arr2[4];
    int num;
    int index;
    int i, j;
    j = 0;
    cout << "ENTER THE NUMBER YOU WANT TO PUT IN ARRAY..." << endl;
    cin >> num;
    cout << "ENTER THE INDEX AT WHICH YOU WANT TO ADD NUMBER..." << endl;
    cin >> index;
    for (int i = 0; i < 4; i++)
    {
        if (index == i)
        {
            arr2[i] = num;
        }
        else
        {
            arr2[i] = arr1[j];
            j++;
        }
    }
    for (int x= 0; x < 4; x++)
    {
        cout<<arr2[x]<<endl;
    }

    return 0;
}