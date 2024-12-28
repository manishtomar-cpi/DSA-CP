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

void IterativeMergeSort(vector<int> &vec)
{
    int pass, low, high, mid, i;
    for (pass = 2; pass <= vec.size(); pass = pass * 2)
    { // this for loop merge 2 2 elements in each pass then 4,4 then 8,8 like this
        for (i = 0; i + pass - 1 < vec.size(); i = i + pass)
        {
            low = i;
            high = i + pass - 1;
            mid = (low + high) / 2;
            merge(vec, low, mid, high);
        }
        if (vec.size() - i > pass / 2)
        {
            low = i;
            high = i + pass - 1;
            mid = (low + high) / 2;
            merge(vec, low, mid, vec.size() - 1);
        }
    }
    if (pass / 2 < vec.size())
    { // means the original vec have odd number of size so that one element left

        merge(vec, 0, pass / 2 - 1, vec.size() - 1); // merge whole list again
    }
}

int main()
{
    vector<int> vec = {4, 3, 6, 1, 8, 9, 10, 11, 18, 14};
    IterativeMergeSort(vec);
    cout << "[ ";
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}