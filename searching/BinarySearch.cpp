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

void sorting(vector<int> &vec)
{

    //? bubble sort
    bool flag = false;
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - 1; j++)
        {
            if (vec[j + 1] < vec[j])
            {
                swap(vec[j + 1], vec[j]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    display(vec);
}

int binarySearch(vector<int> &vec, int key)
{
    // when we added 2 very big integer they might cross the limit of the INT_MAX and when we add start + end then we might have the chance to get the negative result because of integer overflow, INT_MAX is (2pow31 -1), then we should use mid = start + ((end-start)/2)

    int start = 0;
    int end = vec.size() - 1;
    int mid = start + ((end-start)/2);

    while (start <= end)
    {
        if (vec[mid] == key) // find key
        {
            return mid;
            break;
        }
        if (vec[mid] > key) // means key is on left hand side
        {
            end = mid - 1;
            mid = start + ((end-start)/2);
        }
        else if (vec[mid] < key) // means key is on right hand side
        {
            start = mid + 1;
            mid = start + ((end-start)/2);
        }
    }
    return -1;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 0, 9, 7, 12, 10};

    sorting(vec);
    cout << binarySearch(vec, 1) << endl;

    return 0;
}