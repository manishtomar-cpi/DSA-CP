#include <iostream>
#include <vector>
using namespace std;

bool isPresent(vector<int> &vec, int element)
{
    //
    if (vec.size() == 0)
    {
        return false;
    }
    else
    {
        if (vec[vec.size() - 1] == element)
        {
            return true;
        }
        else
        {
            vec.pop_back();
            isPresent(vec, element);
        }
    }
}

bool isPresent2(int arr[], int size, int element)
{
    //
    if (size == 0)
    {
        return false;
    }
    if (arr[size - 1] == element)
    {
        return true;
    }
    bool found = isPresent2(arr, size - 1, element);

    if (!found)
    {
        return false;
    }
    if (found)
    {
        return true;
    }
}

int main()
{
    cout << boolalpha;
    // vector<int> vec = {1, 4, 7, 12, 14};
    // cout << isPresent(vec, 18);

    int arr[5] = {1, 4, 6, 8, 12};
    cout << isPresent2(arr, 5, 13);

    return 0;
}