#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot) // If we wish to have array sorted in decreasing order than simply change <= to >=
        {
            idx++;
            swap(arr[j], arr[idx]); // first comparing with arr[0] & arr[0]
        }
    }
    idx++;
    swap(arr[end], arr[idx]); // swapping pivot original place with last element
    return idx;
}

void Quick_Sort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int piv_Idx = partition(arr, st, end);

        Quick_Sort(arr, st, piv_Idx - 1);  // calling for left side of array
        Quick_Sort(arr, piv_Idx + 1, end); // calling for right side of array
    }
}

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    Quick_Sort(arr, 0, arr.size() - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}