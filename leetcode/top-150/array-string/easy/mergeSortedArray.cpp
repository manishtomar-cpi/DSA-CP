#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> &vec)
{
    cout << "[ ";
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{ //! time : O((m + n) * log(m + n)), because of sorting, we are sorting nums1 which have size m+n
    if (n == 0 && m == 0)
    {
        display(nums1);
        return;
    }
    if (n == 0)
    {
        display(nums1);
        return;
    }
    if (m == 0)
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            nums1[i] = nums2[i];
        }
        display(nums1);
        return;
    }
    int pointer = 0;
    for (int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[pointer++];
    }
    sort(nums1.begin(), nums1.end());
    display(nums1);
}

void merge_optimize(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    //! we dont need edge cases in this because i, j below will work as the edges cases they automatically becomes less then 0 if any one of the array is empty 
    // if (n == 0)
    //     return;
    // if (m == 0)
    // {
    //     for (int i = 0; i < nums2.size(); i++)
    //     {
    //         nums1[i] = nums2[i];
    //     }
    //     return;
    // } 
    int i = m - 1;       // for traversing first array
    int j = n - 1;       // for traversing second array
    int k = (m + n) - 1; // for filling array 1 (merging)

    while (j >= 0 && i >= 0)
    {
        // if last element of first array is largest then last element of
        // second array that should be the largest in both the remaining array
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
            // otherwise, second array's element is largest that should come
            // next
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // if nums1 have elements left -> because in some cases if some elements in the begining of first array is largest then begining elements of the second array in that case i(first array pointer becomes 0 and the first loop get terminated)
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;

    merge(nums1, m, nums2, n);

    return 0;
}