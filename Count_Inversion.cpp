#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;

    int i = st, j = mid + 1;
    int inv_count = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }

    return inv_count;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        int left_Inv_Count = mergeSort(arr, st, mid);
        int Right_Inv_Count = mergeSort(arr, mid + 1, end);

        int Inv_count = merge(arr, st, mid, end);

        return left_Inv_Count + Right_Inv_Count + Inv_count;
    }
    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};
    int ans = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversion Count: " << ans << endl;

    return 0;
}