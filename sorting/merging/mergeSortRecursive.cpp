#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &vec)
{
    cout << "[ ";
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

void merge(vector<int> &vec, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    vector<int> merged(vec.size());

    while (i <= mid && j <= high)
    {
        if (vec[i] < vec[j])
        {
            merged[k++] = vec[i++];
        }
        else
        {
            merged[k++] = vec[j++];
        }
    }
    while (i <= mid)
    {
        merged[k++] = vec[i++];
    }
    while (j <= high)
    {
        merged[k++] = vec[j++];
    }
    // after merge passing the merged back into original array
    for (int i = low; i <= high; i++)
    {
        vec[i] = merged[i];
    }
    display(vec);
}

void recMergeSort(vector<int> &vec, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        recMergeSort(vec, low, mid);
        recMergeSort(vec, mid + 1, high);
        merge(vec, low, mid, high);
    }
}

int main()
{
    vector<int> vec = {3, 1, 5, 4, 9, 8, 10, 11, 12, 7};

    recMergeSort(vec, 0, 9);

    display(vec);

    return 0;
}