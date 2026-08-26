#include <iostream>
#include <vector>
using namespace std;
// for sorting the merger array
vector<int> merge_sort(vector<int> &a, vector<int> &b, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    ;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
    return a;
}
// for dividing into two
void merge(vector<int> &arr, vector<int> &b, int low, int high)
{

    if (low < high)
    {

        int mid = (low + high) / 2;

        merge(arr, b, low, mid);
        merge(arr, b, mid + 1, high);

        merge_sort(arr, b, low, mid, high);
    }
}
// Final Function Call
void sort_array(vector<int> &nums)
{
    vector<int> b(nums.size());
    merge(nums, b, 0, nums.size() - 1);
}
int main()
{
    vector<int> nums = {8, 31, 5311, 1, 93, 221, 312, 6};

    cout << "Before sorting" << endl;

    for (int x = 0; x < nums.size(); x++)
    {
        cout << nums[x] << endl;
    }

    sort_array(nums);

    cout << "After sorting:" << endl;

    for (int x = 0; x < nums.size(); x++)
    {
        cout << nums[x] << endl;
    }

    return 0;
}