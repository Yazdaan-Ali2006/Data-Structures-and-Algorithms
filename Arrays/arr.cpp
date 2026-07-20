#include <iostream>
using namespace std;
int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < sizeof(arr); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
bool search(int arr[], int size)
{
    int a;
    int flag = 0;
    cout << "ENTER THE NUMBER YOU WANT TO FIND IN ARRAY.." << endl;
    cin >> a;
    for (int i = 0; i < size; i++)
    {
        if (a == arr[i])
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void insert(int arr[],int size){
    int index;
    int num;
    cout<<"ENTER THE NUMBER YOU WANT TO ADD IN ARRAY....."<<endl;
    cin>>num;
    cout<<"ENTER THE INDEX AT WHICH YOU WANT TO ADD...."<<endl;
    cin>>index;
    for(int i=0;i<=index;i++){
       
    }
}
int main()
{
    int max;
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}