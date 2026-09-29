#include <iostream>
using namespace std;

bool isSorted(int data[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        if(data[i]>data[i+1])
            return false;
    }
    return true;
}

int binarySearch(int data[], int size, int item)
{
    int low=0;
    int high=size-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(data[mid]==item)
            return mid;
        else if(data[mid]<item)
            low=mid+1;
        else
            high=mid-1;
    }

    return -1;
}

void insertElement(int data[], int &size, int item)
{
    int position=0;
    //reach the position
    while(position<size && data[position]<item)
        position++;
    //shift to right
    for(int i=size;i>position;i--)
        data[i]=data[i-1];
    //insert the element
    data[position]=item;
    size++;
}

int main()
{
    int size;
    int data[100];

    cout<<"Enter the size of array: ";
    cin>>size;

    while(true)
    {
        cout<<"Enter "<<size<<" elements:\n";

        for(int i=0;i<size;i++)
            cin>>data[i];

        if(isSorted(data,size))
            break;

        cout<<"ARRAY IS UNSORTED. Please enter again.\n";
    }

    char choice;

    do
    {
        int item;

        cout<<"\nEnter the element you want to find: ";
        cin>>item;

        int result=binarySearch(data,size,item);

        if(result!=-1)
        {
            cout<<"FOUND AT INDEX: "<<result<<endl;
        }
        else
        {
            cout<<"ELEMENT NOT FOUND"<<endl;

            insertElement(data,size,item);

            cout<<"ELEMENT INSERTED"<<endl;
            cout<<"Updated array: ";

            for(int i=0;i<size;i++)
                cout<<data[i]<<" ";

            cout<<endl;
        }
        cout<<"Do you want to search another item? (y/n): ";
        cin>>choice;} while(choice=='y'||choice=='Y');

    return 0;
}